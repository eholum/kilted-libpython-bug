cmake_minimum_required(VERSION 3.22)
project(kilted-libpython-bug)

find_package(ament_cmake REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(geometry_msgs REQUIRED)

# Shared library that links tf2_eigen
add_library(tf2_wrapper_lib SHARED src/lib.cpp)
target_link_libraries(tf2_wrapper_lib PUBLIC ${tf2_eigen_TARGETS})
target_include_directories(tf2_wrapper_lib PUBLIC include)

# Test executable that links the shared library
add_executable(tf2_eigen_bug src/main.cpp)
target_link_libraries(tf2_eigen_bug tf2_wrapper_lib)

install(TARGETS tf2_wrapper_lib DESTINATION lib)
install(TARGETS tf2_eigen_bug DESTINATION bin)
ament_package()
