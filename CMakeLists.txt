cmake_minimum_required(VERSION 2.8.3)
project(ps4camera)

find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
  message_filters
  cv_bridge
  roslib
  dynamic_reconfigure
  image_transport)


## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )


catkin_package()
include_directories(include)
add_executable(ps4camera_bridge include/Ps4CameraClass.h src/Ps4CameraClass.cpp src/main.cpp)
target_link_libraries(ps4camera_bridge ${catkin_LIBRARIES})
#add_dependencies(ps4camera_bridge)
