cmake_minimum_required(VERSION 3.24)
project(voronoi)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(voronoi
        src/distPred.h
        src/graphe.cpp
        src/graphe.h
        src/main.cpp)
