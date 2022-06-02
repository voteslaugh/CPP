cmake_minimum_required(VERSION 3.22)
project(Server)

set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR C:\\Users/usual\\Documents/Code\\C++/.libraries\\SFML-2.5.1/lib\\cmake/SFML)

find_package(SFML 2.5 COMPONENTS network REQUIRED)

add_executable(Server main.cpp User.h)

target_link_libraries(Server sfml-network sfml-graphics)

