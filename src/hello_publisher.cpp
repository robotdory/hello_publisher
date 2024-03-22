/*******************************************************************************
 * Copyright 2024 ROBOTIS CO., LTD.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* Authors: Tae-Hyeon KIM */

#include "hello_publisher/hello_publisher.hpp"

#include <string>
#include <vector>

namespace hello_publisher
{

  using namespace std::chrono_literals;

  HelloPublisher::HelloPublisher(const std::string &node_name) : Node(node_name)

  {
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(20));

    RCLCPP_INFO_STREAM(get_logger(), "HelloPublisher has been started.");

    hello_publisher_ =
        create_publisher<std_msgs::msg::String>("/hello", qos_profile);
    heartbeat_publisher_ =
        create_publisher<std_msgs::msg::Bool>("/heartbeat", qos_profile);

    publish_heartbeat_timer_ = this->create_wall_timer(
        500ms, std::bind(&HelloPublisher::publish_heartbeat, this));

    publish_info_timer_ = this->create_wall_timer(
        100ms, std::bind(&HelloPublisher::publish_info, this));
    message_count_ = 0;
  }

  HelloPublisher::~HelloPublisher()
  {
    RCLCPP_INFO_STREAM(get_logger(), "HelloPublisher has been terminated.");
  }

  void HelloPublisher::publish_info()
  {
    auto hello_msg = std_msgs::msg::String();
    hello_msg.data = "hello[" + std::to_string(++message_count_) + "]";
    hello_publisher_->publish(hello_msg);
  }

  void HelloPublisher::publish_heartbeat()
  {
    auto heartbeat = std_msgs::msg::Bool();
    heartbeat.data = true;
    heartbeat_publisher_->publish(heartbeat);
  }
} // namespace hello_publisher
