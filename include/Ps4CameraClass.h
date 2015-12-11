#include "ros/ros.h"
#include "std_msgs/String.h"
#include <opencv2/opencv.hpp>

class ps4camera {
    private:
        ros::NodeHandle n;
        ros::Publisher camera1_pub;
        ros::Publisher camera2_pub;

        cv::VideoCapture capturer;

        cv::Mat receive_images();

    public:
        bool init();
        void spin();
};

