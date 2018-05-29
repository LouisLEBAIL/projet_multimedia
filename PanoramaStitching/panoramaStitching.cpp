#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void panoramaStitching()
{
	namedWindow("Display", WINDOW_AUTOSIZE);
	vector<Mat> imgs;
	string imageName2;
	
	cout << "Choisissez votre seconde image" << endl;
	cin >> imageName2;

	// read the image
	src2 = imread(imageName2,IMREAD_COLOR);

	if (!src2.data){
      printf("No image data\n");
    }

	imgs.push_back(src);
	imgs.push_back(src2);
	
	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA, true);
	Stitcher::Status status = stitcher->stitch(imgs, dst);

	if (status != Stitcher::OK)
	{
    	cout << "Can't stitch images, error code = " << int(status) << endl;
	}

	imshow( "Display", dst );

	// Wait for any key stroke
    waitKey(0);

    //destroy all open windows
    destroyAllWindows();
}
