cmake_minimum_required(VERSION 3.30)
project(Lab_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_Project main.cpp
        Note.cpp
        Note.h
        Collection.cpp
        Collection.h
        Observer.h
        Subject.h
        CollectionSizeObserver.cpp
        CollectionSizeObserver.h)
