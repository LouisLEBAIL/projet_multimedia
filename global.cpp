#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

struct button {
	int id;
	Rect rect;
    Rect hover_rect;
};

// Global variables
Mat src, src2, dst, src_gray, detected_edges;
VideoCapture cap_stream, cap_video;

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
int const alpha_slider_max = 200;
int alpha_slider = 100;

// edge detection
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

// menu
Mat3b img;
vector<button> buttons;
string title[4] = {"C++ Editor", "Image", "Video", "Stream"};
string texts_first_menu[4] = {"Exit", "Image", "Video", "Stream"};
string texts_editing_menu[8] = {"Back", "Light and dark", "Dilation", "Erosion", "Edge Detection", "Face detection", "Resizing", "Panorama/stitching"};
int editingMenuChoice;
bool backToFirstMenu = false;
bool quitApp = false;
bool cap_initialised = false;
