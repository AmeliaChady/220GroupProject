//
// Created by Amelia Chady on 11/27/2018.
//

#ifndef INC_220GROUPPROJECT_SOUND_H
#define INC_220GROUPPROJECT_SOUND_H

#include <iostream>

class Sound{
private:
    std::string symbol;
    //List<Sound> connectedSounds;

    Sound(const Sound& soundToCopy);
    Sound& operator=(const Sound& soundToCopy);
    Sound();

    /**
     * Connects a Sound to this sound.
     * @param connectedSound the sound to connect to.
     */
    void AddConnectionSecondary(Sound& connectedSound);
public:
    /**
     * Constructs a Sound Object
     * @param symbol the symbol representing the sound object
     */
    Sound(std::string symbol);

    /**
     * Connects the two sound objects together
     * @param connectedSound the other sound to connect to
     */
    void AddConnection(Sound& connectedSound);

    /**
     * Randomly gets a similar sound
     * @return The symbol of that Sound
     */
    std::string getSimilar();
    /**
     * Randomly gets a similar sound
     * @return that Sound
     */
    Sound getSimilarSound();

    /**
     * Get the symbol of this Sound
     * @return the symbol
     */
    std::string getSymbol();
};

#endif //INC_220GROUPPROJECT_SOUND_H
