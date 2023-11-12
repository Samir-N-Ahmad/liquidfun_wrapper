

#include "Utils.h"


float** Utils::worldPostionsToDynamicArray(std::vector<std::vector<float>>& list){
    float** postions = new float*();
    
    int i = 0;
    
    for(std::vector<float>& postion : list) {
        std::cout << "positon " << i <<  " "  << postion[i] << std::endl;
        postions[i++] =  Utils::toDynamicArray<float>(postion);

    }

    return postions;
}
