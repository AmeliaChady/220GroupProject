//
// Created by Timothy Marotta on 11/30/18.
//

#include "RandomQuiz.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>


//private
std::string RandomQuiz::makeQuestion(const std::pair<std::string, std::string> pairIn) {
    delete currQuestion;
    currQuestion = new Question(pairIn, workingMap);
    return currQuestion->outputQuestion();
}

//public
RandomQuiz::RandomQuiz(SoundMap* soundMap, std::string readFileName, int numQuestions) {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();

    this->writefile = "RandomQuiz " + str;
    this->score = 0;
    this->answQuestions = 0;
    this->quizCap = numQuestions;
    this->workingMap = soundMap;
    this->currQuestion = nullptr;
    this->quizBank = new ListOfWords(readFileName);
    outf.open(writefile, std::ios::app);
}

RandomQuiz::~RandomQuiz() {
    if (outf.is_open()){
        outf.close();
    }

    delete currQuestion;
    currQuestion = nullptr;

    workingMap = nullptr;

    delete quizBank;
    quizBank = nullptr;
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
    if (answerString[0] == 'C'){
        this->addToScore();
    }
    outf << answerString << std::endl;
    return answerString;
}

void RandomQuiz::saveQuiz(){
    outf << getScore() << std::endl;
    outf.close();
}

std::string RandomQuiz::getScore(){
    return "Score: " + std::to_string(score) + " out of  " + std::to_string(quizCap);
}

void RandomQuiz::addToScore(){
    this->score++;
}