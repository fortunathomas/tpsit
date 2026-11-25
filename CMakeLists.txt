cmake_minimum_required(VERSION 4.3)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled 
        es3/main.cpp
        es3/classi/MetodoPagamento.cpp
        es3/classi/MetodoPagamento.h
        es3/classi/CartaCredito.cpp
        es3/classi/CartaCredito.h
        es3/classi/PayPal.cpp
        es3/classi/PayPal.h
        es3/classi/Contanti.cpp
        es3/classi/Contanti.h)
