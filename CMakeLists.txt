cmake_minimum_required(VERSION 3.15)
project(acnl_player)

set(CMAKE_CXX_STANDARD 17)

#Qt5 stuff
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(PkgConfig REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

pkg_search_module(AO REQUIRED)
pkg_search_module(Qt5 REQUIRED)

add_library(mpg123 SHARED IMPORTED)
set_target_properties(mpg123 PROPERTIES IMPORTED_LOCATION  /usr/local/lib/libmpg123.so)

add_compile_options(-lmpg123 -lao)
include_directories(${AO_INCLUDE_DIRS} ${mpg123_INCLUDE_DIRS})
add_executable(acnl_player src/main.cpp src/audioPlayer.cpp src/fileManager.cpp src/fileManager.h src/audioPlayer.h)

target_link_libraries(acnl_player ${AO_LIBRARIES} mpg123 Qt5::Widgets)