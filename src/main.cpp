#include <iostream>
#include <geometry_msgs/msg/point.hpp>
#include <Eigen/Dense>

extern Eigen::Vector3d convert_point(const geometry_msgs::msg::Point& p);

int main() {
  geometry_msgs::msg::Point p;
  p.x = 1.0;
  p.y = 2.0;
  p.z = 3.0;

  auto v = convert_point(p);
  std::cout << "Converted point: " << v.transpose() << std::endl;
  return 0;
}
