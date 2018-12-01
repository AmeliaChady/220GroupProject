#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(){
    ArrayList<T>(1);
}

template <class T>
void ArrayList<T>::doubleCapacity(){
    T * arrayHolder = array;
    this->array = new T[currCapacity*2];
    for (int i = 0; i < currCapacity; ++i){
        this->array[i]= arrayHolder[i];
    }
    this->currCapacity = currCapacity * 2;
    delete[]arrayHolder;
    arrayHolder = NULL;
}

/**
 * Constructor
 * @throws an std::invalid_argument exception if size < 1
 */
template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
    if (initialCapacity < 1){
        throw std::invalid_argument("Size must be at least 1");
    }
    this->currCapacity = initialCapacity;
    this->array = new T [currCapacity];
    this->currItemCount = 0;
}

//Copy Constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayListToCopy){
    this->currCapacity = arrayListToCopy.currCapacity;
    this->currItemCount = arrayListToCopy.currItemCount;
    this->array = new T[currCapacity];
    for (int i = 0; i < currItemCount; ++i){
        array[i] = arrayListToCopy.array[i];
    }

}

//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
    delete[] this->array;
    this->currCapacity = arrayListToCopy.currCapacity;
    this->currItemCount = arrayListToCopy.currItemCount;
    this-> array = new T[arrayListToCopy.currCapacity];
    for (int i = 0; i < arrayListToCopy.currItemCount; ++i){
        array[i] = arrayListToCopy.array[i];
    }
    return *this;

}

template <class T>
//Destructor
ArrayList<T>::~ArrayList<T>(){
    if (array != nullptr){
        delete[] array;
        array = nullptr;
    }

}

template <class T>
void ArrayList<T>::replaceValue(T itemToAdd, int index) {
    this->array[index] = itemToAdd;
}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd){
    if (currItemCount >= currCapacity){
        doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount += 1;

}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
template <class T>
T ArrayList<T>::getValueAt(int index){
    if (index >= currItemCount || index < 0){
        throw std::out_of_range("Index out of range");
    }

    return array[index];
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */


template <class T>
std::string ArrayList<T>::toString(){
    if (currItemCount < 1){
        return "{}";

    }
    std::string completedString = "{";
    for (int i = 0; i < currItemCount - 1; ++i){
        completedString = completedString + std::to_string(array[i]);
        completedString = completedString + ", ";
    }
    completedString = completedString + std::to_string(array[currItemCount - 1]);
    completedString = completedString + "}";
    return completedString;
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
template <class T>
bool ArrayList<T>::isEmpty(){
    if (currItemCount < 1){
        return true;
    }
    else{
        return false;
    }

}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
template <class T>
int ArrayList<T>::itemCount(){
    return currItemCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
template <class T>
void ArrayList<T>::clearList(){
    array = new T[currCapacity];
    currItemCount = 0;
}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
template <class T>
int ArrayList<T>::find(T numToFind){
    for (int i = 0; i < currItemCount; ++i){
        if (array[i] == numToFind){
            return i;
        }
    }

    return -1;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
template <class T>
int ArrayList<T>::findLast(T numToFind){
    int indexToReturn = -1;
    for (int i = 0; i < currItemCount; ++i){
        if (array[i] == numToFind){
            indexToReturn = i;
        }
    }

    return indexToReturn;
}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value, or -1 if size < 1
 */
template <class T>
int ArrayList<T>::findMaxIndex(){
    if (currItemCount < 1){
        throw std::out_of_range("Size < 1");
    }
    T currMaxValue = array[0];
    int currMaxIndex = 0;
    for (int i = 0; i < currItemCount; ++i){
        if (array[i] > currMaxValue){
            currMaxValue = array[i];
            currMaxIndex = i;
        }
    }
    return currMaxIndex;

}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd){
    if (currItemCount >= currCapacity){
        doubleCapacity();
    }
    T* arrayHolder = array;
    array = new T[currCapacity];
    for (int i = 0; i < currItemCount; ++i){
        array[i + 1] = arrayHolder[i];
    }
    array[0] = itemToAdd;
    delete[] arrayHolder;
    currItemCount += 1;

}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index){

    if (index > currItemCount || index < 0){
        throw std::out_of_range("Index is invalid.");
    }


    if (currItemCount >= currCapacity){
        doubleCapacity();
    }
    T* arrayHolder = array;
    array = new T[currCapacity];
    for (int i = 0; i < index; ++i){
        array[i] = arrayHolder[i];
    }
    for (int i = index; i < currItemCount; ++i){
        array[i + 1] = arrayHolder[i];
    }
    array[index] = itemToAdd;
    currItemCount += 1;
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
template <class T>
T ArrayList<T>::removeValueAtEnd(){
    if (currItemCount < 1){
        throw std::out_of_range("No item to remove");
    }
    T toReturn = array[currItemCount -1];
    currItemCount -= 1;

    return toReturn;
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
template <class T>
T ArrayList<T>::removeValueAtFront(){
    if (currItemCount < 1){
        throw std::out_of_range("No item to remove");
    }
    T* arrayHolder = array;
    T toReturn = array[0];
    array = new T[currCapacity];
    for (int i = 1; i < currItemCount; ++i){
        array[i-1] = arrayHolder[i];
    }
    currItemCount -= 1;
    delete[] arrayHolder;

    return toReturn;
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
template <class T>
T ArrayList<T>::removeValueAt(int index){
    if(index >= currItemCount || index < 0){
        throw std::out_of_range("Index is out of range");
    }
    T toReturn = array[index];
    T* arrayHolder = array;
    array = new T[currCapacity];
    for (int i = 0; i < index; ++i){
        array[i] = arrayHolder[i];
    }
    for (int i = index; i < currItemCount-1; ++i){
        array[i] = arrayHolder[i + 1];
    }
    currItemCount -= 1;
    delete[] arrayHolder;

    return toReturn;
}