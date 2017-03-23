cmake_minimum_required(VERSION 2.8.3)
project(tdd_cpp_examples)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp rospy std_msgs
  #DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(tdd_cpp_examples src/main.cpp)
target_link_libraries(tdd_cpp_examples ${catkin_LIBRARIES})

add_executable(examples src/main.cpp)
target_link_libraries(examples ${catkin_LIBRARIES})

##### Commented out if-logic below during devel so that tests are always built #####
#if (CATKIN_ENABLE_TESTING)

  # For running unit tests (gtest) alone
  # catkin_add_gtest(utest src/test/utest.cpp)
  # target_link_libraries(utest ${catkin_LIBRARIES} tdd_cpp_examples)
  
  # For running ROS tests (integration) NOTE: I believe it is possible to do these together
  find_package(rostest REQUIRED)
  add_rostest_gtest(examples_node_tests test/node_tests.test src/test/utest.cpp)
  target_link_libraries(examples_node_tests ${catkin_LIBRARIES} tdd_cpp_examples)

#endif()



