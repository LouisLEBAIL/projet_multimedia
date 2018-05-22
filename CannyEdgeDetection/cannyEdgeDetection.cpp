#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
	Mat image;
  	image = imread("van_gogh.jpg" , CV_LOAD_IMAGE_COLOR);

    // Check for failure
    if(! image.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
  	
    //Blur the image with 3x3 kernel
    Mat edges;
    Canny(image, edges, 50, 150, 3);

    //Define names of the windows
    String window_name1 = "original image";
    String window_name2 = "canny edge detection";
    
    // Create windows with above names
    namedWindow( window_name1, cv::WINDOW_AUTOSIZE );
    namedWindow( window_name2, cv::WINDOW_AUTOSIZE );
  	

    // Show our images inside the created windows.
    imshow( "original image", image );
    imshow( "canny edge detection", edges );

    waitKey(0);// Wait for any keystroke in the window

    return 0; //destroy all opened windows


}

