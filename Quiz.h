//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_QUIZ_H
#define INC_220GROUPPROJECT_QUIZ_H

#include <string>

class Quiz {
private:
    /*
     * asks for Question object to be made
     * @returns Question object temp void
     */
    virtual void makeQuestion(std::string word)=0;

    /*
     * retrieves answer from Question, writes to a file, send to UI
     */
    virtual std::string getAndWriteAnswer()=0;

    int score;
    int numQuestions;
    int quizCap;

    //writes to file to store past tests

public:
    //destructor to be declared in child classes
    virtual ~Quiz()=0;

    /*
     * creates Question object, asks question and passes resulting string up to UI
     * throws std::out_of_range error if questionCounter is greater than or equal to number of questions in quiz
     *
     */
    virtual std::string presentQuestion(std::string word)=0;

    /*
     * given answer choice (1,2,3,4), passes
     */
    virtual std::string checkAnswer(int answerChoice)=0;



};
#endif //INC_220GROUPPROJECT_QUIZ_H
