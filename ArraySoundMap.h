//
// Created by Amelia Chady on 11/27/2018.
//

#ifndef INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
#define INC_220GROUPPROJECT_ARRAYSOUNDMAP_H

#include "SoundMap.h"

class ArraySoundMap : SoundMap{
private:
    ArraySoundMap(const ArraySoundMap& arraySoundMapToCopy);
    ArraySoundMap& operator=(const SoundMap& arraySoundMapToCopy);

public:
    ArraySoundMap();
    ArraySoundMap(std::string fileName);
    ~ArraySoundMap();

    std::string getFileName();
    Sound getKey();

};


#endif //INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
