cmake_minimum_required(VERSION 3.12)

project(02.working_wtih_files)

add_executable(working_wtih_files
    includes.h
    game.cpp
    file.cpp
    levels.cpp
    rand.cpp
    class.cpp
)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
target_compile_options(working_wtih_files PRIVATE
-g
-Wall
-Wextra
-pedantic
)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_compile_options(working_wtih_files PRIVATE
/EHsc
/W4
)
endif()
set_target_properties(working_wtih_files PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)