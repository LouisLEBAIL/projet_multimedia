#include <opencv2/opencv.hpp>
using namespace cv;

/*Function headers*/
void Dilation_trackbar(int, void*);

/*Dilation function*/
void Dilation() {

  /*Create windows*/
  namedWindow("Dilation", CV_WINDOW_AUTOSIZE);

  /*Create dilation trackbar*/
  createTrackbar("Shape:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation",
                 &dilation_shape, max_shape,
                 Dilation_trackbar);

  createTrackbar("Kernel size:\n 2n +1", "Dilation",
                 &dilation_size, max_kernel_size,
                 Dilation_trackbar);

  /*Start*/
  Dilation_trackbar(0, 0);

  /*End*/
  waitKey(0);
  destroyAllWindows();

}

/*Dilation trackbar function*/
void Dilation_trackbar(int, void*) {

  int dilation_type;
  if(dilation_shape == 0) {dilation_type = MORPH_RECT;}
  else if(dilation_shape == 1) {dilation_type = MORPH_CROSS;}
  else if(dilation_shape == 2) {dilation_type = MORPH_ELLIPSE;}

  Mat shape = getStructuringElement(dilation_type,
                                    Size(2*dilation_size+1, 2*dilation_size+1),
                                    Point(dilation_size, dilation_size));
  
  /*Operate dilation*/
  dilate(src, dst, shape);
  imshow("Dilation", dst);

}