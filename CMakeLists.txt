cmake_minimum_required(VERSION 2.8.3)
project(ctools_gtest_pkg_shell)

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

add_library(ctools_gtest_pkg_shell src/main.cpp)
target_link_libraries(ctools_gtest_pkg_shell ${catkin_LIBRARIES})

add_executable(pkg_shell src/main.cpp)
target_link_libraries(pkg_shell ${catkin_LIBRARIES})

if (CATKIN_ENABLE_TESTING)

  # For running unit tests (gtest) alone
  catkin_add_gtest(utest src/test/utest.cpp)
  target_link_libraries(utest ${catkin_LIBRARIES} ctools_gtest_pkg_shell)
  
  # For running ROS tests (integration) NOTE: I believe it is possible to do these together
  find_package(rostest REQUIRED)
  add_rostest_gtest(shell_node_tests test/node_tests.test src/test/utest.cpp)
  target_link_libraries(shell_node_tests ${catkin_LIBRARIES} ctools_gtest_pkg_shell)

endif()



