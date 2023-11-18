/*
// Utils.h
// Created nby Samir Ahmad
*/

#ifndef Utils_h
#define  Utils_h

#include <iostream>

class Utils {
    
    
public:
    static float** worldPostionsToDynamicArray(std::vector<std::vector<float>>&);
    
private:
    template<typename T> static T* toDynamicArray(std::vector<T>& list){
        //TODO
        // deal with the pointer
        unsigned long listSize = list.size();
        if(listSize == 0){
            return nullptr;
        }
        T* dynamicArray = new T[listSize + 1]();
        int iterator = 0;
        // embed the array's size as the first element
        dynamicArray[iterator++] = (T)listSize;
        for(T& item : list){
            dynamicArray[iterator++] = item;
        }
        return dynamicArray;
    }
};


#endif
