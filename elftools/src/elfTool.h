/* SPDX-License-Identifier: MIT
 *
 * Copyright 2017-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#ifndef TPC_KERNELS_ELFTOOL_H
#define TPC_KERNELS_ELFTOOL_H
#include <iostream>
#include <boost/format.hpp>
#include "elfio/elfio.hpp"

using namespace ELFIO;
/*!
 * @brief createAvector create a vector of sections
 * @param reader is the object file
 * @param searchParmater a vector of section names
 * @return vector of sections.
 */
std::vector<section *> createAVector(elfio *reader, std::vector<std::string> searchParmater);

/*!
 * @brief create a protocol by the input of the program. In overall the protocol creates a copy of sections according
 * to the input -s. The order witch the element enter to the input reflect the order of the protocol. The protocol is
 * set by the following convenation
 * [data section0][data section1]...[data sectionN][size section1][size section2]...[size sectionN]
 * @param sections vector of sections elements.
 * @param head of the destination.
 * @return size of the new object
 */
int protocol(std::vector<section *> sections, char *&head, bool suffixSize = true);

/*!
 * @breif help prints the help string
 */
void help_print();

typedef struct commandParser {
    std::vector<std::string> cmdSection; /*<! Contain the section to copy */
    std::string inputFile;               /*<! input file */
    std::string outputFile;              /*<* output file */
    bool size = false;
} commandParser;

/*!
 * @brief The fill the command struct.
 * @param CPVal The struct to be fill.
 * @param argc number of arguments.
 * @param argv a list of arguments.
 */
void fileCommandVectors(commandParser &CPVal, int argc, char **argv);

#endif //TPC_KERNELS_ELFTOOL_H
