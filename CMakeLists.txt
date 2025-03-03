cmake_minimum_required(VERSION 3.10)
project(Cornpiler C)

set(CMAKE_C_STANDARD 11)

# Suppress `-Wunused-parameter` while keeping other warnings
set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-parameter -g")

include_directories(Misc/H_Files Parser/H_Files Lexer/H_Files)

file(GLOB SOURCES "Misc/C_Files/*.c" "Parser/C_Files/*.c" "Lexer/C_Files/*.c")

add_executable(output ${SOURCES})

# Define the executable

# Custom target to clear the terminal before running the program
add_custom_target(run
    COMMAND clear && ./output
    DEPENDS output
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)