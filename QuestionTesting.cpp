//
// Created by Josh Hayden on 12/1/18.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include "Question.h"


void QuestionTest(){
    std::string EnglishTest = "Testing";
    std::string phoneticTest = "Zesting";
    std::pair<std::string, std::string> testPair = {EnglishTest, phoneticTest};
    Question* testQuestion = new Question(testPair, "Westing", "Zestinw", "Zestwng");
    std::string toPrint = testQuestion->outputQuestion();
    std::cout<<toPrint<<std::endl;

}

int main(){
    QuestionTest();
    return 0;
}

