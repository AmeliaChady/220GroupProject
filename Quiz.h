//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_QUIZ_H
#define INC_220GROUPPROJECT_QUIZ_H

#include <string>
#include "Question.h"
#include "ListOfWords.h"
#include "ArraySoundMap.h"
#include <fstream>

class Quiz {
protected:
    std::string writefile;
    int score;
    int answQuestions;
    int quizCap;
    SoundMap* workingMap;
    Question* currQuestion;
    ListOfWords* quizBank;
    std::ofstream outf;
private:
    /*
     * asks for Question object to be made
     * @returns Question object temp void
     */
    virtual std::string makeQuestion(const std::pair<std::string, std::string> pairIn)=0;

    //writes to file to store past tests

public:
    /*
     * creates Question object, asks question and passes resulting string up to UI
     * throws std::out_of_range error if questionCounter is greater than or equal to number of questions in quiz
     *
     */
    virtual std::string presentQuestion()=0;

    /*
     * given answer choice (1,2,3,4), passes
     */
    virtual std::string checkAnswer(int answerChoice)=0;

    virtual void saveQuiz()=0;

    virtual std::string getScore()=0;

    virtual void addToScore()=0;


};
#endif //INC_220GROUPPROJECT_QUIZ_H
