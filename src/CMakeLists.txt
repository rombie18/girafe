cmake_minimum_required(VERSION 3.21)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
        pugiconfig.hpp
        pugixml.cpp
        pugixml.hpp SensorNode.h Vertex.h Edge.h Graph.cpp)
