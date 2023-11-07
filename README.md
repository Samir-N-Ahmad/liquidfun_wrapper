# liquidfun_wrapper
A C wrapper for the Google's liquidFun library. the wrapper will work as a bridge library to use LiquidFun in Flutter

## Build this library

    ### Run cmake

    cmake CmakeLists.txt -G "Xcode"

    if you have issues with the C and/or C++ compilers paths, you have 3 options:
        1- add the paths to your env variables
        2- set the paths in the cmakeLists.txt file
        3- set the paths using the cmake command option -D
            cmake CmakeLists.txt -G "Xcode" -D CMAKE_C_COMPILER={path-to-c-compiler} -D CMAKE_CXX_COMPILER={path-to-c++-compiler}
