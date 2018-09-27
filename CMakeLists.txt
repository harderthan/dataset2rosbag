cmake_minimum_required(VERSION 2.8.3)
project(dataset2rosbag)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)


add_executable(${PROJECT_NAME}_node src/dataset2rosbag_node.cpp)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
