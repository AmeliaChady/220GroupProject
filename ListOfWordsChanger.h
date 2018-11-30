//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_LISTOFWORDSCHANGER_H
#define INC_220GROUPPROJECT_LISTOFWORDSCHANGER_H


#include <string>

class ListOfWordsChanger {
public:
    void addWord(std::string word, std::string phoneticSpelling);
    void removeWord(std::string word);
};


#endif //INC_220GROUPPROJECT_LISTOFWORDSCHANGER_H
