//
// Created by Amelia Chady on 11/27/2018.
//

#ifndef INC_220GROUPPROJECT_SOUNDMAP_H
#define INC_220GROUPPROJECT_SOUNDMAP_H

#include "iostream"
#include "Sound.h"

class SoundMap{
private:
    SoundMap(const SoundMap& soundMapToCopy);
    SoundMap& operator=(const SoundMap& soundMapToCopy);

public:
    SoundMap();
    SoundMap(std::string fileName);
    virtual ~SoundMap()=0;

    virtual std::string getFileName()=0;
    virtual Sound getKey(std::string key)=0;
};

#endif //INC_220GROUPPROJECT_SOUNDMAP_H
