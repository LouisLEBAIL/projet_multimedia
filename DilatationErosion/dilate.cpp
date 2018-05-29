#include <opencv2/opencv.hpp>
using namespace cv;

/*Function headers*/
void Dilation_trackbar(int, void*);

/*Dilation function*/
void Dilation(int choice) {

  /*Create windows*/
  namedWindow("Dilation", CV_WINDOW_AUTOSIZE);

  /*Create dilation trackbar*/
  createTrackbar("Shape:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation",
                 &dilation_shape, max_shape,
                 Dilation_trackbar);

  createTrackbar("Kernel size:\n 2n +1", "Dilation",
                 &dilation_size, max_kernel_size,
                 Dilation_trackbar);

  if (choice == 1) {
    /*Start*/
    Dilation_trackbar(0, 0);

    /*End*/
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

    Dilation_trackbar(0, 0);

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