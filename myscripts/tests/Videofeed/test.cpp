/*************************************************************
 * Gazebo broadcasts video on UDP 5600 port in local host.
 * This is the sample script to read the video Broadcasted 
 * with gstreamer plugin(model in gazebo) with OpenCV script 
*/

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;
    Mat frame;
    cap.open("udpsrc port=5600 caps = \"application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264\" ! rtph264depay ! avdec_h264 ! videoconvert ! appsink", cv::CAP_GSTREAMER);
    //cap.open(0);
    while(1){
    bool read_frame = cap.read(frame);
    if(read_frame)
    {
        imshow("Window Name", frame);
        if(waitKey(30) == 27) // Wait for 'esc' key press to exit
        break; 
    }
    }
    return 0;
}