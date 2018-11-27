//
// Created by Amelia Chady on 11/27/2018.
//

#include "Sound.h"
#include "LinkedList.h"

Sound::Sound(std::string symbol) {
    this->symbol = symbol;
    //TODO: Change to ArrayList
    this->connectedSounds = new LinkedList<Sound>();
}