//
// Created by Josh Hayden on 11/29/18.
//

#ifndef INC_220GROUPPROJECT_LISTOFWORDS_H
#define INC_220GROUPPROJECT_LISTOFWORDS_H
#include <cstdlib>

class ListOfWords{
private:
    std::pair<std::string,std::string>* wordBank; //array of pairs, each with the first entry being the english word and second being phonetic
    std::string fileName; //name of the csv file that the list comes from
public:
    ListOfWords(std::string fileName); //generates a list from the fileName
    std::pair<std::string, std::string> giveRandWord(); //outputs a random word in the wordBank
    std::pair<std::string, std::string> giveAskedWord(std::string englishWord);//takes the english version of the word, if it's
    //in the wordBank, otherwise throws an exception
};
#endif //INC_220GROUPPROJECT_LISTOFWORDS_H
