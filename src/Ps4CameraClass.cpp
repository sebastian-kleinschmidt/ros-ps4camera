#include "Ps4CameraClass.h"

bool ps4camera::init(){
    //Read Launchfile

    camera1_pub = n.advertise<std_msgs::String>("left_image", 1000);
    camera2_pub = n.advertise<std_msgs::String>("right_image", 1000);

    if(capturer.open(0))
    {
        return true;
    } else {
        return false;
    }
}

cv::Mat ps4camera::receive_images(){

    cv::Mat ps4image;
    capturer >> ps4image;
    ROS_INFO("GOT IMAGES");
    return ps4image;
}

void ps4camera::spin(){
    while (ros::ok())
    {
        cv::Rect left_rect(48,0, 640, 480);
        cv::Rect right_rect(688,0, 640, 480);

        cv::Mat full_image = receive_images();
        cv::Mat left_image(full_image,left_rect);
        cv::Mat right_image(full_image,right_rect);

        cv::imshow("Left Image", left_image);
        cv::imshow("Right Image", right_image);
        cv::waitKey(1);
        //ros::spin();
    }
}
