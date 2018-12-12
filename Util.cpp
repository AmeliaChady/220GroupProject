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
    while(stringToTrim.length()!=0 &&
          (stringToTrim.find(' ',0)==0
          ||stringToTrim.find('\r')==0
          ||stringToTrim.find('\n')==0)){
        stringToTrim = stringToTrim.substr(1);
    }
    while(stringToTrim.length()!=0 &&
          (stringToTrim.find_last_of(' ')==stringToTrim.length()-1
          ||stringToTrim.find('\r')==stringToTrim.length()-1
          ||stringToTrim.find('\n')==stringToTrim.length()-1)){
        stringToTrim = stringToTrim.substr(0, stringToTrim.length()-1);
    }
    return stringToTrim;
}


void split_ErrorCheck(const std::string& stringToSplit, const std::string& delim){
    if(stringToSplit.length()==0){
        throw std::invalid_argument("stringToSplit is empty");
    }
    if(delim.length()==0){
        throw std::invalid_argument("delim is empty");
    }
}
List<std::string>* split(std::string stringToSplit, std::string delim){
    split_ErrorCheck(stringToSplit, delim);

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

    if(splitted->itemCount()==0){
        std::invalid_argument("stringToSplit only has delimiters");
    }


     return splitted;
}

std::string AtU(std::string ascii){
    return ASCIItoUNICODE(ascii);
}

std::string ASCIItoUNICODE(std::string ascii){
    std::string[] letters = {"p", "b", "m", ".w", "f", "v", "T", "D", "t", "d", "s", "z", "n",
                            "l", ".S", ".Z", "S", "Z", "R", "j", "k", "g", "N", "h",
                            "i", "I", "e", "E", "&", ")", "u", "U", "o", "^", "O", "A"};
    std::string[] unicode = {"p", "b", "m", "w", "f", "v", "θ", "ð", "t", "d", "s", "z", "n",
                            "l", "ʧ", "ʤ", "ʃ", "ʒ", "r", "j", "k", "g", "ŋ", "h",
                            "i", "ɪ", "e", "ɛ", "æ", "ə", "u", "ʊ", "o", "ʌ", "ɔ", "ɑ"};
    int arraySize = 36;

    for(int i = 0; i<arraySize; i++){
        if(ascii == letters[i]){
            return unicode[i];
        }
    }
    throw std::invalid_argument("Conversion doesn't exist");
}