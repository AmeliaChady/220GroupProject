//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_LISTOFWORDSCHANGER_H
#define INC_220GROUPPROJECT_LISTOFWORDSCHANGER_H


#include <string>

class ListOfWordsChanger {
public:
    //default constructor
    ListOfWordsChanger();
    //constructor for specific file
    ListOfWordsChanger(std::string fileName);
    //adds directly into .csv file
    void addWord(std::string word, std::string phoneticSpelling);
    //removes from file
    void removeWord(std::string word);
};


#endif //INC_220GROUPPROJECT_LISTOFWORDSCHANGER_H
