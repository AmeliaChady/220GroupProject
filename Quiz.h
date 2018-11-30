//
// Created by Timothy Marotta on 11/30/18.
//

#ifndef INC_220GROUPPROJECT_QUIZ_H
#define INC_220GROUPPROJECT_QUIZ_H

#include <string>

class Quiz {
private:
    /*
     * asks for Question object to be made
     * @returns Question object temp void
     */
    virtual void makeQuestion(std::string word)=0;

public:
    //destructor to be declared in child classes
    virtual ~Quiz()=0;

    /*
     * @input takes word passed from ListOfWords
     * @returns Question object (currently void bc class doesn't exist yet
     *
     */
    virtual void genQuestion(std::string word)=0;



};
#endif //INC_220GROUPPROJECT_QUIZ_H
