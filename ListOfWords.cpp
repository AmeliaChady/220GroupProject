//
// Created by Josh Hayden on 12/2/18.
//
#include "ListOfWords.h"
#include <fstream>
#include <iostream>
#include "Util.h"



ListOfWords::ListOfWords(){

}
ListOfWords::ListOfWords(std::string fileNameIn){
    ifstream listInput = new ifstream(fileName);
    ArrayList<std::pair<std::string, std::string>>* lineList = new ArrayList<std::pair<std::string, std::string>>();
    std::string inputStr;
    std::pair<std::string, std::string> inputPair;
    while (ifstream){
        std::string inputStr;
        listInput >> inputStr;
        List<std::string>* englishAndPhonetic = split(inputStr, ",");
        inputPair<0> = englishAndPhonetic->getValueAt(0);
        inputPair<1> = englishAndPhonetic->getValueAt(1);
        lineList->insertAtEnd(inputPair);
    }
    fileName = fileNameIn;

} //generates a list from the fileName
std::pair<std::string, std::string> ListOfWords::giveRandWord(){

} //outputs a random word in the wordBank


