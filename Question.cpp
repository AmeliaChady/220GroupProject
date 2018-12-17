//
// Created by Josh Hayden on 11/29/18.
//

#include "Question.h"
#include "ArraySoundMap.h"
#include "Util.h"
#include <locale>
#include <codecvt>

bool replace(std::string& str, const std::string& from, const std::string& to);

/**
 * converts a given string from ASCII to Unicode, makes certain phonetic symbols more readable
 * @param input the ASCII string to be converted
 * @return a Unicode version of the ASCII string
 */
bool unicodeConvert(std::string& input){
    std::string letters[] = { "p",  "b",  "m", ".w",  "f",  "v",  "T",  "D",  "t",  "d",  "s",  "z",  "n",
                              "l", ".S", ".Z",  "S",  "Z",  "r",  "R",  "j",  "k",  "g",  "N",  "h",
                              "i",  "I",  "e",  "E",  "&",  ")",  "u",  "U",  "o",  "^",  "O",  "A",  "y",  "H",
                             "~i", "~I", "~e", "~E", "~&", "~)", "~u", "~U", "~o", "~^", "~O", "~A", "~y"};
    std::string unicode[] = { "p",  "b",  "m",  "w",  "f",  "v",  "θ",  "ð",  "t",  "d",  "s",  "z",  "n",
                              "l",  "ʧ",  "ʤ",  "ʃ",  "ʒ",  "ɾ",  "r",  "j",  "k",  "g",  "ŋ",  "h",
                              "i",  "ɪ",  "e",  "ɛ",  "æ",  "ə",  "u",  "ʊ",  "o",  "ʌ",  "ɔ",  "ɑ", "y",  "ʰ",
                              "̃i",  "̃ɪ",  "̃e",  "̃ɛ",  "̃æ",  "̃ə",  "̃u",  "̃ʊ",  "̃o",  "̃ʌ",  "̃ɔ",  "̃ɑ", "̃̃y"};
    int size = 52;
    for (int i = 0; i < size; ++i){
        std::string letter = letters[i];
        std::string uniSymbol = unicode[i];
        replace(input, letter, uniSymbol);
    }
    return true;
}
/***
 * Replaces part of a string with a different string
 * @param str the string to be edited
 * @param from the part of the string to be changed
 * @param to the string to replace from
 * @return
 */
bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
/***
 * Constructor
 */
Question::Question(){
    englishWord = "";
    correctAnswer = "";
    wrongOne = "";
    wrongTwo = "";
    wrongThree = "";
    correctOption = 0;
}
/***
 * Generates a question with 3 incorrect multiple choice answers that are similar to the correct answer
 * @param word Pair contains an english word and its phonetic translation
 * @param soundMap used to find similar phonetic symbols for the part of the correctAnswer getting replaced
 */
