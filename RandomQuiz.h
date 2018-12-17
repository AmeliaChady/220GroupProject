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
    /*
     * constructor for Random Quiz
     * @pre sound map must be created before a Quiz is created (passed by pointer)
     * @pre file name must be an existing set of pairs
     * @throws out_of_range exception if a question is asked after the number of questions is equal to or greater than
     * the capacity of the quiz
     */
    RandomQuiz(SoundMap* soundMap, std::string fileName, int numQuestions);

    /*
     * destructor for Random Quiz
     * @pre saveQuiz must be called before deleting the PresetQuiz
     */
    ~RandomQuiz();

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
#endif //INC_220GROUPPROJECT_RANDOMQUIZ_H
