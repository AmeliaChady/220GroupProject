//
// Created by Amelia Chady on 12/1/2018.
// Allows the user to use the program
//

#include "Util.h"
#include "List.h"
#include "Quiz.h"
#include "RandomQuiz.h"
#include "PresetQuiz.h"
#include "ListOfWordsChanger.h"
#include <iostream>
#include <typeinfo>
#include <string.h>

void menuState(int& state, std::string& filename, bool& printer, bool& preset, int& questions){
    // Text Blurb?
    if(printer) {
        std::cout << "\n--Main Menu--------" << std::endl;
        std::cout << "Main Menu Help:\n"
                     "start <preset/random> <integer> -> starts the quiz, allowing a user to\n"
                     "  pick the style of quiz, and for random quizzes, the number of questions.\n"
                     "  default is equivalent to \"start random 10\" "
                     "\n"
                     "load <filename> -> sets the filename for quiz to <filename>"
                     "\n"
                     //"edit -> Sends you to the editor mode"
                     //"\n"
                     "help -> prints this message"
                     "\n"
                     "quit -> exits out of the program"<< std::endl;
        printer = false;
    }
    std::cout << " >";
    // Get Input
    std::string userInput;
    std::getline(std::cin, userInput);

    try{
        List<std::string>* splitInput = split(userInput, " ");
        // Possible Functions
        if(splitInput->itemCount()!=0) {
            if(splitInput->getValueAt(0) == "start"){
                // Check start <preset or random>
                // TODO: Allowing preset and random with amount of questions
                try{
                    std::string type = splitInput->getValueAt(1);
                    if(type == "preset"){
                        preset = true;
                    }else if(type == "random"){
                        preset = false;
                        try{
                            questions = std::stoi(splitInput->getValueAt(2));
                        }catch(std::exception){
                            throw std::invalid_argument("");
                        }
                    }else{
                        throw std::invalid_argument("");
                    }
                    state = 1;
                    printer = true;
                }catch(std::out_of_range){
                    preset = false;
                    questions = 10;
                    state = 1;
                    printer = true;
                }catch(std::invalid_argument){
                    std::cout << "invalid argument(s)!" << std::endl;
                    state = 0;
                    printer = false;
                }

            }else if(splitInput->getValueAt(0) == "load") {
                // Check load <filename>
                try{
                    filename = splitInput->getValueAt(1);
                    std::cout << "Set quiz as: " << filename << std::endl;
                    filename += ".csv";
                }catch(std::out_of_range&){
                    std::cout << "Filename needed!" << std::endl;
                }
            //}else if(splitInput->getValueAt(0) == "edit"){
            //    // Check edit
            //    state = 2;
            //    printer = true;
            }else if(splitInput->getValueAt(0) == "help"){
                // Check help
                std::cout << "Main Menu Help:\n"
                             "start <preset/random> <integer> -> starts the quiz, allowing a user to\n"
                             "  pick the style of quiz, and for random quizzes, the number of questions.\n"
                             "  default is equivalent to \"start random 10\" "
                             "\n"
                             "load <filename> -> sets the filename for quiz to <filename>"
                             "\n"
                             //"edit -> Sends you to the editor mode"
                             //"\n"
                             "help -> prints this message"
                             "\n"
                             "quit -> exits out of the program"<< std::endl;
            }else if(splitInput->getValueAt(0) == "quit"){
                // Check quit
                state = -1;
                printer = true;
            }else{
                std::cout << "not valid command. type \"help\" for help" << std::endl;
            }
        }
        delete splitInput;
    }catch(std::invalid_argument&){
        //std::cout << "Invalid!" << std::endl;
    }


}

