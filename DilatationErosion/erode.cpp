#include <opencv2/opencv.hpp>
using namespace cv;

/*Function headers*/
void Erosion_trackbar(int, void*);

/*Erosion function*/
void Erosion(int choice) {

  /*Create windows*/
  namedWindow( "Erosion", CV_WINDOW_AUTOSIZE );

  /*Create erosion trackbar*/
  createTrackbar("shape:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion",
                 &erosion_shape, max_shape,
                 Erosion_trackbar);

  createTrackbar("Kernel size:\n 2n +1", "Erosion",
                 &erosion_size, max_kernel_size,
                 Erosion_trackbar);

  if (choice == 1) {
    /*Start*/
    Erosion_trackbar( 0, 0 );

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

    Erosion_trackbar(0, 0);

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

/*Erosion trackbar function*/
void Erosion_trackbar(int, void*) {

  int erosion_type;
  if(erosion_shape == 0) {erosion_type = MORPH_RECT;}
  else if(erosion_shape == 1) {erosion_type = MORPH_CROSS;}
  else if(erosion_shape == 2) {erosion_type = MORPH_ELLIPSE;}

  Mat shape = getStructuringElement(erosion_type,
                                    Size(2*erosion_size+1, 2*erosion_size+1),
                                    Point(erosion_size, erosion_size));

  /*Operate erotion*/
  erode(src, dst, shape);
  imshow("Erosion", dst);

}