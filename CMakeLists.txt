cmake_minimum_required(VERSION 3.20)
project(Homework C)

set(CMAKE_C_STANDARD 99)

add_executable(Homework main.c head/Inquire.h head/Edit.h head/Statistics.h head/FileIO.h head/Input.h source/Inquire.c source/Edit.c source/FileIO.c source/Input.c source/Statistics.c)
