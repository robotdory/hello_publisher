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

#ifndef HELLO_PUBLISHER__HELLO_PUBLISHER_HPP_
#define HELLO_PUBLISHER__HELLO_PUBLISHER_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/empty.hpp"
#include "std_msgs/msg/string.hpp"

namespace hello_publisher
{
class HelloPublisher : public rclcpp::Node
{
public:
  explicit HelloPublisher(const std::string & node_name);

  virtual ~HelloPublisher();

private:
  rclcpp::TimerBase::SharedPtr publish_info_timer_;
  rclcpp::TimerBase::SharedPtr publish_heartbeat_timer_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr hello_publisher_;
  rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr heartbeat_publisher_;

  size_t message_count_;

  /**
   * @brief Topic과 Heartbeat를 Publish하는 함수
   *
   */
  void publish_info();

  /**
   * @brief 노드의 생존 여부에 대해 Publish하는 함수
   *
   */
  void publish_heartbeat();
};

}  // namespace hello_publisher

#endif  // HELLO_PUBLISHER__HELLO_PUBLISHER_HPP_
