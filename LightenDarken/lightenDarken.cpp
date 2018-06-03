#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void on_trackbar1( int, void* )
{
    double alpha = (double) alpha_slider/(alpha_slider_max/2);
    addWeighted( src, alpha, src, 0, 0.0, dst);
    imshow( "Display", dst );
}

void lightDark(int choice)
{
    namedWindow("Display", WINDOW_AUTOSIZE);

    // Create Trackbars
 	char TrackbarNameAlpha[50];

 	sprintf( TrackbarNameAlpha, "Brightness");

 	createTrackbar( TrackbarNameAlpha, "Display", &alpha_slider, alpha_slider_max, on_trackbar1 );

    if (choice == 1) {

        on_trackbar1(alpha_slider, 0);
        // Wait for any key stroke
        waitKey(0);
    } else {
    
        cout << "press escape to close the video" << endl;
        while(1) {

        if (choice == 2) {
        // Capture frame-by-frame
        cap_video >> src;

        // If the frame is empty, break immediately
        if (!cap_video.read(src)) 
        {
            cout << "end of the video!" << endl;
            break;
        }
      } else {
        cap_stream >> src;
      }

        on_trackbar1(alpha_slider, 0);

        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
            if(c==27) {
                break;
            }
        }

        if (choice == 2) {
            cap_video = VideoCapture(videoName);
        }

  }

    //destroy all open windows
    destroyAllWindows();
}