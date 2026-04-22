#include <iostream>
#include <Eigen/Dense>
#include <tf2_eigen/tf2_eigen.hpp>
#include <geometry_msgs/msg/point.hpp>

int main() {
  geometry_msgs::msg::Point p;
  p.x = 1.0;
  p.y = 2.0;
  p.z = 3.0;

  Eigen::Vector3d v;
  tf2::fromMsg(p, v);

  std::cout << "Converted point: " << v.transpose() << std::endl;
  return 0;
}
