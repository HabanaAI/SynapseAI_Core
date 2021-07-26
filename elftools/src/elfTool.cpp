/* SPDX-License-Identifier: MIT
 *
 * Copyright 2017-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "elfTool.h"

std::vector<section *> createAVector(elfio *reader, std::vector<std::string> searchParmater) {
    std::vector<section *> val;
    for (auto runner : searchParmater) {
        val.push_back(reader->sections["." + runner]);
    }
    return val;
}

int protocol(std::vector<section *> sections, char *&head, bool suffixSize) {
    std::string val;
    int sizeVal = 0;
    for (auto runner:sections) {
        if (runner != NULL) {
            val += boost::str(boost::format("%08d") % runner->get_size());
            sizeVal += runner->get_size();
        } else {
            val += boost::str(boost::format("%08d") % 0);
        }
    }
    char *buffer = nullptr;
    if (!suffixSize) {
        buffer =  new char[sizeVal];
    } else{
        buffer =  new char[sizeVal + (sections.size() * 8)];
    }
    head = buffer;
    for (auto runner:sections) {
        if (runner != NULL) {
            memcpy(buffer, runner->get_data(), runner->get_size());
            buffer = buffer + runner->get_size();
        }
    }
    if (suffixSize) {
        memcpy(buffer, val.c_str(), sections.size() * 8);
        sizeVal +=(sections.size() * 8);
    }
    return sizeVal;
}

void help_print() {
    std::string help = "elftool [option] objectfile\n"
                       "option:\n"
                       "-h       print this info\n"
                       "-s       and list of sections. Indication to copy the following sections in the elf\n"
                       "-o       output file\n"
                       "-o -     bash output\n"
                       "-p       insert section size in the end of the object\n"
                       "elftool creates a new object[-o] file contains section in the order of the [-s]\n";
    std::cout << help;
    exit(0);
}

void fileCommandVectors(commandParser &CPVal, int argc, char **argv){
    int i = 1;
    do{
        if (strcmp(argv[i], "-s") == 0) {
            i++;
            while (argv[i][0] != '-' && i < argc) {
                CPVal.cmdSection.push_back(argv[i]);
                i++;
            }
        } else if (strcmp(argv[i], "-h") == 0) {
            help_print();
        } else if (strcmp(argv[i], "-o") == 0) {
            i++;
            CPVal.outputFile = argv[i];
        } else if (strcmp(argv[i], "-p") == 0) {
            CPVal.size = true;
            i++;
        } else{
            i++;
        }
    }while(i<argc-1);
    CPVal.inputFile =argv[argc-1];
}

int main(int argc, char **argv) {
    commandParser cmd;
    fileCommandVectors(cmd, argc, argv);
    std::ofstream outfile;
    if(cmd.outputFile != "-")
      outfile.open(cmd.outputFile);
    // Create elfio reader
    elfio reader;
    if (!reader.load(cmd.inputFile)) {
        std::cout << "Can't find or process ELF file " << argv[1] << std::endl;
        return 2;
    }
    std::vector<section *> sectionVec = createAVector(&reader, cmd.cmdSection);
    char *ptrHead;
    int size;
    try {
        size = protocol(sectionVec, ptrHead, cmd.size);
    }
    catch(...){
        std::cerr << "Bad format";
        exit(-1);
    }
    if(cmd.outputFile != "-") {
      outfile.write(ptrHead, size);
      outfile.close();
    }else {
      std::string val = ptrHead;
      std::cout << ptrHead;
    }
    delete[](ptrHead);
}
