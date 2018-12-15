//
// Created by Amelia Chady on 11/30/2018.
//

#ifndef INC_220GROUPPROJECT_UTIL_H
#define INC_220GROUPPROJECT_UTIL_H

#include<string>
#include "List.h"
/**
 * Removes whitespace, \r, and \n from the ends of the inputted string
 * @param stringToTrim
 * @return the trimmed string
 */
std::string trim(std::string stringToTrim);
/**
 * Splits the string by delimiter
 * @param stringToSplit the string to split
 * @param delim the delimiter to split by
 * @return a list of the split pieces
 */
List<std::string>* split(std::string stringToSplit, std::string delim);

#endif //INC_220GROUPPROJECT_UTIL_H
