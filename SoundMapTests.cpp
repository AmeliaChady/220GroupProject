//
// Created by Amelia Chady on 11/27/2018.
//

#include <iostream>
#include "ArraySoundMap.h"
#include "Sound.h"

void testSound(){
    std::cout << "--Sound Tests--------" << std::endl;
    int passes = 0;
    int fails = 0;

    Sound soundA("A");

    //Testing getSymbol
    if(soundA.getSymbol() == "A"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }


    //Testing addConnection (and basic getSimilarSymbol
    Sound soundB("B");
    soundA.addConnection(&soundB);

    if(soundA.getSimilarSymbol() == soundB.getSymbol()) {
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(soundB.getSimilarSymbol() == soundA.getSymbol()){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }


    //Testing getSimilarSymbol Error
    try{
        Sound soundC("C");
        soundC.getSimilarSymbol();
        std::cout << "failed" << std::endl;
        fails++;
    }catch(std::out_of_range e){
        std::cout << "passed" << std::endl;
        passes++;
    }

    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

void testSoundMap(){
    std::cout << "--SoundMap Tests--------" << std::endl;
    int passes = 0;
    int fails = 0;

    try{
        SoundMap* testDefault = new ArraySoundMap();
        std::cout << "passed" << std::endl;
        passes++;
        delete testDefault;
    }catch(std::exception e){
        std::cout << "failed" << std::endl;
        fails++;
    }

    SoundMap* map = new ArraySoundMap("testMap.txt");

    if(map->getFileName() == "testMap.txt"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(map->getKey("A")->getSymbol()=="A"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(map->getKey("B")->getSymbol()=="B"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    try{
        map->getKey("Z");
        std::cout << "failed" << std::endl;
        fails++;
    }catch(std::invalid_argument e){
        std::cout << "passed" << std::endl;
        passes++;
    }

    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

int main(){
    try {
        testSound();
    }catch(std::exception){
        std::cout << "Error while testing class Sound" << std::endl;
    }

    try {
        testSoundMap();
    }catch(std::exception){
        std::cout << "Error while testing class SoundMap" << std::endl;
    }


    return 0;
}