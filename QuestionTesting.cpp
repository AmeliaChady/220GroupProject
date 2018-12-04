//
// Created by Josh Hayden on 12/1/18.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include "Question.h"
#include "ListOfWords.h"


void QuestionTest(){
    std::string EnglishTest = "Testing";
    std::string phoneticTest = "Zesting";
    std::pair<std::string, std::string> testPair = {EnglishTest, phoneticTest};
    Question* testQuestion = new Question(testPair, "Westing", "Zestinw", "Zestwng");
    std::string toPrint = testQuestion->outputQuestion();
    std::cout<<toPrint<<std::endl;

}

void QuestionSoundMapTest(){
    std::cout<<"QuestionSoundMapTest beginning"<<std::endl;
    SoundMap* testMap = new ArraySoundMap("defaultSounds.txt");
    testMap->read();
    const std::pair<std::string,std::string> testPair = {"beet", "bit"};
    Question* testQuestion = new Question(testPair, testMap);
    std::string toPrint = testQuestion->outputQuestion();
    std::cout<<toPrint<<std::endl;
    std::string secondString = testQuestion->getAnswerString(2);
    std::cout<<secondString<<std::endl;
}

void ListOfWordsTest(){
    ListOfWords* testList = new ListOfWords("listOfWordsTest.csv");
    int i = 0;
    for (i = 0; i < 10; ++i){
        std::pair<std::string, std::string> testPair = testList->giveRandWord();
        std::string frontString = std::get<0>(testPair);
        std::string backString = std::get<1>(testPair);
        std::cout<< frontString <<std::endl;
        std::cout<< backString <<std::endl;
    }
}

void QuestionSoundMapMacro(){
    for (int i = 0; i < 10; ++i){
        QuestionSoundMapTest();
    }
}

int main(){
    QuestionTest();
    ListOfWordsTest();
    QuestionSoundMapMacro();
    return 0;
}

