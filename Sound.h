//
// Created by Amelia Chady on 11/27/2018.
//

#ifndef INC_220GROUPPROJECT_SOUND_H
#define INC_220GROUPPROJECT_SOUND_H

#include <iostream>

class Sound{
private:
    std::string symbol;

    Sound(const Sound& soundToCopy);
    Sound& operator=(const Sound& soundToCopy);
    Sound();
public:
    Sound(std::string symbol);

    void AddConnection(Sound& connectedSound);

    std::string getSimilar();
    Sound getSimilarSound();

    std::string getSymbol();
};

#endif //INC_220GROUPPROJECT_SOUND_H
