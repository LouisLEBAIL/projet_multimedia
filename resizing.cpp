#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

void Resizing(Mat source){

	Mat dst;

	double scaleX, scaleY;			
	cout << "Coefficient de modification x"<<endl;
	cin >> scaleX;
	cout << "Coefficient de modification y"<<endl;
	cin >> scaleY;

	// Scaling the image
	resize(source,dst, Size(),scaleX, scaleY, INTER_LINEAR);

	 // Naming window
    string windowNameOriginalImage="Original Image";
    string windowNameResizedImage="Resized Image";

    //Create window
    namedWindow(windowNameOriginalImage, WINDOW_AUTOSIZE);
    namedWindow(windowNameResizedImage, WINDOW_AUTOSIZE);

    // Show our images inside the created windows.
    imshow(windowNameOriginalImage,source);
    imshow(windowNameResizedImage,dst);

    // Wait for any keystroke in the window
    waitKey(0); 

    //destroy all opened windows
    destroyAllWindows();

}

