//
// Created by Josh Hayden on 11/29/18.
//

#include "Question.h"
#include "ArraySoundMap.h"


std::string stringEdit(std::string toEdit, int index, std::string toInsert){
    std::string newString = toEdit;
    newString[index] = toInsert;
    return stringEdit;

}

//generates a new question, uses the soundMap to generate 3 random incorrect questions
//the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
Question::Question(std::pair<std::string,std::string> word, ArraySoundMap* soundMap){
    this.englishWord = std::get<0>(word);
    this.correctAnswer = std::get<1>(word);
    std::string baseString = "Does this work lol";
    baseString.copy()

}
//gives the use a multiple choice question, tells them if their answer is correct or not
void Question::ask(){
    int order = rand() % 4;
    if (order == 0){
        std::cout<<englishWord<<std::endl;
        std::cout<<"A. " + correctAnswer<<std::endl;
        std::cout<<"B. " + wrongOne<<std::endl;
        std::cout<<"C. " + wrongTwo<<std::endl;
        std::cout<<"D. " + wrongThree<<std::endl;
        std::string userAnswer;
        std::cin >> userAnswer;
        if (userAnswer == "A"){
            response = true;
            std::cout<< "Correct" << std::endl;
        }
        else{
            response = false;
            std::cout<< "Incorrect" <<std::endl;
        }
    }
    if (order == 1){
        std::cout<<englishWord<<std::endl;
        std::cout<<"A. " + wrongOne<<std::endl;
        std::cout<<"B. " + correctAnswer<<std::endl;
        std::cout<<"C. " + wrongTwo<<std::endl;
        std::cout<<"D. " + wrongThree<<std::endl;
        std::string userAnswer;
        std::cin >> userAnswer;
        if (userAnswer == "B"){
            response = true;
            std::cout<< "Correct" << std::endl;
        }
        else{
            response = false;
            std::cout<< "Incorrect" <<std::endl;
        }
    }
    if (order == 2){
        std::cout<<englishWord<<std::endl;
        std::cout<<"A. " + wrongOne<<std::endl;
        std::cout<<"B. " + wrongTwo<<std::endl;
        std::cout<<"C. " + correctAnswer<<std::endl;
        std::cout<<"D. " + wrongThree<<std::endl;
        std::string userAnswer;
        std::cin >> userAnswer;
        if (userAnswer == "C"){
            response = true;
            std::cout<< "Correct" << std::endl;
        }
        else{
            response = false;
            std::cout<< "Incorrect" <<std::endl;
        }
    }
    if (order == 3){
        std::cout<<englishWord<<std::endl;
        std::cout<<"A. " + wrongOne<<std::endl;
        std::cout<<"B. " + wrongTwo<<std::endl;
        std::cout<<"C. " + wrongThree<<std::endl;
        std::cout<<"D. " + correctAnswer<<std::endl;
        std::string userAnswer;
        std::cin >> userAnswer;
        if (userAnswer == "D"){
            response = true;
            std::cout<< "Correct" << std::endl;
        }
        else{
            response = false;
            std::cout<< "Incorrect" <<std::endl;
        }
    }
}
//outputs the question in a printout type of format, not sure if we need this functionality
//but should be easy enough to do, basically a toString
std::string Question::outputQuestion(){

}

bool Question::getResponse() {
    return response;
}