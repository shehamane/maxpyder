cmake_minimum_required(VERSION 3.0)
project(Chess)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ChessLib
        app/lib/games/chess/src/lib/GameController.h
        app/lib/games/chess/src/lib/GameController.cpp
        app/lib/games/chess/src/lib/Board.h
        app/lib/games/chess/src/lib/Board.cpp
        app/lib/games/chess/src/lib/Player.h
        app/lib/games/chess/src/lib/Player.cpp
        app/lib/games/chess/src/lib/BoardBuilder.h
        app/lib/games/chess/src/lib/BoardBuilder.cpp
        app/lib/games/chess/src/lib/Cell.h
        app/lib/games/chess/src/lib/Cell.cpp
        app/lib/games/chess/src/lib/Move.h
        app/lib/games/chess/src/lib/Move.cpp
        app/lib/games/chess/src/lib/Figure.h
        app/lib/games/chess/src/lib/Figure.cpp
        app/lib/games/chess/src/lib/Piece.h
        app/lib/games/chess/src/lib/utils.cpp)

add_executable(ChessApp app/lib/games/chess/src/main.cpp)
target_link_libraries(ChessApp PUBLIC ChessLib)
