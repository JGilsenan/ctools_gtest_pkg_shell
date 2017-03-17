cmake_minimum_required(VERSION 2.8.3)
project(tdd_lidar_demo)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  tf
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs tf
  DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(tdd_lidar_demo src/tdd_lidar_demo.cpp)
target_link_libraries(tdd_lidar_demo ${catkin_LIBRARIES})

add_executable(tdd_demo src/tdd_lidar_demo.cpp)
target_link_libraries(tdd_demo ${catkin_LIBRARIES})

if (CATKIN_ENABLE_TESTING)
  catkin_add_gtest(utest test/utest.cpp)
  target_link_libraries(utest ${catkin_LIBRARIES} tdd_lidar_demo)
endif()



