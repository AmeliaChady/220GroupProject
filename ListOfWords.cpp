//
// Created by Josh Hayden on 12/2/18.
//
//
#include "ListOfWords.h"
#include <fstream>
#include <iostream>
#include "Util.h"
#include <string>


/***
 * Default Constructor
 */
ListOfWords::ListOfWords(){
    wordBank = nullptr;
    fileName = "";
}
/***
 * Destructor
 */
ListOfWords::~ListOfWords() {
    delete wordBank;
    wordBank = nullptr;
}

/***
 * Constructor
 * @param fileNameIn takes the name of the csv file that the wordBank is drawn from
 */
ListOfWords::ListOfWords(std::string fileNameIn){
    std::fstream listInput(fileNameIn);
    this->wordBank = new ArrayList<std::pair<std::string, std::string>>(2);
    std::pair<std::string, std::string> inputPair;
    std::string inputStr;
    if (!listInput){
        //std::cout<<"File is not in directory"<<std::endl;
        throw std::invalid_argument("File does not exist!");
    }

    while (getline(listInput, inputStr)){
        List<std::string>* englishAndPhonetic = split(inputStr, ",");
        inputPair = {englishAndPhonetic->getValueAt(0), englishAndPhonetic->getValueAt(1)};
        this->wordBank->insertAtEnd(inputPair);

    }
    this->fileName = fileNameIn;



}
/***
 * gives a random pair from the wordBank
 * @return a  std::pair, consisting of an english word first and its phonetic translation second, drawn randomly from the wordBank
 */
std::pair<std::string, std::string> ListOfWords::giveRandWord(){
    int sizeOfList = wordBank->itemCount();
    int index = rand() % sizeOfList;
    std::pair<std::string, std::string> returnedPair;
    returnedPair = wordBank->getValueAt(index);
    return returnedPair;
} //outputs a random word in the wordBank

/***
 * for returning a specific pair
 * @param index int that is a given index in the wordBank arrayList
 * @return the pair at the entered index
 */
std::pair<std::string, std::string> ListOfWords::giveWordAtIndex(int index) {
    std::pair<std::string, std::string> returnedPair;
    returnedPair = wordBank->getValueAt(index);
    return returnedPair;
}


