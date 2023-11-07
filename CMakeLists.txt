cmake_minimum_required(VERSION 3.9.1)


set(LIB_NAME FLiquidFun)
set(LIB_VERSION 0)
set(LIB_SO_VERSION 1)

project(${LIB_NAME})

# another library for testing
add_library(${LIB_NAME} SHARED 
    ${CMAKE_SOURCE_DIR}/include/LiquidFunAPI.cpp)

# set library version
set_target_properties(${LIB_NAME} PROPERTIES VERSION ${LIB_VERSION})
set_target_properties(${LIB_NAME} PROPERTIES SOVERSION ${LIB_SO_VERSION})

# set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/LiquidFunAPI.h)



#include liquid fun static library with it's includes
# add_library(EXT_LIQUID_FUN SHARED IMPORTED)
add_library(LiquidFunEngine STATIC ${CMAKE_SOURCE_DIR}/src/engine/LiquidFunEngine.cpp)

include_directories(${LIB_NAME} PUBLIC  ${CMAKE_SOURCE_DIR}/external/liquidfun)
target_link_libraries(${LIB_NAME}  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/external/liquidfun/Box2D/Debug/libliquidfun.a)
target_link_libraries(${LIB_NAME}  PUBLIC LiquidFunEngine)

#include the libraries includedirectory
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

install (TARGETS ${LIB_NAME}
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib
         RUNTIME DESTINATION bin)