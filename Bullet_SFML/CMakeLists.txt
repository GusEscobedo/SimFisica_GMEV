cmake_minimum_required(VERSION 3.26)
project(Bullet_SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bullet_SFML main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(Bullet_SFML PRIVATE box2d::box2d)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Bullet_SFML PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
