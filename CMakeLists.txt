# by harderthan, kheo1772@gmail.com
###----------------------------------------
cmake_minimum_required(VERSION 2.8.3)
project(dataset2rosbag)
add_compile_options(-std=c++11)

find_package(OpenCV REQUIRED)

find_package(catkin REQUIRED roscpp)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  include
)

set(SOURCES
    src/dataset2rosbag_node.cpp
    src/YamlParamReader.cpp
)

add_executable(${PROJECT_NAME}_node ${SOURCES})
set(PARAM_YAML "${CMAKE_CURRENT_SOURCE_DIR}/param.yaml")
set_target_properties(${PROJECT_NAME}_node
    PROPERTIES COMPILE_FLAGS
    "-DPARAM_YAML=${PARAM_YAML}"
)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)
