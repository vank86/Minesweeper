cmake_minimum_required(VERSION 3.24)
project(Minesweeper_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Minesweeper_1 main.cpp MinesweeperBoard.cpp MinesweeperBoard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h)
