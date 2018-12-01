//
// Created by Amelia Chady on 12/1/2018.
//
#include "Util.h"
#include "List.h"
#include <iostream>


void menuState(int& state){
    // Text Blurb?
    std::cout << "Main Menu Motherfuckers" << std::endl;
    std::cout << "Input: ";
    // Get Input
    std::string userInput;
    std::getline(std::cin, userInput);
    List<std::string>* splitInput = split(userInput, " ");
    if(splitInput->itemCount()!=0) {
        // Check start
        if(splitInput->getValueAt(0) == "start"){
            state = 1;
        }

        // Check load <filename>


        // Check edit
        if(splitInput->getValueAt(0)=="edit"){
            state = 2;
        }

        // Check help


        // Check quit
        if(splitInput->getValueAt(0)=="quit"){
            state = -1;
        }
    }
}

void quizState(int& state){
    // Text Blurb?

    // Get Input

    // Check letter or number answer

    // Check save

    // Check exit


}

void editState(int& state){

}

int main(){
    int state = 0;
    while(state>=0){
        if(state==0){
            menuState(state);
        }else if(state==1){
            quizState(state);
        }else if(state==2){
            editState(state);
        }
    }
    std::cout << "Later, ya hopefully more memorized nerd" << std::endl;
    return 0;
}