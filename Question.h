//
// Created by Josh Hayden on 11/29/18.
//

#ifndef INC_220GROUPPROJECT_QUESTION_H
#define INC_220GROUPPROJECT_QUESTION_H
#include <cstdlib>

class Question{
private:
    std::string englishWord; //english translation
    std::string correctAnswer;
    std::string wrongOne;
    std::string wrongTwo;
    std::string wrongThree;
    std::string stringEdit(std::string toEdit, int index, std::string toInsert);
    bool response; //tracks if the user got the question wrong or right
public:
    Question(std::pair<std::string,std::string> word, ArraySoundMap* soundMap); //generates a new question, uses the soundMap to generate 3 random incorrect questions
    //the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
    void ask(); //gives the use a multiple choice question, tells them if their answer is correct or not
    std::string outputQuestion(); //outputs the question in a printout type of format, not sure if we need this functionality
    //but should be easy enough to do, basically a toString
    bool getResponse(); //outputs response

};
#endif //INC_220GROUPPROJECT_QUESTION_H
