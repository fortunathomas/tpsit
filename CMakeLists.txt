cmake_minimum_required(VERSION 4.3)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        es4/main.cpp
        es4/classi/Notifica.cpp
        es4/classi/Notifica.h
        es4/classi/NotificaEmail.cpp
        es4/classi/NotificaEmail.h
        es4/classi/NotificaSMS.cpp
        es4/classi/NotificaSMS.h
        es4/classi/NotificaPush.cpp
        es4/classi/NotificaPush.h
        es4/classi/GestoreNotifiche.cpp
        es4/classi/GestoreNotifiche.h
)
