#include "Ps4CameraClass.h"

ps4camera::ps4camera()
{
}

bool ps4camera::init(){
    //Read Launchfile
    int deviceID;
    std::string LeftImageTopic;
    std::string RightImageTopic;

    if(!n.getParam("leftImageTopic",LeftImageTopic) || !n.getParam("rightImageTopic",RightImageTopic))
    {
        LeftImageTopic="left_image";
        RightImageTopic="right_image";
    }

    if(!n.getParam("deviceID",deviceID))
    {
        ROS_ERROR("Using default device: /dev/video0");
        deviceID=0;
    }

    it = new image_transport::ImageTransport(n);
    camera1_pub = it->advertise(LeftImageTopic, 1);
    camera2_pub = it->advertise(RightImageTopic, 1);

    if(capturer.open(deviceID))
    {
        return true;
    } else {
        return false;
    }
}

cv::Mat ps4camera::receive_images(){

    cv::Mat ps4image;
    capturer >> ps4image;
    return ps4image;
}

void ps4camera::spin(){
    while (ros::ok())
    {
        int resolution_x = 1280;
        int resolution_y = 800;

        cv::Rect left_rect((48),0, resolution_x, resolution_y);
        cv::Rect right_rect((resolution_x+48),0, resolution_x, resolution_y);

        cv::Mat full_image = receive_images();
        cv::Mat left_image(full_image,left_rect);
        cv::Mat right_image(full_image,right_rect);

        sensor_msgs::ImagePtr left_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", left_image).toImageMsg();
        sensor_msgs::ImagePtr right_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", right_image).toImageMsg();

        camera1_pub.publish(left_msg);
        camera2_pub.publish(right_msg);

        ros::spinOnce();
    }
}
