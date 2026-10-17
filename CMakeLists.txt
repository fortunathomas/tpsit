cmake_minimum_required(VERSION 4.3)
project(tpsit)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tpsit
        computer.cpp
        computer.h
        GestionePC.cpp
        GestionePC.h
        Program.cpp)
