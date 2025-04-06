#include <iostream>
#include <string>
#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/vector3.hpp"

using namespace std::chrono_literals;

class TurtlePublisher: public rclcpp::Node {
	
	public:
		TurtlePublisher() : Node("turtle_publisher") {
			publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
			timer_ = this->create_wall_timer(500ms, std::bind(&TurtlePublisher::timer_callback, this));
		}
	
	private:
		rclcpp::TimerBase::SharedPtr timer_;
		rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
		void timer_callback() {
			auto message = geometry_msgs::msg::Twist();
			message.linear = geometry_msgs::msg::Vector3();
			message.linear.x = 1;
			message.linear.y = 0;
			message.linear.z = 0;
			message.angular = geometry_msgs::msg::Vector3();
			message.angular.x = 0;
			message.angular.y = 0;
			message.angular.z = 0;
			RCLCPP_INFO(this->get_logger(), 
									"Publishing: 'linear  x: %f, y: %f, z: %f', 'angular: x: %f, y: %f, z: %f'", 
									message.linear.x, message.linear.y, message.linear.z,
									message.angular.x, message.angular.y, message.angular.z
									);
			 publisher_->publish(message);
		}
};

int main(int argc, char* argv[]) {
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<TurtlePublisher>());
	rclcpp::shutdown();
	return 0;
}

