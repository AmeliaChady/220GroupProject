//
// Created by Amelia Chady on 11/27/2018.
// Am implementation of SoundMap that uses arrays.
//

#ifndef INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
#define INC_220GROUPPROJECT_ARRAYSOUNDMAP_H

#include "SoundMap.h"
#include "List.h"

class ArraySoundMap : public SoundMap{
private:
    std::string fileName;
    List<Sound*>* soundArray;

    ArraySoundMap(const ArraySoundMap& arraySoundMapToCopy);
    ArraySoundMap& operator=(const SoundMap& arraySoundMapToCopy);
    

public:
    /**
     * Constructor, using the default SoundMap loading file: "defaultSounds.txt"
     */
    ArraySoundMap();
    /**
     * Constructs ArraySoundMap off the passed fileName
     * @param fileName name of the file to load
     */
    ArraySoundMap(std::string fileName);
    /**
     * Destructor
     * Deletes its Sound objects
     */
    ~ArraySoundMap();
    /**
     * Loads and reads the file given to soundMap
     * @throws std::exception if the file does not exist
     */
    void read();

    /**
     * @returns the fileName used to construct the SoundMap
     */
    std::string getFileName();
    /**
     * Returns the Sound object connected to the key
     * @param key ASCii Representation of an IPA Character described
     * @returns The connected SoundObject
     * @throws std::invalid_argument if the key doesn't exist
     */
    Sound* getKey(std::string key);

};


#endif //INC_220GROUPPROJECT_ARRAYSOUNDMAP_H
