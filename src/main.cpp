#include "Ps4CameraClass.h"


#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ps4_camera_bridge");
  ROS_INFO("ROS_PS4_Eye: Started");

  ps4camera *camera = new ps4camera();
  if(camera->init())
  {
    camera->spin();
  }
  ROS_ERROR("ROS_PS4_Eye: Shutdown");
  ros::shutdown();

  return 0;
}
