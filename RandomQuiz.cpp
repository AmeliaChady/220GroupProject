//
// Created by Timothy Marotta on 11/30/18.
//

#include "RandomQuiz.h"
#include <fstream>
#include <iostream>

//private
void RandomQuiz::makeQuestion(std::string word) {

}

std::string RandomQuiz::getAndWriteAnswer() {

}

//public
RandomQuiz::RandomQuiz(std::string fileName, int numQuestions) {

    std::string timeDate = std::to_string(std::chrono::system_clock::now());
    std::ofstream outf("Random Quiz " + timeDate + ".txt");




}
