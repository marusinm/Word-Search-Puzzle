cmake_minimum_required(VERSION 3.7)
project(assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Wall -Werror -Wextra -pedantic -pthread ")

set(SOURCE_FILES main.c deck.h deck.c wordgenerator.c wordgenerator.h)
add_executable(mini_assingnment ${SOURCE_FILES})
