//
// Created by Amelia Chady on 11/30/2018.
//

#ifndef INC_220GROUPPROJECT_UTIL_H
#define INC_220GROUPPROJECT_UTIL_H

#include<string>
#include "List.h"

std::string trim(std::string stringToTrim);
List<std::string>* split(std::string stringToSplit, std::string delim);
std::string AtU(std::string ascii);
std::string ASCIItoUNICODE(std::string ascii);

#endif //INC_220GROUPPROJECT_UTIL_H
