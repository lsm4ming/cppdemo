cmake_minimum_required(VERSION 3.27)
project(cppdemo)

# Turning off extensions avoids and issue with the clang 16 compiler
# clang 17 and greater can avoid this setting
set(CMAKE_CXX_EXTENSIONS OFF)
# Set the version of C++ for the project
set(CMAKE_CXX_STANDARD 23)

add_executable(cppdemo main.cpp my_string.cpp file_operation.cpp my_string.h file_operation.h
        common.h
        md5.cpp
        md5.h)

set(CRYPTO++_INCLUDE_DIR "/usr/include/crypto++")
set(CRYPTO++_LIBRARY "/usr/lib/x86_64-linux-gnu/libcrypto++.so")

include_directories(${CRYPTO++_INCLUDE_DIR})
target_link_libraries(cppdemo ${CRYPTO++_LIBRARY})