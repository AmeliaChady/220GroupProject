//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_RANDOMQUIZ_H
#define INC_220GROUPPROJECT_RANDOMQUIZ_H


#include "Quiz.h"

class RandomQuiz : public Quiz {
private:
    void makeQuestion(std::string word);
public:
    RandomQuiz(std::string fileName, int numQuestions);

};
#endif //INC_220GROUPPROJECT_RANDOMQUIZ_H
