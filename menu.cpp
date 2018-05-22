#include <iostream>
#include "resizing.cpp"
#include <opencv2/opencv.hpp>
#include "DilatationErosion/dilate.cpp"

using namespace std;

void printMenu(){


	

	cout << "0 - exit program"<<endl;
	cout << "1 - resizing"<<endl;
	cout << "2 - light and dark"<<endl;
	cout << "3 - panorama and stitching"<<endl;
	cout << "4 - dilatation and erosion"<<endl;
	cout << "5 - canny edge detection"<<endl;
}

bool choiceMenu(bool stop,Mat src){
	int choice;
	cin >> choice;
	switch(choice){
		case 0:
			stop = false;
			destroyAllWindows();
			break;

		case 1:
			
			Resizing(src);
			break;

	case 4:
			Dilatation(src);
			break;
	}
	return stop;
}