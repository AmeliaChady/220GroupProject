//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_RANDOMQUIZ_H
#define INC_220GROUPPROJECT_RANDOMQUIZ_H


#include "Quiz.h"

class RandomQuiz : public Quiz {
private:
    ListOfWords* quizBank;
    std::string makeQuestion(const std::pair<std::string, std::string>);
public:
    RandomQuiz(std::string fileName, int numQuestions);

};
#endif //INC_220GROUPPROJECT_RANDOMQUIZ_H
