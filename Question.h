//
// Created by Josh Hayden on 11/29/18.
// Used to take an english word and its phonetic translation and generate a multiple choice question
// Generates 3 wrong choices that are similar to the correct answer, substituting one similar sound
//



#ifndef INC_220GROUPPROJECT_QUESTION_H
#define INC_220GROUPPROJECT_QUESTION_H
#include <cstdlib>
#include <tuple>
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
    int correctOption;
public:
    /***
    * Constructor
    */
    Question(); //default constructor so arrays can be made
    /***
    * Generates a question with 3 incorrect multiple choice answers that are similar to the correct answer
    * @param word Pair contains an english word and its phonetic translation
    * @param soundMap used to find similar phonetic symbols for the part of the correctAnswer getting replaced
    */
    Question(std::pair<std::string,std::string> word, std::string wrongOneIn, std::string wrongTwoIn, std::string wrongThreeIn); //you shouldn't
    //ever have to use this, its for testing
    /***
    * Constructor used for testing without a soundMap
    * @param word English word and its phonetic translation
    * @param wrongOneIn hardcoded wrong answer
    * @param wrongTwoIn hardcoded wrong answer
    * @param wrongThreeIn hardcoded wrong answer
    */
    Question(const std::pair<std::string,std::string> word, SoundMap* soundMap); //generates a new question, uses the soundMap to generate 3 random incorrect questions
    //the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
    /***
    * Outputs the question for the use to answer
    * @return A string with the english word at the top and the correct answer and wrong anwers in random order
    */
    std::string outputQuestion();
    /***
    * Takes the users answer to a question and checks it
    * @param userAnswer int option for the multiple choice question
    * @return A string telling the user if they were correct or incorrect
    */
    std::string getAnswerString(int userAnswer); //returns either correct, or incorrect- answer is " "


};
#endif //INC_220GROUPPROJECT_QUESTION_H
