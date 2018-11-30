//
// Created by Josh Hayden on 11/29/18.
//

#include "Question.h"
#include "ArraySoundMap.h"

Question::~Question(){

}

std::string stringEdit(std::string toEdit, int index, std::string toInsert);

//generates a new question, uses the soundMap to generate 3 random incorrect questions
//the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
Question::Question(std::pair<std::string,std::string> word){
    this.englishWord = std::get<0>(word);
    this.correctAnswer = std::get<1>(word);
    std::string baseString = "Does this work lol";
    baseString.copy()

}
//gives the use a multiple choice question, tells them if their answer is correct or not
void Question::ask(){

}
//outputs the question in a printout type of format, not sure if we need this functionality
//but should be easy enough to do, basically a toString
std::string Question::outputQuestion(){

}