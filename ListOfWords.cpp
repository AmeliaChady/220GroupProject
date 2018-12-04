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
    std::fstream listInput(fileNameIn);
    this->wordBank = new ArrayList<std::pair<std::string, std::string>>(2);
    std::pair<std::string, std::string> inputPair;
    std::string inputStr;
    if (!listInput){
        std::cout<<"File is not in directory"<<std::endl;
        exit(1);
    }

    while (getline(listInput, inputStr)){
        List<std::string>* englishAndPhonetic = split(inputStr, ",");
        inputPair = {englishAndPhonetic->getValueAt(0), englishAndPhonetic->getValueAt(1)};
        this->wordBank->insertAtEnd(inputPair);

    }
    this->fileName = fileNameIn;



} //generates a list from the fileName
std::pair<std::string, std::string> ListOfWords::giveRandWord(){
    int sizeOfList = wordBank->itemCount();
    int index = rand() % sizeOfList;
    std::pair<std::string, std::string> returnedPair;
    returnedPair = wordBank->getValueAt(index);
    return returnedPair;
} //outputs a random word in the wordBank

std::pair<std::string, std::string> ListOfWords::giveWordAtIndex(int index) {
    std::pair<std::string, std::string> returnedPair;
    returnedPair = wordBank->getValueAt(index);
    return returnedPair;
}


