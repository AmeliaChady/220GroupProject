//
// Created by Amelia Chady on 11/27/2018.
//

#include "ArraySoundMap.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "Util.h"
#include <fstream>

ArraySoundMap::ArraySoundMap() {
    fileName = "defaultSounds.txt";
}

ArraySoundMap::ArraySoundMap(std::string fileName) {
    this->fileName = fileName;
}

ArraySoundMap::~ArraySoundMap() {

}

void ArraySoundMap::read() {
    std::string currentLine;
    std::ifstream file;
    file.open(fileName, std::ios::in);
    if(!file.is_open()){
        throw std::exception();
    }
    std::getline(file, currentLine);
    while(currentLine.substr(0, 2) == "//" || currentLine.substr(0, 2) == "\r" ){
        std::getline(file, currentLine);
    }
    //TODO: Change to Array List
    soundArray = new LinkedList<Sound*>(); // Make sure to add the currentLine size

    getline(file,currentLine);
    while(currentLine.substr(0, 1) != "#") {
        if (currentLine.substr(0, 2) != "//" && currentLine.substr(0, 2) != "\r") {
            soundArray->insertAtEnd(new Sound(trim(currentLine)));
        }
        getline(file, currentLine);
    }

    getline(file, currentLine);
    while(currentLine.substr(0, 1) != "#"){
        if (currentLine.substr(0, 2) != "//" && currentLine.substr(0, 2) != "\r") {
            List<std::string>* splitted = split(currentLine, " ");
            Sound* tempBase = getKey(splitted->getValueAt(0));
            for(int i = 1; i < splitted->itemCount(); i++) {
                tempBase->addConnection(getKey(splitted->getValueAt(i)));
            }
        }
        getline(file, currentLine);
    }

    file.close();
}

std::string ArraySoundMap::getFileName() {
    return "not implemented";
}

Sound* ArraySoundMap::getKey(std::string key) {
    for(int i = 0; i < soundArray->itemCount(); i++){
        Sound* temp = soundArray->getValueAt(i);
        if(temp->getSymbol()==key){
            return temp;
        }
    }
}