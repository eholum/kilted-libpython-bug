cmake_minimum_required(VERSION 3.22)
project(kilted-libpython-bug)

find_package(ament_cmake REQUIRED)

add_executable(symbol_bug src/main.cpp)
install(TARGETS symbol_bug DESTINATION bin)
ament_package()

