cmake_minimum_required(VERSION 3.20)
project(ESE224_Midterm_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ESE224_Midterm_Project
        enemy.cpp
        enemy.h
        FileOperations.cpp
        FileOperations.h
        functions.h
        main.cpp
        player.cpp
        player.h
        scoreboard.cpp
        scoreboard.h
        weapon.cpp
        weapon.h)
