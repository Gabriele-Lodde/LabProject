cmake_minimum_required(VERSION 3.30)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include lib/googletest/googlemock/include)

set(SOURCE_TEST_FILES runAllTests.cpp TestCollection.cpp TestNote.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core pthread)