//
// Created by Timothy Marotta on 11/30/18.
//

#include "ListOfWordsChanger.h"

ListOfWordsChanger::ListOfWordsChanger() {}

ListOfWordsChanger::ListOfWordsChanger(std::string fileName){
    this->file = fileName;
}

void ListOfWordsChanger::addWord(std::string word, std::string phoneticSpelling) {
    outFile.open(file, std::ios::app);
    outFile << word << "," << phoneticSpelling <<std::endl;
}

void ListOfWordsChanger::removeWord(std::string word) {
    inFile.open(file);
    //TODO find line to delete and delete
}

void ListOfWordsChanger::save(std::string filename) {
    inFile.close();
    outFile.close();
}