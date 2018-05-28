#include <opencv2/opencv.hpp>

using namespace cv;

// Global variables
Mat src, dst, src_gray, detected_edges;

// erosion
int erosion_elem = 0;
int erosion_size = 0;

// dilation
int dilation_elem = 0;
int dilation_size = 0;

// erosion & delation
int const max_elem = 2;
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
