git clone https://github.com/opencv/opencv_contrib
mkdir build_opencv_contrib
cd build_opencv_contrib
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules/aruco ../../opencv
make -j4
sudo make install
