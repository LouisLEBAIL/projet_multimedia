#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "global.cpp"
#include "Resizing/resizing.cpp"
#include "DilatationErosion/dilate.cpp"
#include "DilatationErosion/erode.cpp"
#include "LightenDarken/lightenDarken.cpp"
#include "CannyEdgeDetection/cannyEdgeDetection.cpp"

using namespace std;

void printEditingMenu(int choice) {
	cout << "0 - back" << endl;
	cout << "1 - light and dark" << endl;
	cout << "2 - dilation" << endl;
	cout << "3 - erosion" << endl;
	cout << "4 - canny edge detection" << endl;
	if (choice == 1) {
		cout << "5 - resizing" << endl;
		cout << "6 - panorama and stitching" << endl;
	}
}

void printFirstMenu() {
	cout << "0 - exit program" << endl;
	cout << "1 - image" << endl;
	cout << "2 - vidéo" << endl;
	cout << "3 - stream" << endl;
}

bool choiceEditingMenu(int prev_choice) {

	int choice;
	cin >> choice;

	switch(choice) {
		case 0:
			return false;
		case 1:
			lightDark(prev_choice);
			break;
		case 2:
			Dilation();
			break;
		case 3:
			Erosion();
			break;
		case 4:
			EdgeDetection();
			break;
		case 5:
			if (prev_choice == 1)
				Resizing();
			break;
		case 6:
			break;
		default:
			cout << "Wrong menu command" << endl;
			break;
	}
	return true;
}

bool choiceFirstMenu() {
	int choice;
	cin >> choice;


	if (choice == 0) {
		return false;
	} else if (choice == 1) {
		cout << "Choisissez votre image file" << endl;
		string imageName;
		cin >> imageName;
		// read the image
		src = imread(imageName,IMREAD_COLOR);
		if (!src.data){
			printf("No image data\n");
			return -1;
		}
	} else if (choice == 2 || choice == 3) {
		if (choice == 2) {
			cout << "Choisissez votre video file" << endl;
			string videoName;
			cin >> videoName;
			// read the image
			cap = VideoCapture(videoName);
		} else {
			cap = VideoCapture(1);
		}

		if(!cap.isOpened()){
			cout << "Error opening video stream or file" << endl;
			return -1;
		}
	}

	if (choice > 0 && choice <= 3) {
		do {
			printEditingMenu(choice);
		} while (choiceEditingMenu(choice));
	}

	return true;
}