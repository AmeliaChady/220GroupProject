//
// Created by Amelia Chady on 11/27/2018.
//

#include "Sound.h"
#include "LinkedList.h"


Sound::Sound(std::string symbol) {
    this->symbol = symbol;
    //TODO: Change to ArrayList
    this->connectedSounds = new LinkedList<Sound*>();
}

Sound::~Sound() {

}

void Sound::addConnectionSecondary(Sound &connectedSound) {

}

void Sound::addConnection(Sound *connectedSound) {

}

std::string Sound::getSimilarSymbol() {
    return "getSimilarSymbol() not created";
}

std::string Sound::getSymbol() {
    return "getSymbol not created";
}

void Sound::lock() {

}
