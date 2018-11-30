//
// Created by Alex Chady on 11/30/2018.
//

#include <string>
#include "List.h"
#include "LinkedList.h"
#include "Util.h"

std::string trim(std::string stringToTrim){
    while(stringToTrim.find(' ',0)==0){
        stringToTrim = stringToTrim.substr(1);
    }
    while(stringToTrim.find_last_of(' ')){
        stringToTrim = stringToTrim.substr(0, stringToTrim.length()-1);
    }
    return stringToTrim;
}

List<std::string>* split(std::string stringToSplit, std::string delim){
    List<std::string>* splitted = new LinkedList<std::string>();
    int delimIndex = stringToSplit.find(delim);
    while(delimIndex > -1){
        if(delimIndex!=0) {
            splitted->insertAtEnd(stringToSplit.substr(0, delimIndex));
        }
        stringToSplit = stringToSplit.substr(delimIndex+1);
        delimIndex = stringToSplit.find(delim);
    }
}