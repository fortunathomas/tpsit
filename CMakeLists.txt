cmake_minimum_required(VERSION 4.3)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled es2/main.cpp
        es2/classi/Personaggio.cpp
        es2/classi/Personaggio.h
        es2/classi/Mago.cpp
        es2/classi/Mago.h
        es2/classi/Arciere.cpp
        es2/classi/Arciere.h
        es2/classi/Guerriero.cpp
        es2/classi/Guerriero.h)
