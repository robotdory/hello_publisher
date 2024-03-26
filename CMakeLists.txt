cmake_minimum_required(VERSION 3.5)
project(hello_publisher)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
################################################################################
# Set additional dependencies (의존성 설정)
################################################################################
set(ADD_DEP
  ament_cmake
  ament_cmake_ros
  rclcpp
  rclcpp_action
  std_msgs)
################################################################################
# Set additional source files (소스 파일 추가)
################################################################################
set(ADD_SRC
src/hello_publisher.cpp)

add_library(hello_publisher ${ADD_SRC})
target_include_directories(hello_publisher PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(hello_publisher ${ADD_DEP})

add_executable(hello src/hello_publisher_node.cpp)
target_link_libraries(hello hello_publisher)

install(
  DIRECTORY include/
  DESTINATION include)

install(TARGETS
  hello
  DESTINATION lib/${PROJECT_NAME})

#install(
#  DIRECTORY launch
#  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()
ament_package()
