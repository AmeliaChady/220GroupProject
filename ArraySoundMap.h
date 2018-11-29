//
// Created by Amelia Chady on 11/27/2018.
//

#ifndef INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
#define INC_220GROUPPROJECT_ARRAYSOUNDMAP_H

#include "SoundMap.h"
#include "List.h"

class ArraySoundMap : public SoundMap{
private:
    std::string fileName;
    List<Sound*>* soundArray;
    int soundArrayLength;

    ArraySoundMap(const ArraySoundMap& arraySoundMapToCopy);
    ArraySoundMap& operator=(const SoundMap& arraySoundMapToCopy);

public:
    ArraySoundMap();
    ArraySoundMap(std::string fileName);
    ~ArraySoundMap();

    void read();

    std::string getFileName();
    Sound* getKey(std::string key);

};


#endif //INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
