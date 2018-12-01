//
// Created by Amelia Chady on 11/30/2018.
//
#include <string>
#include <iostream>
#include "Util.h"

void trimTest(){
    std::cout << "--Trim Tests--------" << std::endl;
    int passes = 0;
    int fails = 0;

    if(trim("  a") == "a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim("a  ") == "a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim("  a  ") == "a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim("\r  a  \r") == "a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim("\n  a  \n") == "a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim(" a a  ") == "a a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim(" ") == ""){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(trim("") == ""){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }


    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

//TODO: Finish tests
void splitTest(){
    std::cout << "--Split Tests--------" << std::endl;
    int passes = 0;
    int fails = 0;

    std::string testString = " a b c ";
    List<std::string>* list = split(testString, " ");
    if(list->getValueAt(0)=="a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    testString = "0a0b0c0";
    delete list;
    list = split(testString, "0");
    if(list->getValueAt(0)=="a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    testString = "01a01b01c01";
    delete list;
    list = split(testString, "01");
    if(list->getValueAt(0)=="a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    testString = "abc";
    delete list;
    list = split(testString, "");
    if(list->getValueAt(0)=="abc"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    testString = "01a01b01c01";
    delete list;
    list = split(testString, "01");
    if(list->getValueAt(0)=="a"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }





    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

int main(){
    trimTest();
    splitTest();

    /*std::string lazyTest = "    a b c  d    \n";
    std::string lazyTest2 = trim(lazyTest);
    List<std::string>* lazyTest3 = split(lazyTest2, " ");

    std::cout << lazyTest << std::endl;
    std::cout << lazyTest2 << std::endl;

    std::cout << "[";
    std::cout << lazyTest3->getValueAt(0);
    for(int i = 1; i < lazyTest3->itemCount(); i++){
        std::cout << ", " << lazyTest3->getValueAt(i);
    }
    std::cout << "]" << std::endl;

    std::cout << "DONE" << std::endl;
    delete lazyTest3;*/

    return 0;
}