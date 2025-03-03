cmake_minimum_required(VERSION 3.10)
project(Cornpiler C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra")

include_directories(Misc/H_Files Parser/H_Files Lexer/H_Files)

file(GLOB SOURCES "Misc/C_Files/*.c" "Parser/C_Files/*.c" "Lexer/C_Files/*.c")

add_executable(output ${SOURCES})