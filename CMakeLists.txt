cmake_minimum_required(VERSION 3.0)
project(Chess)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Chess app/lib/games/chess/main.cpp)