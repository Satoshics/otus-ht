cmake_minimum_required(VERSION 3.12)

project(05.arrays)

add_executable(badvector
    badvector.cpp
    badvector/badvector.h
    badvector/badvector.ipp
)

set_target_properties(badvector PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

add_executable(badlist
    badlist.cpp
    badlist/badlist.h
    badlist/badlist.ipp
)

set_target_properties(badlist PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)