void quizState(int& state, std::string& filename, bool& printer, bool& preset, SoundMap* soundMap, int& questions){
    // Text Blurb?
    if(printer){
        std::cout << "\n--Quiz--------" << std::endl;
        std::cout << "Quiz Help:"
                     "<1-4> -> Answers the current question as that answer"
                     "\n"
                     "help -> displays this message"
                     "\n"
                     "exit -> goes back to the main menu, not saving the quiz or current progress"
                     "\n"
                     "reprint -> reprints the current question" << std::endl;
        printer = false;
    }

    bool loaded = false;

    Quiz* quiz;
    try {
        if (preset) {
            // Preset Quiz needs a file name in the constructor
            quiz = new PresetQuiz(soundMap, filename);
        } else {
            // Random Quiz also needs a file name in the constructor
            quiz = new RandomQuiz(soundMap, filename, questions);
        }
        loaded = true;
    }catch(std::exception){
         state = 0;
         printer = true;
         loaded = false;

         std::cout << "\n \n File not found! Did you make sure it's in the correct directory? \n \n";
         std::flush(std::cout);
    }

    if(loaded) {
        bool quizFinished = false;
        bool getNextQuestion = true;
        std::string question = "";
        while (state == 1) {
            if (getNextQuestion) {
                try {
                    question = quiz->presentQuestion();
                    std::cout << question << std::endl;
                    getNextQuestion = false;
                } catch (std::out_of_range) {
                    state = 0;
                    printer = true;
                    quizFinished = true;
                }
            }
            if (!quizFinished) {
                std::cout << " >";
                // Get Input
                std::string userInput;
                std::getline(std::cin, userInput);
                try {
                    List<std::string> *splitInput = split(userInput, " ");
                    // Possible functions
                    if (splitInput->getValueAt(0) == "1") {
                        std::cout << quiz->checkAnswer(1) << std::endl;
                        getNextQuestion = true;
                    } else if (splitInput->getValueAt(0) == "2") {
                        std::cout << quiz->checkAnswer(2) << std::endl;
                        getNextQuestion = true;
                    } else if (splitInput->getValueAt(0) == "3") {
                        std::cout << quiz->checkAnswer(3) << std::endl;
                        getNextQuestion = true;
                    } else if (splitInput->getValueAt(0) == "4") {
                        std::cout << quiz->checkAnswer(4) << std::endl;
                        getNextQuestion = true;
                    } else if (splitInput->getValueAt(0) == "help") {
                        std::cout << "Quiz Help:"
                                     "<1-4> -> Answers the current question as that answer"
                                     "\n"
                                     "help -> displays this message"
                                     "\n"
                                     "exit -> goes back to the main menu, not saving the quiz or current progress"
                                     "\n"
                                     "reprint -> reprints the current question" << std::endl;
                    } else if (splitInput->getValueAt(0) == "exit") {
                        // Check exit
                        state = 0;
                        printer = true;
                    } else if (splitInput->getValueAt(0) == "reprint") {
                        std::cout << question << std::endl;
                    } else {
                        std::cout << "not valid command. type \"help\" for help" << std::endl;
                    }
                } catch (std::invalid_argument &) {

                }
            }
        }

        quiz->saveQuiz();
        std::cout << quiz->getScore() << "\n";
        std::cout << "Quiz saved!\n";

        if (strcmp(typeid(quiz).name(), "RandomQuiz") == 0){
            delete (RandomQuiz *) quiz;
        } else {
            delete (PresetQuiz *) quiz;
        }

    }
}

/*
void editState(int& state, bool& printer){
    // Text Blurb?
    if(printer){
        std::cout << "--Editor--------" << std::endl;
        printer = false;
    }

    ListOfWordsChanger* words = new ListOfWordsChanger();

    while(state == 2) {
        std::cout << " >";
        // Get Input
        std::string userInput;
        std::getline(std::cin, userInput);

        try {
            List<std::string> *splitInput = split(userInput, " ");
            // Possible Functions
            if (splitInput->itemCount() != 0) {
                if (splitInput->getValueAt(0) == "save") {
                    // Check save <filename>
                    try {
                        std::string filename = splitInput->getValueAt(1);
                        words->save(filename);
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument" << std::endl;
                    }
                } else if (splitInput->getValueAt(0) == "load") {
                    // Check load <filename>
                    try {
                        std::string filename = splitInput->getValueAt(1);
                        ListOfWordsChanger* temp = new ListOfWordsChanger(filename);
                        delete words;
                        words = temp;
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument" << std::endl;

                    }
                } else if (splitInput->getValueAt(0) == "add") {
                    // Check add <spelling> <phonetic>
                    try {
                        std::string addedSpelling = splitInput->getValueAt(1);
                        std::string addedPhonetic = splitInput->getValueAt(2);
                        words->addWord(addedSpelling, addedPhonetic);
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument(s)" << std::endl;
                    }
                } else if (splitInput->getValueAt(0) == "remove") {
                    // Check remove <spelling>
                    try {
                        std::string removedWord = splitInput->getValueAt(1);
                        words->removeWord(removedWord);
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument" << std::endl;
                    }
                } else if (splitInput->getValueAt(0) == "help") {
                    // Check help
                    std::cout << "Editor Help"
                                 "save <filename> -> saves the word list as filename"
                                 "\n"
                                 "load <filename> -> loads the word list at that filename if it exists"
                                 "\n"
                                 "add <spelling> <phonetic> -> adds a new word with the spelling and ASCII phonetic descriptions to the list"
                                 "\n"
                                 "remove <spelling> -> removes a word by is spelling definition"
                                 "\n"
                                 "help -> shows this message"
                                 "\n"
                                 "exit -> goes to the main menu without saving" << std::endl;
                } else if (splitInput->getValueAt(0) == "exit") {
                    // Check exit
                    printer = true;
                    state = 0;
                } else {
                    std::cout << "not valid command. type \"help\" for help" << std::endl;
                }
            }
        } catch (std::invalid_argument &) {

        }
    }

    delete words;
}
*/

int main(){
    SoundMap* soundMap = new ArraySoundMap();
    soundMap->read();
    std::string filename = "default.csv";
    int state = 0;
    bool printer = true;
    bool preset = false;
    int questions = 0;

    while(state>=0){
        if(state==0){
            menuState(state, filename, printer, preset, questions);
        }else if(state==1){
            quizState(state, filename, printer, preset, soundMap, questions);
        }//else if(state==2){
        //    editState(state, printer);
        //}
    }

    delete soundMap;
    std::cout << "Later, ya hopefully more memorized nerd" << std::endl;
    return 0;
}