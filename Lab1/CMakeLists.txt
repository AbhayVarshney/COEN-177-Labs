cmake_minimum_required(VERSION 3.8)
project(Lab1)

set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES main.c)
#add_executable(Lab1 ${SOURCE_FILES})

set(BUILD_1 main)
set(SOURCE_FILES_1 lab_1.c lab_2.c lab_3.c lab_4.c)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 main_2)
set(SOURCE_FILES_2 helloworld.c)
add_executable(${BUILD_2} ${SOURCE_FILES_2})
