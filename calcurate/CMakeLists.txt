cmake_minimum_required(VERSION 3.8)
project(calcurate)



find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(number_gen src/number_gen.cpp)
ament_target_dependencies(number_gen rclcpp std_msgs)

install(TARGETS number_gen
  DESTINATION lib/${PROJECT_NAME})


ament_package()
