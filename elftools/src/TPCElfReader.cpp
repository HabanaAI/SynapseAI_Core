/* SPDX-License-Identifier: MIT
 *
 * Copyright 2017-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "TPCElfReader.h"

#include <sstream>


TpcElfTools::TpcElfStatus ExtractTpcBinaryFromElfBySection( const void *pElf,
                                                            uint32_t elfSize,
                                                            void *&pTpcBinary,
                                                            uint32_t &tpcBinarySize,
                                                            std::string sectionName)
{
    char *ptr = (char*)pElf;
    std::string strBuffer= "";
    for (int i = 0; i < elfSize; i++)
    {
        strBuffer += *ptr;
        ptr++;
    }

    std::stringstream buffer;
    buffer.str(strBuffer);
    if (elfSize == 0) {
        return TpcElfTools::TpcElfStatus::TPC_ELF_INVALID_ELF_BUFFER;
    }
    elfio reader;
    if (!reader.load(buffer))
    {
        return TpcElfTools::TpcElfStatus::TPC_ELF_UNSUPPORTED;
    }
    section* sectionVec = reader.sections["." + sectionName];
    if (!sectionVec)
    {
        return TpcElfTools::TpcElfStatus::TPC_ELF_SECTION_NOT_FOUND;
    }
    try
    {
        pTpcBinary = (void*)(sectionVec->get_offset() + (char*)pElf);
        tpcBinarySize =  sectionVec->get_size();
    }
    catch (...)
    {
        return TpcElfTools::TpcElfStatus::TPC_ELF_INVALID_ELF_BUFFER;
    }
    if (tpcBinarySize == 0)
    {
        return TpcElfTools::TpcElfStatus::TPC_ELF_INVALID_ELF_BUFFER;
    }
    return TpcElfTools::TpcElfStatus::TPC_ELF_SUCCESS;
}


TpcElfTools::TpcElfStatus TpcElfTools::ExtractTpcBinaryFromElf(const void *pElf,
                                                               uint32_t elfSize,
                                                               void *&pTpcBinary,
                                                               uint32_t &tpcBinarySize) {
    return ExtractTpcBinaryFromElfBySection(pElf, elfSize, pTpcBinary, tpcBinarySize, "text");
}


static bool programHeaderInitialization(int8_t *prtHeader,int32_t sizeHeader){
  if(!prtHeader||sizeHeader==0)
    return false;
  for (int8_t *ptr = prtHeader; ptr < prtHeader + sizeHeader; ptr++)
    *ptr = 0;
  return true;
}


static void copyAndInc(void *dst,void *&ptr, unsigned length){
  memcpy(dst, ptr, length);
  ptr = (uint8_t*)ptr+length;
}

static void backwardCompatibility(void * pPartOfTpcBinary,TpcElfTools::TPCProgramHeader &programHeader){
  char temp = '0';
  char tempValue[5] = "";
  memcpy(tempValue, pPartOfTpcBinary, 4);
  programHeader.version = std::stoi(tempValue);
  pPartOfTpcBinary = (char *)pPartOfTpcBinary + 4;
  temp = *(char*) pPartOfTpcBinary;
  programHeader.specialFunctionUsed = temp == '1'? true:false;
  pPartOfTpcBinary = (char *)pPartOfTpcBinary + sizeof(programHeader.specialFunctionUsed);
  temp = *(char*) pPartOfTpcBinary;
  programHeader.printfUsed = temp == '1'? true:false;
  pPartOfTpcBinary = (char *)pPartOfTpcBinary + sizeof(programHeader.printfUsed);
  temp = *(char*) pPartOfTpcBinary;
  programHeader.lockUnlock = temp == '1'? true:false;
  pPartOfTpcBinary = (char *)pPartOfTpcBinary + sizeof(programHeader.lockUnlock);
  if (programHeader.version > 5)
  {
    temp = *(char *)pPartOfTpcBinary;
    programHeader.mmioUse = temp == '1' ? true : false;
    pPartOfTpcBinary = (char *)pPartOfTpcBinary + sizeof(programHeader.mmioUse);
    memcpy(tempValue, pPartOfTpcBinary, 2);
    tempValue[2]='\0';
    programHeader.march = static_cast<TpcElfTools::TPCArch>(std::stoi(tempValue));
    pPartOfTpcBinary = (char *)pPartOfTpcBinary + sizeof(programHeader.march);
    pPartOfTpcBinary = (char *)pPartOfTpcBinary + sizeof(programHeader.reserved_temp); // To align to compiler.
  }
  int32_t typeSize = sizeof(char); //shall be one byte TODO: replace once scalarLoad field is integrated.
  for (int i = 0; i < gcapi::MAX_TENSOR_NR; i++)
  {
    memcpy(&temp, pPartOfTpcBinary, typeSize);
    pPartOfTpcBinary = (char *)pPartOfTpcBinary + typeSize;
    programHeader.scalarLoad |= (temp == '1') ? (1 << i) : 0;
  }
  for (int i = 0; i < gcapi::MAX_TENSOR_NR; i++)
  {
    memcpy(&temp, pPartOfTpcBinary, typeSize);
    pPartOfTpcBinary = (char *)pPartOfTpcBinary + typeSize;
    programHeader.rmwStore |= (temp == '1') ? (1 << i) : 0;
  }
  memcpy(&programHeader.reserved, pPartOfTpcBinary, sizeof(programHeader.reserved));
}

TpcElfTools::TpcElfStatus TpcElfTools::ExtractTpcProgramHeaderFromElf(const void *pElf,
                                                                      uint32_t elfSize,
                                                                      TpcElfTools::TPCProgramHeader &programHeader)
{
    void *pTpcBinary = nullptr;
    uint32_t tpcBinarySize = 0;
    programHeaderInitialization((int8_t *)&programHeader,sizeof(TpcElfTools::TPCProgramHeader));
    TpcElfTools::TpcElfStatus status = ExtractTpcBinaryFromElfBySection(pElf, elfSize, pTpcBinary, tpcBinarySize, "tpc_metadata");
    if (status != TpcElfTools::TpcElfStatus::TPC_ELF_SUCCESS)
    {
        // recheck
        status = ExtractTpcBinaryFromElfBySection(pElf, elfSize, pTpcBinary, tpcBinarySize, "TPC_METADATA");
        if (status != TpcElfTools::TpcElfStatus::TPC_ELF_SUCCESS)
          return status;
    }
    void * pPartOfTpcBinary = pTpcBinary;
    memcpy(&(programHeader.version), pPartOfTpcBinary, 4);
    if(programHeader.version<=9)
      copyAndInc(&(programHeader), pPartOfTpcBinary, sizeof(programHeader));
    else
      backwardCompatibility(pPartOfTpcBinary,programHeader);
    return status;
}

TpcElfTools::TpcElfStatus
TpcElfTools::GetTpcKernelISAName(gcapi::HabanaKernelInstantiation_t *instance,
                                 char *kernelISA, unsigned *nameSize) {
  void *pTpcBinary = nullptr;
  uint32_t tpcBinarySize = 0;
  TpcElfTools::TpcElfStatus status =
      ExtractTpcBinaryFromElfBySection(instance->kernelElf, instance->elfSize,
                                       pTpcBinary, tpcBinarySize, "KernelInfo");
  if (status != TpcElfTools::TpcElfStatus::TPC_ELF_SUCCESS) {
    return status;
  }

  if (tpcBinarySize == 0)
    return TpcElfTools::TpcElfStatus::TPC_ELF_INVALID_ELF_BUFFER;
  char *ptr = (char *)pTpcBinary;

  if (kernelISA != nullptr)
  {
    strtok(ptr, "[");
    strcpy(kernelISA, strtok(NULL, "]"));
    strcat(kernelISA, "\0");
  }
  else if (nameSize != nullptr)
  {
    *nameSize = (int)(strchr((const char *)pTpcBinary, ']')-strchr((const char *)pTpcBinary, '['));
  }
  else {
    return TpcElfStatus::TPC_ELF_INVALID_BUFFER;
  }

  return TpcElfStatus::TPC_ELF_SUCCESS;
}
