
## opencv setup
Run the following script to install opencv 
```bash
  cd setup/opencv
  bash install_opencv_cpp.sh
```
To test the installation build the following script

```bash
  cd setup/opencv
  cmake .
  make
  ./DisplayImage sample_img.jpg
```
You should be able to view the image in a new window
