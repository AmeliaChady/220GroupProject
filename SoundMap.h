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
    /**
     * Constructor, using the default SoundMap loading file: "defaultSounds.txt"
     */
    SoundMap() {};
    /**
     * Constructs ArraySoundMap off the passed fileName
     * @param fileName name of the file to load
     */
    SoundMap(std::string fileName) {};
    /**
     * Destructor
     * Deletes its Sound objects
     */
    virtual ~SoundMap() {};

    /**
     * Loads and reads the file given to soundMap
     * @throws std::exception if the file does not exist
     */
    virtual void read()=0;

    /**
     * @returns the fileName used to construct the SoundMap
     */
    virtual std::string getFileName()=0;
    /**
    * Returns the Sound object connected to the key
    * @param key ASCii Representation of an IPA Character described
    * @returns The connected SoundObject
    * @throws std::invalid_argument if the key doesn't exist
    */
    virtual Sound* getKey(std::string key)=0;
};

#endif //INC_220GROUPPROJECT_SOUNDMAP_H
