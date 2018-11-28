//
// Created by Amelia Chady on 11/27/2018.
//

#include "ArraySoundMap.h"
#include <fstream>

ArraySoundMap::ArraySoundMap() {
    std::string currentLine;
    std::ifstream file;
    file.open("defaultSounds.txt");
    getline(file, currentLine);
    while(currentLine.substr(0, 2)=="//" || currentLine.length()==0){
        getline(file, currentLine);
    }
    soundArrayLength = std::stoi(currentLine);
    arr
}

ArraySoundMap::ArraySoundMap(std::string fileName) {

}

ArraySoundMap::~ArraySoundMap() {

}

std::string ArraySoundMap::getFileName() {
    return "not implemented";
}

Sound* ArraySoundMap::getKey(std::string key) {
}