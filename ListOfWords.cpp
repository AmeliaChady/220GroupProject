//
// Created by Josh Hayden on 12/2/18.
//
#include "ListOfWords.h"
#include <fstream>
#include <iostream>
#include "Util.h"
#include <string>



ListOfWords::ListOfWords(){
    wordBank = nullptr;
    fileName = "";
}
ListOfWords::ListOfWords(std::string fileNameIn){
    std::ifstream listInput(fileNameIn);
    wordBank = new ArrayList<std::pair<std::string, std::string>>();
    std::string inputStr;
    std::pair<std::string, std::string> inputPair;
    while (listInput){
        std::string inputStr;
        getline(listInput, inputStr);
        List<std::string>* englishAndPhonetic = split(inputStr, ",");
        inputPair = std::make_pair(englishAndPhonetic->getValueAt(0), englishAndPhonetic->getValueAt(1));
        wordBank->insertAtEnd(inputPair);

    }
    fileName = fileNameIn;

} //generates a list from the fileName
std::pair<std::string, std::string> ListOfWords::giveRandWord(){
    int sizeOfList = wordBank->itemCount();
    int index = rand() % sizeOfList;
    std::pair<std::string, std::string> returnedPair;
    returnedPair = wordBank->getValueAt(index);
    return returnedPair;
} //outputs a random word in the wordBank


