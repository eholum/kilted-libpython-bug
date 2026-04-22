cmake_minimum_required(VERSION 3.22)
project(kilted-libpython-bug)

find_package(ament_cmake REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(Eigen3 REQUIRED)

# This links against tf2_eigen, which transitively pulls in
# _rosidl_generator_py.so libraries that are missing libpython linkage.
add_executable(repro_test main.cpp)
target_link_libraries(repro_test ${tf2_eigen_TARGETS})
set_property(TARGET repro_test PROPERTY CXX_STANDARD 17)

install(TARGETS repro_test DESTINATION bin)
ament_package()
