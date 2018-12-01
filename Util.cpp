//
// Created by Amelia Chady on 11/30/2018.
//

#include <string>
#include "List.h"
#include "LinkedList.h"
#include "Util.h"

std::string trim(std::string stringToTrim){
    if(stringToTrim.length()==0){
        return stringToTrim;
    }
    while(stringToTrim.find(' ',0)==0){
        stringToTrim = stringToTrim.substr(1);
    }
    while(stringToTrim.find_last_of(' ')==stringToTrim.length()-1
        ||stringToTrim.find('\r')==stringToTrim.length()-1
        ||stringToTrim.find('\n')==stringToTrim.length()-1){
        stringToTrim = stringToTrim.substr(0, stringToTrim.length()-1);
    }
    return stringToTrim;
}

List<std::string>* split(std::string stringToSplit, std::string delim){
    trim(stringToSplit);
    List<std::string>* splitted = new LinkedList<std::string>();
    int delimIndex = stringToSplit.find(delim);
    while(delimIndex > -1){
        if(delimIndex!=0) {
            splitted->insertAtEnd(stringToSplit.substr(0, delimIndex));
        }
        stringToSplit = stringToSplit.substr(delimIndex+1);
        delimIndex = stringToSplit.find(delim);
    }
    if(stringToSplit.length()!=0){
        splitted->insertAtEnd(stringToSplit);
    }


     return splitted;
}