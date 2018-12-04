//
// Created by Timothy Marotta on 11/30/18.
//

#include "PresetQuiz.h"

//private
std::string PresetQuiz::makeQuestion(const std::pair<std::string, std::string> pairIn){
    delete currQuestion;
    currQuestion = new Question(pairIn, workingMap);
    return currQuestion->outputQuestion();
}

//public
PresetQuiz::PresetQuiz(std::string fileName){
    this->quizBank = new ListOfWords(fileName);
    this->quizCap = 10;
    this->score = 0;
    this->answQuestions = 0;
    this->workingMap = new ArraySoundMap();
    this->currQuestion = nullptr;
}

std::string PresetQuiz::presentQuestion(){
    if (answQuestions < quizCap){
        std::pair<std::string, std::string> holdForQuestion = quizBank->giveWordAtIndex(answQuestions);
        std::string holdForUI = makeQuestion(holdForQuestion);
        //outf << holdForUI << "/n";
        answQuestions++;
        return holdForUI;
    } else {
        throw std::out_of_range("No more questions.");
    }
}

std::string PresetQuiz::checkAnswer(int answerChoice){
    std::string answerString = currQuestion->getAnswerString(answerChoice);
    //TODO outf << answerString << std::endl;
    return answerString;
}

void PresetQuiz::saveQuiz(std::string fileName){
    //TODO write score to quiz
    //TODO close file
}

std::string PresetQuiz::getScore(){
    return "Score: " + std::to_string(score);
}