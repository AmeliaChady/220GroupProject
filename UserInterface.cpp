//
// Created by Amelia Chady on 12/1/2018.
//
#include "Util.h"
#include "List.h"
#include <iostream>


void menuState(int& state, std::string& filename, bool& print){
    // Text Blurb?
    if(print) {
        std::cout << "--Main Menu--------" << std::endl;

        print = false;
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
                // Check start
                state = 1;
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
                print = true;
            }else if(splitInput->getValueAt(0) == "help"){
                // Check help
                std::cout << "todo" << std::endl;
            }else if(splitInput->getValueAt(0) == "quit"){
                // Check quit
                state = -1;
                print = true;
            }else{
                std::cout << "not valid command. type \"help\" for help";
            }
        }
        delete splitInput;
    }catch(std::invalid_argument&){
        //std::cout << "Invalid!" << std::endl;
    }


}

void quizState(int& state, std::string& filename, bool& printer){
    // Text Blurb?
    if(printer){
        std::cout << "--Quiz--------" << std::endl;
        printer = false;
    }

    std::cout << " >";
    // Get Input
    std::string userInput;
    std::getline(std::cin, userInput);
    List<std::string>* splitInput = split(userInput, " ");
    //Check letter or number answer

    // Check help

    // Check save

    // Check exit


}

void editState(int& state, std::string& filename, bool& printer){
    // Text Blurb?
    std::cout << "--Editor--------" << std::endl;
    std::cout << " >";
    // Get Input
    std::string userInput;
    std::getline(std::cin, userInput);


    try{
        List<std::string>* splitInput = split(userInput, " ");
        // Possible Functions
        if(splitInput->itemCount()!=0) {
            if(splitInput->getValueAt(0) == "save"){
                // Check save <filename>
                ge
            }else if(splitInput->getValueAt(0) == "load"){
                // Check load <filename>
            }else if(splitInput->getValueAt(0) == "add"){
                // Check add <spelling> <phonetic>
            }else if(splitInput->getValueAt(0) == "remove"){
                // Check remove <spelling>
                try{
                    std::string removedWord = splitInput->getValueAt(1);
                }catch(std::out_of_range){
                    std::cout << "remove requires a word to remove" << std::endl;
                }
            }else if(splitInput->getValueAt(0) == "help"){
                // Check help
                std::cout << "todo" << std::endl;
            }else if(splitInput->getValueAt(0) == "exit"){
                // Check exit
                state = 0;
            }else{
                std::cout << "not valid command. type \"help\" for help";
            }
        }
    }catch(std::invalid_argument) {

    }
}

int main(){

    std::string filename = "default";
    int state = 0;
    bool printer = true;

    while(state>=0){
        if(state==0){
            menuState(state, filename, printer);
        }else if(state==1){
            quizState(state, filename, printer);
        }else if(state==2){
            editState(state, filename, printer);
        }
    }
    std::cout << "Later, ya hopefully more memorized nerd" << std::endl;
    return 0;
}