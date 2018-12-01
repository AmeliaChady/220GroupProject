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

    // Test 1
    if(trim("  a") == "a"){

    }else{

    }



    // Test 2


    // Test 3


    //


    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

void splitTest(){

}

int main(){
    std::string lazyTest = "    a b c  d    \n";
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
    delete lazyTest3;

    return 0;
}