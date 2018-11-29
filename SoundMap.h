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
     * Constructs a SoundMap off of the default file
     * default file is <filename>
     */
    SoundMap() {};
    /**
     * Constructs a SoundMap off of the file called fileName.
     * @param fileName The files name
     */
    SoundMap(std::string fileName) {};
    // Destructor
    virtual ~SoundMap() {};

    virtual void read()=0;

    /**
     * Gets the fileName used to make the SoundMap
     * @return the files name
     */
    virtual std::string getFileName()=0;
    /**
     * Gets the Sound object held at key
     * @param key phonetic symbol of the Sound
     * @return the Sound connected with the key.
     * @throws std::invalid_argument if the key doesn't exist
     * @throws std::out_of_range if the map is empty
     */
    virtual Sound* getKey(std::string key)=0;
};

#endif //INC_220GROUPPROJECT_SOUNDMAP_H
