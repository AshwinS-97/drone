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