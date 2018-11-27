//
// Created by Amelia Chady on 11/27/2018.
//

#ifndef INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
#define INC_220GROUPPROJECT_ARRAYSOUNDMAP_H

#include "SoundMap.h"

class ArraySoundMap : public SoundMap{
private:
    std::string fileName;

    ArraySoundMap(const ArraySoundMap& arraySoundMapToCopy);
    ArraySoundMap& operator=(const SoundMap& arraySoundMapToCopy);

public:
    ArraySoundMap();
    ArraySoundMap(std::string fileName);
    ~ArraySoundMap();

    std::string getFileName();
    Sound* getKey(std::string key);

};


#endif //INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
