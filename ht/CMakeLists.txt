cmake_minimum_required(VERSION 3.12)

project(02.guess_the_num)

add_executable(guess_the_num 
    game.cpp
    filewriter.cpp
    levels.cpp
    rand.cpp
)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
target_compile_options(calc PRIVATE
-g
-Wall
-Wextra
-Werror
-pedantic
)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_compile_options(calc PRIVATE
/EHsc
/W4
/WX
)
endif()
set_target_properties(guess_the_num PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)