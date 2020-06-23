cmake_minimum_required(VERSION 3.15)
project(acnl_player)

set(CMAKE_CXX_STANDARD 17)

add_executable(acnl_player main.cpp audioPlayer.cpp fileManager.cpp fileManager.h)

find_library(acnl_player libao)
find_library(acnl_player mpg123)