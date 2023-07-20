cmake_minimum_required(VERSION 3.12)

project(02.working_wtih_files)

add_executable(working_wtih_files
    game.cpp
    file.cpp
    levels.cpp
    rand.cpp
    includes.h
)
set_target_properties(working_wtih_files PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)