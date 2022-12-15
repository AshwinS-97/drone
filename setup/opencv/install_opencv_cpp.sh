sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config
git clone https://github.com/opencv/opencv
mkdir -p build
cd build
cmake ../opencv
make -j4
sudo make install