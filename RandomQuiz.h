//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_RANDOMQUIZ_H
#define INC_220GROUPPROJECT_RANDOMQUIZ_H


#include "Quiz.h"
#include <fstream>

class RandomQuiz : public Quiz {
private:
    RandomQuiz(const RandomQuiz& quizToCopy);
    RandomQuiz& operator=(const RandomQuiz& quizToCopy);
    std::string makeQuestion(const std::pair<std::string, std::string>);
public:
    RandomQuiz(ArraySoundMap* soundMap, std::string fileName, int numQuestions);
    ~RandomQuiz();
    std::string presentQuestion();
    std::string checkAnswer(int answerChoice);
    void saveQuiz();
    std::string getScore();

};
#endif //INC_220GROUPPROJECT_RANDOMQUIZ_H
