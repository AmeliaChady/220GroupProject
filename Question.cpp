//
// Created by Josh Hayden on 11/29/18.
//

#include "Question.h"
#include "ArraySoundMap.h"



std::string Question::stringEdit(std::string toEdit, int index, char toInsert){
    std::string newString = toEdit;
    newString[index] = toInsert;
    return newString;

}

Question::Question(){
    englishWord = "";
    correctAnswer = "";
    wrongOne = "";
    wrongTwo = "";
    wrongThree = "";
    correctOption = 0;
}

//generates a new question, uses the soundMap to generate 3 random incorrect questions
//the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
Question::Question(const std::pair<std::string,std::string> word, SoundMap* soundMap){
    this->englishWord = std::get<0>(word);
    this->correctAnswer = std::get<1>(word);
    std::cout<<"setting englishWord and correctAnswer worked"<<std::endl;
    int length = correctAnswer.size();
    int index = rand() % length;
    char character = correctAnswer[index];
    std::cout<<"selecting a character worked"<<std::endl;
    std::string charAsString(1, character);
    std::cout<<"String is set properly"<<std::endl;
    Sound* toUse = soundMap->getKey(charAsString);
    std::cout<<"Getting key worked"<<std::endl;
    std::string toInsert = toUse->getSimilarSymbol();
    char toInsertChar = toInsert[0];
    this->wrongOne = this->stringEdit(correctAnswer, index, toInsertChar);
    std::cout<<"first wrong answer worked"<<std::endl;
    index = rand() % length;
    character = correctAnswer[index];
    std::string charAsString2(1, character);
    toUse = soundMap->getKey(charAsString);
    toInsert = toUse->getSimilarSymbol();
    toInsertChar = toInsert[0];
    this->wrongTwo = this->stringEdit(correctAnswer, index, toInsertChar);
    index = rand() % length;
    character = correctAnswer[index];
    std::string charAsString3(1, character);
    toUse = soundMap->getKey(charAsString);
    toInsert = toUse->getSimilarSymbol();
    toInsertChar = toInsert[0];
    this->wrongThree = this->stringEdit(correctAnswer, index, toInsertChar);
    correctOption = 1;



}
Question::Question(std::pair<std::string, std::string> word, std::string wrongOneIn, std::string wrongTwoIn, std::string wrongThreeIn){
    this->englishWord = std::get<0>(word);
    this->correctAnswer = std::get<1>(word);
    this->wrongOne = wrongOneIn;
    this->wrongTwo = wrongTwoIn;
    this->wrongThree = wrongThreeIn;

}

std::string Question::outputQuestion(){
    int order = rand() % 4;
    std::string questionStr = "";
    if (order == 0) {
        questionStr = this->englishWord + "\n";
        questionStr = questionStr + "1. " + this->correctAnswer + "\n";
        questionStr = questionStr + "2. " + this->wrongOne + "\n";
        questionStr = questionStr + "3. " + this->wrongTwo + "\n";
        questionStr = questionStr + "4. " + this->wrongThree + "\n";

        this->correctOption = 1;
    }

    else if (order == 1) {
        questionStr = this->englishWord + "\n";
        questionStr = questionStr + "1. " + this->wrongOne + "\n";
        questionStr = questionStr + "2. " + this->correctAnswer + "\n";
        questionStr = questionStr + "3. " + this->wrongTwo + "\n";
        questionStr = questionStr + "4. " + this->wrongThree + "\n";
        this->correctOption = 2;
    }
    else if (order == 2) {
        questionStr = this->englishWord + "\n";
        questionStr = questionStr + "1. " + this->wrongOne + "\n";
        questionStr = questionStr + "2. " + this->correctAnswer + "\n";
        questionStr = questionStr + "3. " + this->wrongTwo + "\n";
        questionStr = questionStr + "4. " + this->wrongThree + "\n";
        this->correctOption = 3;
    }
    else { //order == 3
        questionStr = this->englishWord + "\n";
        questionStr = questionStr + "1. " + this->wrongOne + "\n";
        questionStr = questionStr + "2. " + this->correctAnswer + "\n";
        questionStr = questionStr + "3. " + this->wrongTwo + "\n";
        questionStr = questionStr + "4. " + this->wrongThree + "\n";
        this->correctOption = 4;
    }
    return questionStr;


}




std::string Question::getAnswerString(int userAnswer){
    std::string answerString = "";
    if (userAnswer == this->correctOption){
        answerString = "Correct.";
    }
    else{ //answer is wrong
        answerString = "Incorrect: Correct answer is - " + this->correctAnswer + ".";
    }
    return answerString;
} //returns either correct, or incorrect- answer is " "