//
// Created by Amelia Chady on 11/27/2018.
// An object that represents an IPA sound, that allows a user to get similar IPA symbols
//

#ifndef INC_220GROUPPROJECT_SOUND_H
#define INC_220GROUPPROJECT_SOUND_H

#include <iostream>
#include "List.h"

class Sound{
private:
    std::string symbol;
    List<Sound*>* connectedSounds;

    Sound(const Sound& soundToCopy);
    Sound& operator=(const Sound& soundToCopy);
    Sound();

    /**
     * Connects a Sound to this sound.
     * @param connectedSound the sound to connect to.
     */
    void addConnectionSecondary(Sound* connectedSound);
public:
    /**
     * Constructs a Sound Object
     * @param symbol the symbol representing the sound object
     */
    Sound(std::string symbol);

    //Destructor
    ~Sound();

    /**
     * Connects the two sound objects together
     * @param connectedSound the other sound to connect to
     */
    void addConnection(Sound* connectedSound);

    /**
     * Randomly gets a similar sound
     * @return The symbol of that Sound
     * @throws std::out_of_range when there are no connected Sounds
     */
    std::string getSimilarSymbol();
    /**
     * Get the symbol of this Sound
     * @return the symbol
     */
    std::string getSymbol();
};

#endif //INC_220GROUPPROJECT_SOUND_H
