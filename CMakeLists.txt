cmake_minimum_required(VERSION 3.6)
project(Final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Atom.cpp src/Atom.h src/Runtime.cpp src/Runtime.h src/VarEnv.cpp src/VarEnv.h src/Code.cpp src/Code.h src/Function.cpp src/Function.h src/Data.cpp src/Data.h src/Integer.cpp src/Bool.cpp)
add_executable(Final ${SOURCE_FILES})