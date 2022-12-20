// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>
#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/aruco/aruco_calib_pose.hpp>
#include<opencv2/aruco.hpp>

using namespace std;
using namespace cv;

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
  // Load the dictionary 
  Ptr<cv::aruco::Dictionary> aruco_dict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
  // Initialize the detector parameters using default values
  Ptr<cv::aruco::DetectorParameters> aruco_param = cv::aruco::DetectorParameters::create(); 
  //Represents the two coordinates of a point in two-dimensional space, using Single-precision floating point numbers
  vector<vector<Point2f>> markerCorners, rejectedCandidates;
  // the ids of the detected markers are  stored in a vector
  vector<int> markerIds;
  VideoCapture cap;

  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  { 
    cap.open(0);   
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      100ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {  
    int marker_id = 0;
    Mat frame;
    bool read_frame = cap.read(frame);
    if(read_frame == true)
    cv::aruco::detectMarkers(frame, aruco_dict, markerCorners, markerIds, aruco_param, rejectedCandidates);
    for (auto i = markerIds.begin(); i!=markerIds.end(); ++i)
        marker_id = *i;
    
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(marker_id);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
