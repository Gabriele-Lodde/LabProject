cmake_minimum_required(VERSION 3.30)
project(Lab_Project)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES Note.cpp
        Note.h
        Collection.cpp
        Collection.h
        Observer.h
        Subject.h
        CollectionSizeObserver.cpp
        CollectionSizeObserver.h)
add_executable(Lab_Project main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Lab_Project core)
add_subdirectory(test)