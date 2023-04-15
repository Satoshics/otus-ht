cmake_minimum_required(VERSION 3.12)

project(01.hello_world)

add_executable(hello_world 
    move_me_out.cpp
    move_me_out.h
    hello_world.cpp
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)