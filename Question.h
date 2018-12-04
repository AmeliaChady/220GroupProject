//
// Created by Josh Hayden on 11/29/18.
//

#ifndef INC_220GROUPPROJECT_QUESTION_H
#define INC_220GROUPPROJECT_QUESTION_H
#include <cstdlib>
#include <string>
#include "ArraySoundMap.h"
#include "Sound.h"

class Question{
private:
    std::string englishWord; //english translation
    std::string correctAnswer;
    std::string wrongOne;
    std::string wrongTwo;
    std::string wrongThree;
    std::string stringEdit(std::string toEdit, int index, char toInsert);
    int correctOption;
public:
    Question(); //default constructor so arrays can be made
    Question(std::pair<std::string,std::string> word, std::string wrongOneIn, std::string wrongTwoIn, std::string wrongThreeIn); //you shouldn't
    //ever have to use this, its for testing

    Question(const std::pair<std::string,std::string> word, SoundMap* soundMap); //generates a new question, uses the soundMap to generate 3 random incorrect questions
    //the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
    std::string outputQuestion(); //outputs the question in a printout type of format, not sure if we need this functionality
    //but should be easy enough to do, basically a toString

    std::string getAnswerString(int userAnswer); //returns either correct, or incorrect- answer is " "

};
#endif //INC_220GROUPPROJECT_QUESTION_H
