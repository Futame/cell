cmake_minimum_required(VERSION 2.8)
project(CanineVentricularCellBeta)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

set(SOURCE_FILES main.cpp beta.h signalling.cpp signalling.h elphys.cpp elphys.h settings.cpp settings.h funsignalling.cpp funsignalling.h)
add_executable(CanineVentricularCellBeta ${SOURCE_FILES})