#include "ros/ros.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/String.h"
#include <opencv2/opencv.hpp>

class ps4camera {
    private:
        ros::NodeHandle n;
        image_transport::ImageTransport *it;
        image_transport::Publisher camera1_pub;
        image_transport::Publisher camera2_pub;

        cv::VideoCapture capturer;


        cv::Mat receive_images();

    public:
        ps4camera();
        bool init();
        void spin();
};

