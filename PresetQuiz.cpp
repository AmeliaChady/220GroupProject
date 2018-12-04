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
PresetQuiz(std::string fileName){

}

std::string PresetQuiz::presentQuestion(){
    if (answQuestions < quizCap){
        std::pair<std::string, std::string> holdForQuestion;
        //TODO read in line from file
        std::string holdForUI = makeQuestion(holdForQuestion);
        outf << holdForUI << std::endl;
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

}