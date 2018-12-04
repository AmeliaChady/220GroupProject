//
// Created by Amelia Chady on 12/1/2018.
//
#include "Util.h"
#include "List.h"
#include "Quiz.h"
#include "RandomQuiz.h"
#include "PresetQuiz.h"
#include "ListOfWordsChanger.h"
#include <iostream>


// Tim's TODO:
// TODO: PresetQuiz constructor with a filename
// TODO: RandomQuiz constructor with a filename & question count
// TODO: A way to save quizzes, with an inputted filename
// TODO: ListOfWordsChanger constructor with a filename
// TODO: ListOfWordsChanger save function with a filename


void menuState(int& state, std::string& filename, bool& printer, bool& preset){
    // Text Blurb?
    if(printer) {
        std::cout << "--Main Menu--------" << std::endl;

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
                state = 1;
                printer = true;
            }else if(splitInput->getValueAt(0) == "load") { // TODO: Figure out a better name
                // Check load <filename>
                try{
                    filename = splitInput->getValueAt(1);
                    std::cout << "Set quiz as: " << filename << std::endl;

                }catch(std::out_of_range&){
                    std::cout << "Filename needed!" << std::endl;
                }
            }else if(splitInput->getValueAt(0) == "edit"){
                // Check edit
                state = 2;
                printer = true;
            }else if(splitInput->getValueAt(0) == "help"){
                // Check help
                //TODO Make a better help function
                std::cout << "Main Menu Help:\n"
                             "start <preset/random> <integer> -> starts the quiz, allowing a user to\n"
                             "  pick the style of quiz, and for random quizzes, the number of questions.\n"
                             "  default is equivalent to \"start random 10\" "
                             "\n"
                             "load <filename> -> sets the filename for quiz to <filename>"
                             "\n"
                             "edit -> Sends you to the editor mode"
                             "\n"
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

void quizState(int& state, std::string& filename, bool& printer, bool& preset){
    // Text Blurb?
    if(printer){
        std::cout << "--Quiz--------" << std::endl;
        printer = false;
    }

    Quiz* quiz;
    if(preset){
        // Preset Quiz needs a file name in the constructor
        quiz = new PresetQuiz(filename);
    }else{
        // Random Quiz also needs a file name in the constructor
        quiz = new RandomQuiz(filename, 10);
    }

    bool quizFinished = false;
    bool getNextQuestion = true;
    std::string question = "";
    while(state==1){
        if(getNextQuestion){
            try{
                question = quiz->presentQuestion();
                std::cout << question << std::endl;
                getNextQuestion = false;
            }catch(std::out_of_range ){
                state = 0;
                printer = true;
            }
        }

        std::cout << " >";
        // Get Input
        std::string userInput;
        std::getline(std::cin, userInput);
        try{
            List<std::string> *splitInput = split(userInput, " ");
            // Possible functions
            if(splitInput->getValueAt(0)=="1"){
                std::cout << quiz->checkAnswer(1) << std::endl;
                getNextQuestion = true;
            }else if(splitInput->getValueAt(0)=="2"){
                std::cout << quiz->checkAnswer(2) << std::endl;
                getNextQuestion = true;
            }else if(splitInput->getValueAt(0)=="3"){
                std::cout << quiz->checkAnswer(3) << std::endl;
                getNextQuestion = true;
            }else if(splitInput->getValueAt(0)=="4"){
                std::cout << quiz->checkAnswer(4) << std::endl;
                getNextQuestion = true;
            }else if(splitInput->getValueAt(0)=="help"){
                //TODO
                std::cout << "todo" << std::endl;
            }else if(splitInput->getValueAt(0)=="exit"){
                // Check exit
                state = 0;
                printer = true;
            }else if(splitInput->getValueAt(0)=="reprint"){
                std::cout << question << std::endl;
            }else if(splitInput->getValueAt(0)=="save"){
                // Check save <filename>
                // TODO: Move Save
                try{
                    std::string saveFilename = splitInput->getValueAt(1);

                }catch(std::out_of_range&){
                    std::cout << "Filename needed!" << std::endl;
                }
            }else{
                std::cout << "not valid command. type \"help\" for help" << std::endl;
            }
        }catch(std::invalid_argument&){

        }
    }

    delete quiz;
}

void editState(int& state, bool& printer){
    // Text Blurb?
    if(printer){
        std::cout << "--Editor--------" << std::endl;
        printer = false;
    }

    ///ListOfWordsChanger* words = new ListOfWordsChanger();

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
                        ///words->save(filename);
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument" << std::endl;
                    }
                } else if (splitInput->getValueAt(0) == "load") {
                    // Check load <filename>
                    try {
                        std::string filename = splitInput->getValueAt(1);
                        ///ListOfWordsChanger* temp = new ListOfWordsChanger(filename);
                        ///delete words;
                        ///words = temp;
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument" << std::endl;

                    }
                } else if (splitInput->getValueAt(0) == "add") {
                    // Check add <spelling> <phonetic>
                    try {
                        std::string addedSpelling = splitInput->getValueAt(1);
                        std::string addedPhonetic = splitInput->getValueAt(2);
                        ///words->addWord(addedSpelling, addedPhonetic);
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument(s)" << std::endl;
                    }
                } else if (splitInput->getValueAt(0) == "remove") {
                    // Check remove <spelling>
                    try {
                        std::string removedWord = splitInput->getValueAt(1);
                        ///words->removeWord(removedWord);
                    } catch (std::out_of_range &) {
                        std::cout << "Invalid argument" << std::endl;
                    }
                } else if (splitInput->getValueAt(0) == "help") {
                    // Check help
                    // TODO
                    std::cout << "todo" << std::endl;
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

    ///delete words;
}

int main(){

    std::string filename = "default.csv";
    int state = 0;
    bool printer = true;
    bool preset = false;

    while(state>=0){
        if(state==0){
            menuState(state, filename, printer, preset);
        }else if(state==1){
            quizState(state, filename, printer, preset);
        }else if(state==2){
            editState(state, printer);
        }
    }
    std::cout << "Later, ya hopefully more memorized nerd" << std::endl;
    return 0;
}