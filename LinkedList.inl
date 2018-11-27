//
// Created by Toby Dragon on 10/30/18.
//

#include <iostream>
#include "LinkedList.h"


template <class T> // O(1)
LinkedList<T>::LinkedList(){
    front = nullptr;
    end = nullptr;
    numItems = 0;
}

template <class T> // O(n)
LinkedList<T>::~LinkedList(){
    while(front != nullptr){
        LinkedNode<T>* temp = front->getNext();
        delete front;
        front = temp;
    }
}

template <class T> // O(n)
T LinkedList<T>::getValueAt(int index){
    emptyTest();
    indexTest(index, false);

    LinkedNode<T>* current = front;
    for(int i = index; i > 0; i--){
        current = current->getNext();
    }
    return current->getItem();
}

template <class T> // O(n)
std::string LinkedList<T>::toString(){
    std::string strRep = "{";
    LinkedNode<T>* next = front;
    while(next != nullptr){
        if(next != front){
            strRep += ", ";
        }
        strRep += "this doesn't work?"; //std::to_string(next->getItem());
        next = next->getNext();
    }
    strRep += "}";
    return strRep;
}

template <class T> // O(1)
bool LinkedList<T>::isEmpty(){
    return front == nullptr;
}

template <class T> // O(1)
int LinkedList<T>::itemCount(){
    return numItems;
}

template <class T> // O(n)
void LinkedList<T>::clearList(){
    while(front != nullptr){
        LinkedNode<T>* temp = front;
        front = front->getNext();
        delete temp;
    }
    numItems = 0;
}

template <class T> // O(n)
int LinkedList<T>::find(T itemToFind){
    int index = 0;
    LinkedNode<T>* next = front;
    while(next != nullptr){
        if(next->getItem() == itemToFind){
            return index;
        }
        next = next->getNext();
        index++;
    }
    return -1;
}

template <class T> // O(n)
int LinkedList<T>::findLast(T itemToFind){
    int findIndex = -1;
    int currIndex = 0;
    LinkedNode<T>* next = front;
    while(next != nullptr){
        if(next->getItem() == itemToFind){
            findIndex = currIndex;
        }
        next = next->getNext();
        currIndex++;
    }
    return findIndex;
}

template <class T> // O(n)
int LinkedList<T>::findMaxIndex(){
    emptyTest();
    T max = front->getItem();
    int maxIndex = 0;
    int currIndex = 1;
    LinkedNode<T>* next = front->getNext();
    while(next != nullptr){
        if(next->getItem() > max){
            max = next->getItem();
            maxIndex = currIndex;
        }
        currIndex++;
        next = next->getNext();
    }
    return maxIndex;
}

template <class T> // O(1)
void LinkedList<T>::insertAtFront(T itemToAdd){
    LinkedNode<T>* newFront = new LinkedNode<T>(itemToAdd);
    newFront->setNext(front);
    front = newFront;
    if(numItems == 0){
        end = front;
    }
    numItems++;
}

template <class T> // O(1)
void LinkedList<T>::insertAtEnd(T itemToAdd){
    if(numItems == 0){
        front = new LinkedNode<T>(itemToAdd);
        end = front;
    }
    else {
        end->setNext(new LinkedNode<T>(itemToAdd));
        end = end->getNext();
    }
    numItems++;
}

template <class T> // O(n)
void LinkedList<T>::insertAt(T itemToAdd, int index){
    if(index == 0){
        insertAtFront(itemToAdd);
    }else if(index == numItems){
        insertAtEnd(itemToAdd);
    }else{
        indexTest(index, true);
        LinkedNode<T>* last = nullptr;
        LinkedNode<T>* current = front;

        for(int i = 0; i < index; i++){
            last = current;
            current = current->getNext();
        }

        LinkedNode<T>* newItem = new LinkedNode<T>(itemToAdd);
        if(last!= nullptr){
            last->setNext(newItem);
        }else{
            front = newItem;
        }
        newItem->setNext(current);
        numItems++;
    }
}

template <class T> // O(n)
T LinkedList<T>::removeValueAtEnd(){
    emptyTest();
    T item;
    if(numItems != 1) {
        LinkedNode<T>* current = front;
        while (current->getNext() != end) {
            current = current->getNext();
        }
        item = end->getItem();
        delete end;
        current->setNext(nullptr);
        end = current;
    }else{
        item = front->getItem();
        delete front;
        front = nullptr;
        end = nullptr;
    }
    numItems--;
    return item;
}

template <class T> // O(1)
T LinkedList<T>::removeValueAtFront(){
    emptyTest();

    T item = front->getItem();
    LinkedNode<T>* temp = front ->getNext();
    delete front;
    front = temp;

    numItems--;
    return item;
}

template <class T> // O(n)
T LinkedList<T>::removeValueAt(int index){
    emptyTest();
    indexTest(index, false);

    if(index == 0){
        return removeValueAtFront();
    }else if(index == numItems-1){
        return removeValueAtEnd();
    }else{
        LinkedNode<T>* last = nullptr;
        LinkedNode<T>* current = front;

        for(int i = 0; i < index; i++){
            last = current;
            current = current->getNext();
        }

        LinkedNode<T>* temp = current->getNext();
        T item = current->getItem();

        last->setNext(temp);
        delete current;

        numItems--;
        return item;
    }
}

template <class T> // O(1)
void LinkedList<T>::indexTest(int index, bool allowNumItems){
    if(allowNumItems && (index < 0 || index > numItems)){
        throw std::out_of_range("Index is out of range!");
    }
    else if(!allowNumItems && (index < 0 || index >= numItems)){
        throw std::out_of_range("Index is out of range!");
    }

}

template <class T> // O(1)
void LinkedList<T>::emptyTest() {
    if (this->isEmpty()) {
        throw std::out_of_range("List is empty!");
    }
}
