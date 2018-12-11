//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_PRESETQUIZ_H
#define INC_220GROUPPROJECT_PRESETQUIZ_H


#include "Quiz.h"

class PresetQuiz: public Quiz {
private:
    PresetQuiz(const PresetQuiz& presetQuizToCopy);
    PresetQuiz& operator=(const PresetQuiz& presetQuizToCopy);
    std::string makeQuestion(const std::pair<std::string, std::string> pairIn);
public:
    PresetQuiz(SoundMap* soundMap, std::string fileName);
    ~PresetQuiz();
    std::string presentQuestion();
    std::string checkAnswer(int answerChoice);
    void saveQuiz();
    std::string getScore();
};

#endif //INC_220GROUPPROJECT_PRESETQUIZ_H
