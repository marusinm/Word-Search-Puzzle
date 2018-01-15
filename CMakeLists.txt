cmake_minimum_required(VERSION 3.7)
project(assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Wall -Werror -Wextra -pedantic -pthread ")

#set(SOURCE_FILES main.c task1.h task2.h task3.h task4.h task5.h task6.h task7.h)
set(SOURCE_FILES main.c deck.h deck.c)
add_executable(mini_assingnment ${SOURCE_FILES})
