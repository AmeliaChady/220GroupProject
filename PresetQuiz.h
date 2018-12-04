//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_PRESETQUIZ_H
#define INC_220GROUPPROJECT_PRESETQUIZ_H


#include "Quiz.h"

class PresetQuiz: public Quiz {
private:
    std::string makeQuestion(const std::pair<std::string, std::string> pairIn);
public:
    PresetQuiz(std::string fileName);
    std::string presentQuestion();
    std::string checkAnswer(int answerChoice);
    void saveQuiz(std::string fileName);
};

#endif //INC_220GROUPPROJECT_PRESETQUIZ_H
