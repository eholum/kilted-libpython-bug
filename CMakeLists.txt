cmake_minimum_required(VERSION 3.22)
project(kilted-libpython-bug)

find_package(ament_cmake REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(Eigen3 REQUIRED)

# This links against tf2_eigen, which transitively pulls in
# _rosidl_generator_py.so libraries that are missing libpython linkage.
add_executable(tf2_eign_bug src/main.cpp)
target_link_libraries(tf2_eign_bug ${tf2_eigen_TARGETS})
set_property(TARGET tf2_eign_bug PROPERTY CXX_STANDARD 17)

install(TARGETS tf2_eign_bug DESTINATION bin)
ament_package()
