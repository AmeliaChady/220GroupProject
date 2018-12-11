//
// Created by Timothy Marotta on 11/30/18.
//

#include <fstream>
#include "PresetQuiz.h"
#include <time.h>

//private
std::string PresetQuiz::makeQuestion(const std::pair<std::string, std::string> pairIn){
    delete currQuestion;
    currQuestion = new Question(pairIn, workingMap);
    return currQuestion->outputQuestion();
}

//public
PresetQuiz::PresetQuiz(SoundMap* soundMap, std::string fileName){
    time_t my_time = time(NULL);
    this->writefile = "PresetQuiz " + std::to_string(my_time) +".txt";
    this->quizBank = new ListOfWords(fileName);
    this->quizCap = 10;
    this->score = 0;
    this->answQuestions = 0;
    this->workingMap = soundMap;
    this->currQuestion = nullptr;
    outf.open(writefile, std::ios::app);
}

PresetQuiz::~PresetQuiz() {
    delete quizBank;
    quizBank = nullptr;

    workingMap = nullptr;

    delete currQuestion;
    currQuestion = nullptr;
}

std::string PresetQuiz::presentQuestion(){
    if (answQuestions < quizCap){
        std::pair<std::string, std::string> holdForQuestion = quizBank->giveWordAtIndex(answQuestions);
        std::string holdForUI = makeQuestion(holdForQuestion);
        outf << holdForUI << "/n";
        answQuestions++;
        return holdForUI;
    } else {
        throw std::out_of_range("No more questions.");
    }
}

std::string PresetQuiz::checkAnswer(int answerChoice){
    std::string answerString = currQuestion->getAnswerString(answerChoice);
    outf << answerString << std::endl;
    return answerString;
}

void PresetQuiz::saveQuiz(){
    outf << getScore() << std::endl;
    outf.close();
}

std::string PresetQuiz::getScore(){
    return "Score: " + std::to_string(score);
}