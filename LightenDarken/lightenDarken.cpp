// Lighten and darken
// Gestion de la luminosite

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Matrices to store images
Mat alphadest;
Mat betadest;
Mat frame;

const int alpha_slider_max = 300;
const int beta_slider_max = 100;
int alpha_slider = 100;
int beta_slider = 0;
double beta, alpha;

void on_trackbar1( int, void* )
{
    alpha = (double) alpha_slider/(alpha_slider_max/3) ;
    addWeighted( frame, alpha, frame, 0, 0.0, alphadest);

    imshow( "Display", alphadest );
}

void on_trackbar2( int, void* )
{
    beta = (double) beta_slider;
    addWeighted( alphadest, 1, alphadest, beta, 0.0, betadest);

    imshow( "Display", betadest );
}

void lightDark()
{
    namedWindow("Display", WINDOW_AUTOSIZE);

    // Create Trackbars
 	char TrackbarNameAlpha[50];
 	char TrackbarNameBeta[50];
 	sprintf( TrackbarNameAlpha, "Alpha [0 - 3.0]");
  	sprintf( TrackbarNameBeta, "Beta [0 - 100]" );

 	createTrackbar( TrackbarNameAlpha, "Display", &alpha_slider, alpha_slider_max, on_trackbar1 );
  	createTrackbar( TrackbarNameBeta, "Display", &beta_slider, beta_slider_max, on_trackbar2 );

    on_trackbar1(alpha_slider, 0);
    on_trackbar2(beta_slider, 0);
    
    // Wait for any key stroke
    waitKey(0);

    //destroy all open windows
    destroyAllWindows();
}

int main(){
	frame = imread("van_gogh.jpg", IMREAD_COLOR);
	lightDark();
	return 0;
}