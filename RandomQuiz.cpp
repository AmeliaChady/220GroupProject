//
// Created by Timothy Marotta on 11/30/18.
//

#include "RandomQuiz.h"
#include <fstream>
#include <iostream>


//private
std::string RandomQuiz::makeQuestion(const std::pair<std::string, std::string> pairIn) {
    Question* currQuestion = new Question(pairIn, workingMap);
    return currQuestion->outputQuestion();
}

std::string RandomQuiz::getAndWriteAnswer() {

}

//public
RandomQuiz::RandomQuiz(std::string fileName, int numQuestions) {
    std::ofstream outf(fileName);
    this->quizBank = new ListOfWords(fileName);
    this->quizCap = numQuestions;
    this->workingMap = new ArraySoundMap();

}

std::string RandomQuiz::presentQuestion(){
    if (answQuestions < quizCap){
        std::pair<std::string, std::string> holdForQuestion = quizBank->giveRandWord();
        std::string holdForUI = makeQuestion(holdForQuestion);
        //write to file
        answQuestions++;
        return holdForUI;
    } else {
        throw std::out_of_range("No more questions.");
    }

}

std::string RandomQuiz::checkAnswer(int answerChoice) {

}

void RandomQuiz::saveQuiz(std::string fileName){

}