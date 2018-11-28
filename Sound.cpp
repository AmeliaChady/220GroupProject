//
// Created by Amelia Chady on 11/27/2018.
//

#include "Sound.h"
#include "LinkedList.h"


Sound::Sound(std::string symbol) {
    this->symbol = symbol;
    //TODO: Change to ArrayList
    connectedSounds = new LinkedList<Sound*>();
    locked = false;
}

Sound::~Sound() {
    delete connectedSounds;
}

void Sound::addConnectionSecondary(Sound* connectedSound) {
    if(locked){
        throw std::exception();
    }
    connectedSounds->insertAtEnd(connectedSound);
}

void Sound::addConnection(Sound* connectedSound) {
    if(locked){
        throw std::exception();
    }
    connectedSounds->insertAtEnd(connectedSound);
    connectedSound->addConnectionSecondary(this);
}

std::string Sound::getSimilarSymbol() {
    if(connectedSounds->isEmpty()){
        throw std::out_of_range("No Similar Symbols!");
    }
    int index = rand() % connectedSounds->itemCount();
    return connectedSounds->getValueAt(index)->getSymbol();

}

std::string Sound::getSymbol() {
    return symbol;
}

void Sound::lock() {
    locked = true;
}

bool Sound::getLocked() {
    return locked;
}
