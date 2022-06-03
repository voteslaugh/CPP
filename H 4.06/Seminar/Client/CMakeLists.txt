cmake_minimum_required(VERSION 3.22)
project(Client)

set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR C:\\Users/usual\\Documents/Code\\C++/.libraries\\SFML-2.5.1/lib\\cmake/SFML)

find_package(SFML 2.5 COMPONENTS network REQUIRED)

add_executable(Client main.cpp functions.h)

target_link_libraries(Client sfml-network sfml-graphics)

