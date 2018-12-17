//
// Created by Josh Hayden on 11/29/18.
// Essentially used to create a wordbank that english words can be drawn from
// This wordbank is drawn from a csv file containing many english words and their translations
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
    /***
    * Default Constructor
    */
    ListOfWords();
    /***
    * Destructor
     */
    ~ListOfWords();
    /***
    * Constructor
    * @param fileNameIn takes the name of the csv file that the wordBank is drawn from
    */
    ListOfWords(std::string fileNameIn); //generates a list from the fileName
    /***
    * gives a random pair from the wordBank
    * @return a  std::pair, consisting of an english word first and its phonetic translation second, drawn randomly from the wordBank
    */
    std::pair<std::string, std::string> giveRandWord(); //outputs a random word in the wordBank
    /***
    * for returning a specific pair
    * @param index int that is a given index in the wordBank arrayList
    * @return the pair at the entered index
    */
    std::pair<std::string, std::string> giveWordAtIndex(int index);

};
#endif //INC_220GROUPPROJECT_LISTOFWORDS_H
