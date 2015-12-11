#include "Ps4CameraClass.h"


#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ps4_camera_bridge");

  ps4camera camera;

  if(camera.init())
  {
    camera.spin();
  }
  ros::shutdown();

  return 0;
}
