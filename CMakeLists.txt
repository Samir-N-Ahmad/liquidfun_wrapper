cmake_minimum_required(VERSION 3.9.1)


set(LIB_NAME FLiquidFun)
set(LIB_VERSION 0)
set(LIB_SO_VERSION 1)

# set c++ 17 as default
set (CMAKE_CXX_STANDARD 17)
project(${LIB_NAME})

# another library for testing
add_library(${LIB_NAME} SHARED 
    ${CMAKE_SOURCE_DIR}/include/LiquidFunAPI.cpp
    ${CMAKE_SOURCE_DIR}/include/LiquidFunAPI.h)

# set library version
set_target_properties(${LIB_NAME} PROPERTIES VERSION ${LIB_VERSION})
set_target_properties(${LIB_NAME} PROPERTIES SOVERSION ${LIB_SO_VERSION})

# set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/LiquidFunAPI.h)


#include liquid fun static library with it's includes
# add_library(EXT_LIQUID_FUN SHARED IMPORTED)
add_library(LiquidFunEngine STATIC 
${CMAKE_SOURCE_DIR}/src/engine/LiquidFunEngine.cpp
${CMAKE_SOURCE_DIR}/src/engine/LiquidFunEngine.h
${CMAKE_SOURCE_DIR}/src/engine/widgets/BaseWidget.h
${CMAKE_SOURCE_DIR}/src/engine/widgets/BaseWidget.cpp
${CMAKE_SOURCE_DIR}/src/engine/widgets/CircleWidget.h
${CMAKE_SOURCE_DIR}/src/engine/widgets/CircleWidget.cpp
# utils
${CMAKE_SOURCE_DIR}/src/utils/Utils.h
${CMAKE_SOURCE_DIR}/src/utils/Utils.cpp
)



include_directories(${LIB_NAME} PUBLIC  ${CMAKE_SOURCE_DIR}/external/liquidfun)
target_link_libraries(${LIB_NAME}  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/external/liquidfun/Box2D/Debug/libliquidfun.a)
target_link_libraries(${LIB_NAME}  PUBLIC LiquidFunEngine)

#include the libraries includedirectory
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/engine)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/utils)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# for testing purposes only
add_executable(testing
        ${CMAKE_SOURCE_DIR}/tests/main.cpp
)
target_link_libraries(testing PUBLIC ${LIB_NAME})


install (TARGETS ${LIB_NAME}
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib
         RUNTIME DESTINATION bin)