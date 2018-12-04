//
// Created by Josh Hayden on 11/29/18.
//

#ifndef INC_220GROUPPROJECT_LISTOFWORDS_H
#define INC_220GROUPPROJECT_LISTOFWORDS_H
#include <cstdlib>
#include "ArrayList.h"

class ListOfWords{
private:
    ArrayList<std::pair<std::string,std::string>>* wordBank; //array of pairs, each with the first entry being the english word and second being phonetic
    std::string fileName; //name of the csv file that the list comes from
public:
    ListOfWords();
    ListOfWords(std::string fileNameIn); //generates a list from the fileName
    std::pair<std::string, std::string> giveRandWord(); //outputs a random word in the wordBank
    std::pair<std::string, std::string> giveWordAtIndex(int index);

};
#endif //INC_220GROUPPROJECT_LISTOFWORDS_H
