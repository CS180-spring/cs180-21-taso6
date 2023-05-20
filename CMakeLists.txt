cmake_minimum_required(VERSION 3.24)
project(cs180_21_taso6)

set(CMAKE_CXX_STANDARD 14)

include_directories(backend)
include_directories(UI)

add_executable(cs180_21_taso6
        backend/collection.cpp
        backend/collection.h
        backend/Initialize.cpp
        backend/Initialize.h
        backend/parse.h
        backend/User.cpp
        backend/User.h
        UI/accountMenu.h
        UI/accountSystem.cpp
        UI/accountSystem.h
        main.cpp backend/bird_record.h backend/bird_record.cpp)
