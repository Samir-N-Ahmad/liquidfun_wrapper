

#include "Utils.h"


float** Utils::worldPostionsToDynamicArray(std::vector<std::vector<float>>& list){
    unsigned long arraySize = list.size();
    float** postions = new float*[arraySize + 1]();
    
    int i = 0;
    // embed first element as the array's size
    float floatedSize = float(arraySize);
    postions[i++] = &floatedSize;
    for(std::vector<float>& postion : list) {
        postions[i++] =  Utils::toDynamicArray<float>(postion);
    }

    return postions;
}
