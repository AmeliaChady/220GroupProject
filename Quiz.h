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
     * deletes previous question object (stored in currQuestion), makes a new question object
     * and returns the string containing the question & answer choices from the Question Interface
     */
    virtual std::string makeQuestion(const std::pair<std::string, std::string> pairIn)=0;

    //writes to file to store past tests

public:
    /*
    * gets English/IPA pair from ListOfWords interface, passes the pair and
    * gets a question to/from the Question interface and writes the resulting string to
    * a file
    * @return question string
    */
    virtual std::string presentQuestion()=0;

    /*
     * sends answerChoice to the Question interface, adds to the score if the resulting string
     * starts with 'C' (correct), and writes the answer string to a file
     * @returns answer string provided by Question
     */
    virtual std::string checkAnswer(int answerChoice)=0;

    /*
     * writes the score to a file and closes the write file stream
     */
    virtual void saveQuiz()=0;

    /*
     * returns Score: # out of ~
     * where # is the string of the score property
     * where ~ is the quiz capacity
     */
    virtual std::string getScore()=0;

    /*
     * adds one to the score property
     */
    virtual void addToScore()=0;


};
#endif //INC_220GROUPPROJECT_QUIZ_H
