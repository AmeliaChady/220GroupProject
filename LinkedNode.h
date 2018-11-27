//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

template <class T>
class LinkedNode {

private:
    T item;
    LinkedNode<T>* next;

public:
    LinkedNode<T>(T item);
    LinkedNode<T>(const LinkedNode<T>& nodeToCopy); //only copies item, next is set to nullptr
    virtual T getItem();
    virtual LinkedNode<T>* getNext();
    virtual void setItem(T newItem);
    virtual void setNext(LinkedNode<T>* newNext);
};

#include "LinkedNode.inl"

#endif //LINKEDNODE_H
