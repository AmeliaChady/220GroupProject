//
// Created by Timothy Marotta on 11/30/18.
//

#include "RandomQuiz.h"
#include <fstream>
#include <iostream>


//private
std::string RandomQuiz::makeQuestion(const std::pair<std::string, std::string> pairIn) {
    delete currQuestion;
    currQuestion = new Question(pairIn, workingMap);
    return currQuestion->outputQuestion();
}

//public
RandomQuiz::RandomQuiz(std::string fileName, int numQuestions) {
    this->file = fileName;
    this->score = 0;
    this->answQuestions = 0;
    this->quizCap = numQuestions;
    this->workingMap = new ArraySoundMap();
    this->currQuestion = nullptr;
    this->quizBank = new ListOfWords(fileName);
}

std::string RandomQuiz::presentQuestion(){
    if (answQuestions < quizCap){
        std::pair<std::string, std::string> holdForQuestion = quizBank->giveRandWord();
        std::string holdForUI = makeQuestion(holdForQuestion);
        outf << holdForUI << std::endl;
        answQuestions++;
        return holdForUI;
    } else {
        throw std::out_of_range("No more questions.");
    }

}

std::string RandomQuiz::checkAnswer(int answerChoice) {
    std::string answerString = currQuestion->getAnswerString(answerChoice);
    outf << answerString << std::endl;
    return answerString;
}

void RandomQuiz::saveQuiz(){
    outf << getScore() << std::endl;
    outf.close();
}

std::string RandomQuiz::getScore(){
    return "Score: " + std::to_string(score);
}