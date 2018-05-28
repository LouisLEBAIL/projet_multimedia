#include <iostream>
#include <opencv2/opencv.hpp>
#include "Resizing/resizing.cpp"
#include "DilatationErosion/dilate.cpp"
#include "DilatationErosion/erode.cpp"
#include "LightenDarken/lightenDarken.cpp"
#include "CannyEdgeDetection/cannyEdgeDetection.cpp"

using namespace std;

void printMenu() {
	cout << "0 - exit program" << endl;
	cout << "1 - resizing" << endl;
	cout << "2 - light and dark" << endl;
	cout << "3 - panorama and stitching" << endl;
	cout << "4 - dilation" << endl;
	cout << "5 - erosion" << endl;
	cout << "6 - canny edge detection" << endl;
}

bool choiceMenu() {

	int choice;
	cin >> choice;

	switch(choice) {
		case 0:
			return false;
		case 1:
			Resizing();
			break;
		case 2:
			lightDark();
			break;
		case 3:
			break;
		case 4:
			Dilation();
			break;
		case 5:
			Erosion();
			break;
		case 6:
			EdgeDetection();
			break;
	}
	return true;
}