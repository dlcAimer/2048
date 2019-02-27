cmake_minimum_required(VERSION 3.9)
project(2048)

set(CMAKE_CXX_STANDARD 11)

add_executable(2048 main.cpp Game.cpp Game.h Board.cpp Board.h Timer.cpp Timer.h Record.cpp Record.h Cheat.cpp Cheat.h kbhit.cpp kbhit.h Ai.cpp Ai.h)