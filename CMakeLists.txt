cmake_minimum_required(VERSION 3.0)
project(Chess)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ChessLib app/lib/games/chess/src/lib/GameController.cpp)

add_executable(ChessApp app/lib/games/chess/src/main.cpp)