cmake_minimum_required(VERSION 4.3)
project(tpsit)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(tpsit
        computer.h
        GestionePC.h
        Program.cpp)
