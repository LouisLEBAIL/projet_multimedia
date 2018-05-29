#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void on_trackbar1( int, void* )
{
    double alpha = (double) alpha_slider/alpha_slider_max;
    addWeighted( src, alpha, src, 0, 0.0, dst);
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
        imshow( "Display", dst );
        // Wait for any key stroke
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

        on_trackbar1(alpha_slider, 0);

        imshow( "Display", dst );
        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
        if(c==27)
        break;
        }

        // When everything done, release the video capture object
        cap.release();

  }

    //destroy all open windows
    destroyAllWindows();
}