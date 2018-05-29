#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void panoramaStitching()
{
	Mat src2, result;
	vector<Mat> imgs;


	cout << "Choisissez votre seconde image" << endl;

	string imageName;
	cin >> imageName;

	// read the image
	src2 = imread(imageName,IMREAD_COLOR);

	if (!src2.data){
      printf("No image data\n");
      return -1;
    }

	imgs.push_back(src);
	imgs.push_back(src2);
	src2.erase();
	
	Ptr<Stitcher> stitcher = Stitcher::create(mode, try_use_gpu);
	Stitcher::Status status = stitcher->stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
    	cout << "Can't stitch images, error code = " << int(status) << endl;
    	return -1;
	}
}
