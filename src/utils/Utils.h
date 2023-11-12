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
        unsigned long listSize = sizeof(list);
        if(listSize == 0){
            return nullptr;
        }
        T* dynamicArray = new T();
        int iterator = 0;
        for(T& item : list){
            std::cout <<"item : " << item << std::endl;
            dynamicArray[iterator++] = item;
        }
        return dynamicArray;
    }
};


#endif
