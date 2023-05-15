cmake_minimum_required(VERSION 3.24)
project(cs180_21_taso6)

set(CMAKE_CXX_STANDARD 14)
set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.81.0_1/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.81.0_1/lib)
find_package(Boost 1.73.0)
include_directories(${Boost_INCLUDE_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

include_directories(backend)
include_directories(UI)

add_executable(cs180_21_taso6
       # backend/collection.cpp
       # backend/collection.h
        #backend/Initialize.cpp
        #backend/Initialize.h
        backend/parse.h
        backend/User.cpp
        backend/User.h
        UI/accountMenu.h
        UI/accountSystem.cpp
        UI/accountSystem.h
        main.cpp backend/bird_record.h backend/bird_record.cpp)
