#include <Eigen/Dense>
#include <tf2_eigen/tf2_eigen.hpp>
#include <tf2/buffer_core.h>
#include <geometry_msgs/msg/point.hpp>

Eigen::Vector3d convert_point(const geometry_msgs::msg::Point& p) {
  Eigen::Vector3d v;
  tf2::fromMsg(p, v);
  return v;
}

// Force a real link dependency on libtf2.so
std::unique_ptr<tf2::BufferCore> make_buffer() {
  return std::make_unique<tf2::BufferCore>();
}
