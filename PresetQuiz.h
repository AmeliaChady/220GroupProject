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
    /*
     * constructor for Preset Quiz
     * @pre sound map must be created before a Quiz is created (passed by pointer)
     * @pre file name must be an existing set of pairs
     * @throws out_of_range exception if a question is asked after the number of questions is equal to or greater than
     * the capacity of the quiz
     */
    PresetQuiz(SoundMap* soundMap, std::string fileName);

    /*
     * destructor for Preset Quiz
     * @pre saveQuiz must be called before deleting the PresetQuiz
     */
    ~PresetQuiz();

    /*
     * gets English/IPA pair from ListOfWords interface, passes the pair and
     * gets a question to/from the Question interface and writes the resulting string to
     * a file
     * @return question string
     */
    std::string presentQuestion();

    /*
     * sends answerChoice to the Question interface, adds to the score if the resulting string
     * starts with 'C' (correct), and writes the answer string to a file
     * @returns answer string provided by Question
     */
    std::string checkAnswer(int answerChoice);

    /*
     * writes the score to a file and closes the write file stream
     */
    void saveQuiz();

    /*
     * returns Score: # out of ~
     * where # is the string of the score property
     * where ~ is the quiz capacity
     */
    std::string getScore();

    /*
     * adds one to the score property
     */
    void addToScore();
};

#endif //INC_220GROUPPROJECT_PRESETQUIZ_H
