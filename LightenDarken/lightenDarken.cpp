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

void lightDark()
{
    namedWindow("Display", WINDOW_AUTOSIZE);

    // Create Trackbars
 	char TrackbarNameAlpha[50];

 	sprintf( TrackbarNameAlpha, "Brightness");

 	createTrackbar( TrackbarNameAlpha, "Display", &alpha_slider, alpha_slider_max, on_trackbar1 );

    on_trackbar1(alpha_slider, 0);
    
    // Wait for any key stroke
    waitKey(0);

    //destroy all open windows
    destroyAllWindows();
}