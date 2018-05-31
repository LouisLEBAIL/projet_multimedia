#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
void CannyThreshold(int, void*)
{
  /// Reduce noise with a kernel 3x3
  blur( src_gray, detected_edges, Size(3,3) );

  /// Canny detector
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

  /// Using Canny's output as a mask, we display our result
  dst = Scalar::all(0);

  src.copyTo( dst, detected_edges);
  imshow( "Display", dst );
 }


/** @function main */
void EdgeDetection(int choice)
{

  /// Create a window
  namedWindow("Display", WINDOW_AUTOSIZE);
  moveWindow("display", 500, 50);

  /// Create a Trackbar for user to enter threshold
  createTrackbar( "Min Threshold:", "Display", &lowThreshold, max_lowThreshold, CannyThreshold );

  if (choice == 1) {
    /// Create a matrix of the same type and size as src (for dst)
    dst.create( src.size(), src.type() );

    /// Convert the image to grayscale
    cvtColor( src, src_gray, CV_BGR2GRAY );
    /// Show the image
    CannyThreshold(0, 0);

    /// Wait until user exit program by pressing a key
    waitKey(0);
  } else {
    cout << "press escape to close the video" << endl;
    while(1) {

    // Capture frame-by-frame
    cap >> src;

    // If the frame is empty, break immediately
    if (!cap.read(src)) 
    {
        cout << "end of the video!" << endl;
        break;
    }

    /// Create a matrix of the same type and size as src (for dst)
    dst.create( src.size(), src.type() );

    /// Convert the image to grayscale
    cvtColor( src, src_gray, CV_BGR2GRAY );

    CannyThreshold(alpha_slider, 0);

    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
        break;
    }

    // When everything done, release the video capture object
    cap.release();

    if (choice == 2) {
      cap = VideoCapture(videoName);
    }
  }

  //destroy all opened windows
  destroyAllWindows();

  }