//generates a new question, uses the soundMap to generate 3 random incorrect questions
//the pair here is output from wordList originally, first string is the english word and second string is the correct phonetic translation
Question::Question(const std::pair<std::string,std::string> word, SoundMap* soundMap){
    this->englishWord = trim(std::get<0>(word));
    this->correctAnswer = trim(std::get<1>(word));
    int length = correctAnswer.size();
    int index = rand() % length;
    char character = correctAnswer[index];
    while (character == 'H'){
        index = rand() % length;
        character = correctAnswer[index];
    }
    std::string charAsString(1, character);
    if (character == '.'){
        char otherChar = correctAnswer[index + 1];
        charAsString += std::string(1, otherChar);
    }
    else if (index > 0 && correctAnswer[index - 1 ] == '.'){
        char otherChar = '.';
        charAsString = std::string(1, otherChar) + charAsString;
    }
    if (character == '~'){
        char otherChar = correctAnswer[index + 1];
        charAsString += std::string(1, otherChar);
    }
    else if (index > 0 && correctAnswer[index - 1] == '~'){
        char otherChar = '~';
        charAsString = std::string(1, otherChar) + charAsString;
    }
    Sound* toUse = soundMap->getKey(charAsString);
    std::string toInsert = toUse->getSimilarSymbol();
    std::string correctCopy = correctAnswer;
    replace(correctCopy, charAsString, toInsert);
    this->wrongOne = correctCopy;
    index = rand() % length;
    character = correctAnswer[index];
    while (character == 'H'){
        index = rand() % length;
        character = correctAnswer[index];
    }
    std::string charAsString2(1, character);
    if (character == '.'){
        char otherChar = correctAnswer[index + 1];
        charAsString2 += std::string(1, otherChar);
    }
    else if (index > 0 && correctAnswer[index - 1 ] == '.'){
        char otherChar = '.';
        charAsString2 = std::string(1, otherChar) + charAsString2;
    }
    if (character == '~'){
        char otherChar = correctAnswer[index + 1];
        charAsString2 += std::string(1, otherChar);
    }
    else if (index > 0 && correctAnswer[index - 1] == '~'){
        char otherChar = '~';
        charAsString2 = std::string(1, otherChar) + charAsString2;
    }
    toUse = soundMap->getKey(charAsString2);
    toInsert = toUse->getSimilarSymbol();
    correctCopy = correctAnswer;
    replace(correctCopy, charAsString2, toInsert);
    this->wrongTwo = correctCopy;
    index = rand() % length;
    character = correctAnswer[index];
    while (character == 'H'){
        index = rand() % length;
        character = correctAnswer[index];
    }
    std::string charAsString3(1, character);
    if (character == '.'){
        char otherChar = correctAnswer[index + 1];
        charAsString3 += std::string(1, otherChar);
    }
    else if (index > 0 && correctAnswer[index - 1 ] == '.'){
        char otherChar = '.';
        charAsString3 = std::string(1, otherChar) + charAsString3;
    }
    if (character == '~'){
        char otherChar = correctAnswer[index + 1];
        charAsString3 += std::string(1, otherChar);
    }
    else if (index > 0 && correctAnswer[index - 1] == '~'){
        char otherChar = '~';
        charAsString3 = std::string(1, otherChar) + charAsString3;
    }
    toUse = soundMap->getKey(charAsString3);
    toInsert = toUse->getSimilarSymbol();
    correctCopy = correctAnswer;
    replace(correctCopy, charAsString3, toInsert);
    this->wrongThree = correctCopy;
    unicodeConvert(correctAnswer);
    unicodeConvert(wrongOne);
    unicodeConvert(wrongTwo);
    unicodeConvert(wrongThree);

}
/***
 * Constructor used for testing without a soundMap
 * @param word English word and its phonetic translation
 * @param wrongOneIn hardcoded wrong answer
 * @param wrongTwoIn hardcoded wrong answer
 * @param wrongThreeIn hardcoded wrong answer
 */
Question::Question(std::pair<std::string, std::string> word, std::string wrongOneIn, std::string wrongTwoIn, std::string wrongThreeIn){
    this->englishWord = std::get<0>(word);
    this->correctAnswer = std::get<1>(word);
    this->wrongOne = wrongOneIn;
    this->wrongTwo = wrongTwoIn;
    this->wrongThree = wrongThreeIn;

}
/***
 * Outputs the question for the use to answer
 * @return A string with the english word at the top and the correct answer and wrong anwers in random order
 */

std::string Question::outputQuestion(){
    int order = rand() % 4;
    std::string questionStr = "<"+this->englishWord + ">\n";
    if (order == 0) {
        questionStr = questionStr + "1. [" + this->correctAnswer + "]\n";
        questionStr = questionStr + "2. [" + this->wrongOne + "]\n";
        questionStr = questionStr + "3. [" + this->wrongTwo + "]\n";
        questionStr = questionStr + "4. [" + this->wrongThree + "]\n";

        this->correctOption = 1;
    }

    else if (order == 1) {
        questionStr = questionStr + "1. [" + this->wrongOne + "]\n";
        questionStr = questionStr + "2. [" + this->correctAnswer + "]\n";
        questionStr = questionStr + "3. [" + this->wrongTwo + "]\n";
        questionStr = questionStr + "4. [" + this->wrongThree + "]\n";
        this->correctOption = 2;
    }
    else if (order == 2) {
        questionStr = questionStr + "1. [" + this->wrongOne + "]\n";
        questionStr = questionStr + "2. [" + this->wrongTwo + "]\n";
        questionStr = questionStr + "3. [" + this->correctAnswer + "]\n";
        questionStr = questionStr + "4. [" + this->wrongThree + "]\n";
        this->correctOption = 3;
    }
    else { //order == 3
        questionStr = questionStr + "1. [" + this->wrongOne + "]\n";
        questionStr = questionStr + "2. [" + this->wrongTwo + "]\n";
        questionStr = questionStr + "3. [" + this->wrongThree + "]\n";
        questionStr = questionStr + "4. [" + this->correctAnswer + "]\n";
        this->correctOption = 4;
    }

    return questionStr;


}


/***
 * Takes the users answer to a question and checks it
 * @param userAnswer int option for the multiple choice question
 * @return A string telling the user if they were correct or incorrect
 */

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