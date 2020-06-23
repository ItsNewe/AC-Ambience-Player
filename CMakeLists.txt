cmake_minimum_required(VERSION 3.15)
project(acnl_player)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)

pkg_search_module(AO REQUIRED)
#pkg_search_module(mpg123 REQUIRED)
add_library(mpg123 SHARED IMPORTED )
set_target_properties(mpg123 PROPERTIES IMPORTED_LOCATION  /usr/local/lib/libmpg123.so)

add_compile_options(${AO_CXXFLAGS} ${mpg123_CXXFLAGS})

include_directories(${AO_INCLUDE_DIRS} ${mpg123_INCLUDE_DIRS})
add_executable(acnl_player main.cpp audioPlayer.cpp fileManager.cpp fileManager.h audioPlayer.h)

target_link_libraries(acnl_player ${AO_LIBRARIES} mpg123)