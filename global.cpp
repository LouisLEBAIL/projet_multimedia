#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

// Global variables
Mat src, dst, src_gray, detected_edges;
VideoCapture cap;

// Video
string videoName;

// erosion
int erosion_shape = 0;
int erosion_size = 0;

// dilation
int dilation_shape = 0;
int dilation_size = 0;

// erosion & dilation
int const max_shape = 2;
int const max_kernel_size = 21;

// brightness
int const alpha_slider_max = 100;
int alpha_slider = 100;

// edge detection
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
