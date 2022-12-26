## opencv setup
Run the following script to install opencv 
```bash
  bash setup/opencv/install_opencv_cpp.sh
```
To test the installation build the following script

```bash
  cd setup/opencv
  cmake .
  make
  ./DisplayImage sample_img.jpg
```
You should be able to view the image in a new window



## opencv-contrib setup (Aruco libraries included)
Run the following script to install opencv-contrib 
```bash
  bash setup/opencv-contrib/install_opencv-contrib.sh
```
[Reference](https://docs.opencv.org/4.x/d4/d17/namespacecv_1_1aruco.html)

Note : In case the extra modules library is not linked with the project run the following command

1. Find the folder containing the shared library libopencv_aruco.so.406 using the following command line.
```bash
  sudo find / -name "libopencv_aruco.so.406*"
```
Then I got the result: /usr/local/lib/libopencv_aruco.so.406. Then run the following.
```bash
  echo "/usr/local/lib/" >> /etc/ld.so.conf.d/opencv.conf 
  sudo ldconfig -v
```

## Basic ros package talker and listener
talker reads the aruco marker id and pass it to the listener (10Hz)
 ```bash
  cd ros2_ws
  colcon build
  . install/setup.bash
```
Run talker and listener in a seperate window
 ```bash
  ros2 run cpp_pubsub talker
  ros2 run cpp_pubsub listener
```

## PX4 SITL
following script installs Gazebo9, jMAVSim, NuttX/Pixhawk toolchain.
```bash
  git clone https://github.com/PX4/PX4-Autopilot.git --recursive
  bash ./PX4-Autopilot/Tools/setup/ubuntu.sh
```


## RTPS 
Create a file in PX4-Autopilot/boards/px4/sitl named ```rtps.px4board``` and put the line ```CONFIG_MODULES_MICRORTPS_BRIDGE=y``` into the file. Then you can make px4_sitl_rtps 
https://github.com/Jaeyoung-Lim/px4-offboard 
https://dev.px4.io/v1.9.0_noredirect/en/middleware/micrortps.html


## MAVSDK Library Installation (From Source)
#### Clone the Library
```bash
    git clone https://github.com/mavlink/MAVSDK.git
    git submodule update --init --recursive
```
#### Configure First and then Build
```bash
    cmake -DCMAKE_BUILD_TYPE=Debug -Bbuild/default -H.
    cmake --build build/default -j8
```
By default, when ```CMAKE_INSTALL_PREFIX``` is not set, cmake tries to install system-wide.
For Linux/macOS that's ```/usr/local```. Install it System-wide.
#### Install the Library built in the previous step
```bash
    sudo cmake --build build/default --target install
```
#### Testing the installation with Gazebo.
Terminal 1  : Run gazebo sitl px4
```bash
    cd PX4-Autopilot
    make px4_sitl gazebo
```
Terminal 2 : Runing sample MAVSDK example and connect to Gazebo.
```udp://:14540``` is the standard PX4 UDP port for connecting to offboard APIs.
```bash
    cd MAVSDK/examples/takeoff_and_land/
    cmake -Bbuild -H.
    cmake --build build -j4
```
MAVSDK should be able to connect to the Gazebo simulator.