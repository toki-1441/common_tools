#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;
class NumberGen: public rclcpp::Node
{
  public:
    NumberGen()
    : Node("number_gen")
    {
      publisher_ = this->create_publisher<std_msgs::msg::Int32>("number", 10);
      timer_ = this->create_wall_timer(
        500ms, std::bind(&NumberGen::timer_callback, this));
    }
  private:
    void timer_callback()
    {
      std::srand(std::time(nullptr));

      // 0から99までの乱数を生成して出力
     int randomNumber = std::rand() % 100;
      auto message = std_msgs::msg::Int32();
      message.data = randomNumber;
      RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    // int count_ = 0;

};
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NumberGen>());
  rclcpp::shutdown();
  
  return 0;
}
