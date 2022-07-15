cmake_minimum_required(VERSION 3.12)
project(rpg CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# Put Your .cpp files in line below
add_executable(rpg src/main.cpp src/RpgCommands.cpp src/RpgViewer.cpp src/RpgControl.cpp src/Arena.cpp src/Monsters.cpp)
target_include_directories(rpg PUBLIC include)


# If You want to write some tests...
option(USE_GTEST "Download compile and provide gtest/gmock" OFF)

