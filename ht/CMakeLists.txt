cmake_minimum_required(VERSION 3.12)

project(02.guess_the_num)

add_executable(guess_the_num 
    game.cpp
    filewriter.cpp
    levels.cpp
    rand.cpp
)

set_target_properties(guess_the_num PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)