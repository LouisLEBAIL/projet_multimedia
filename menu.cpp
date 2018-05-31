#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <vector>

#include "global.cpp"
#include "Resizing/resizing.cpp"
#include "DilatationErosion/dilate.cpp"
#include "DilatationErosion/erode.cpp"
#include "LightenDarken/lightenDarken.cpp"
#include "CannyEdgeDetection/cannyEdgeDetection.cpp"
#include "PanoramaStitching/panoramaStitching.cpp"
#include "FaceDetection/faceDetection.cpp"

using namespace std;

bool choiceEditingMenu(int choice, int prev_choice);
void printEditingMenu(int choice);
bool choiceFirstMenu(int choice);
void callBackFuncFirstMenu(int event, int x, int y, int flags, void* userdata);
void callBackFuncEditingMenu(int event, int x, int y, int flags, void* userdata);
void drawMenu(int size, int menu_nb, int choice);
int openImage();
int openVideo(int choice);

bool choiceEditingMenu(int choice, int prev_choice) {

	switch(choice) {
		case 0:
			return false;
		case 1:
			lightDark(prev_choice);
			break;
		case 2:
			Dilation(prev_choice);
			break;
		case 3:
			Erosion(prev_choice);
			break;
		case 4:
			EdgeDetection(prev_choice);
			break;
		case 5:
			FaceDetection(prev_choice);
			break;
		case 6:
			if (prev_choice == 1)
				Resizing();
			break;
		case 7:
			if (prev_choice == 1)
				panoramaStitching();
			break;
		default:
			cout << "Wrong menu command" << endl;
			break;
	}
	return true;
}

bool choiceFirstMenu(int choice) {

	int safeOpen;

	if(cap.isOpened()){
		cap.release();
	}

	if (choice == 0) {
		return false;
	} else if (choice == 1) {
		safeOpen = openImage();
	} else if (choice == 2 || choice == 3) {
		safeOpen = openVideo(choice);
	}

	if (safeOpen == -1)
		return true;

	if (choice >= 0 && choice <= 3) {
		printEditingMenu(choice);
	}

	return true;
}

void callBackFuncFirstMenu(int event, int x, int y, int flags, void* userdata)
{
	for (vector<button>::iterator bt = buttons.begin() ; bt != buttons.end(); ++bt) {
		if (bt -> rect.contains(Point(x, y)))
		{
			if (event == EVENT_LBUTTONDOWN)
			{
				destroyAllWindows();
				if (bt -> id != 0) {
					choiceFirstMenu(bt -> id);
					quitApp = false;
				} else {
					quitApp = true;
				}
				return;
			}
			rectangle(img, bt -> hover_rect, Scalar(255, 0, 0), 1, 8);
			rectangle(img, bt -> rect, Scalar(255, 255, 255), 1, 8);
		} else {
			rectangle(img, bt -> rect, Scalar(255, 0, 0), 1, 8);
			rectangle(img, bt -> hover_rect, Scalar(255, 255, 255), 1, 8);
		}
	}
	imshow("display", img);
}

void callBackFuncEditingMenu(int event, int x, int y, int flags, void* userdata)
{
	for (vector<button>::iterator bt = buttons.begin() ; bt != buttons.end(); ++bt) {
		if (bt -> rect.contains(Point(x, y)))
		{
			if (event == EVENT_LBUTTONDOWN)
			{
				destroyAllWindows();
				if (bt -> id != 0) {
					choiceEditingMenu(bt -> id, editingMenuChoice);
					backToFirstMenu = false;
				} else {
					backToFirstMenu = true;
				}
				return;
			}
			rectangle(img, bt -> hover_rect, Scalar(255, 0, 0), 1, 8);
			rectangle(img, bt -> rect, Scalar(255, 255, 255), 1, 8);
		} else {
			rectangle(img, bt -> rect, Scalar(255, 0, 0), 1, 8);
			rectangle(img, bt -> hover_rect, Scalar(255, 255, 255), 1, 8);
		}
	}
	imshow("display", img);
}

void drawMenu(int size, int menu_nb, int choice) {

	Mat3b canvas;

	img = Mat3b(size*100, 300, Vec3b(255, 255, 255));

	putText(img, title[choice], Point(30, 60), FONT_HERSHEY_SIMPLEX, 1, Scalar(255,0,0));
	buttons.clear();
	for (int i = 1; i < size+1; i++) {
		button bt;
		bt.rect = Rect(50, 100 + ((i-1)*75), 200, 50);
		bt.hover_rect = Rect(bt.rect.x-10, bt.rect.y-10, bt.rect.width + 20, bt.rect.height + 20);
		bt.id = i-1;
		buttons.push_back(bt);
    	rectangle(img, bt.rect, Scalar(255, 0, 0), 1, 8);
		if (menu_nb == 1)
			putText(img, texts_first_menu[i-1], Point(bt.rect.x + bt.rect.width*0.15, bt.rect.y + bt.rect.height*0.7), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,0,0));
		else
			putText(img, texts_editing_menu[i-1], Point(bt.rect.x + bt.rect.width*0.15, bt.rect.y + bt.rect.height*0.7), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,0,0));
	}

	namedWindow("display");
	moveWindow("display", 500, 50);

	if (menu_nb == 1) {
    	setMouseCallback("display", callBackFuncFirstMenu);
	} else {
		editingMenuChoice = choice;
		setMouseCallback("display", callBackFuncEditingMenu);
	}
    imshow("display", img);

	waitKey(0);
}

void printFirstMenu() {
	do {
		drawMenu(4, 1, 0);
	} while (!quitApp);
}

void printEditingMenu(int choice) {
	do {
		if (choice == 1) {
			drawMenu(8, 2, choice);
		} else {
			drawMenu(6, 2, choice);
		}
	} while (!backToFirstMenu);
}

int openImage() {
	cout << "Choisissez votre image file" << endl;
	string imageName;
	cin >> imageName;
	// read the image
	src = imread(imageName,IMREAD_COLOR);

	if (!src.data){
		printf("No image data\n");
		return -1;
	}
	return 0;
}

int openVideo(int choice) {
	if (choice == 2) {
		cout << "Choisissez votre video file" << endl;
		cin >> videoName;
		cap = VideoCapture(videoName);
	} else {
		cap = VideoCapture(1);
	}

	if(!cap.isOpened()){
		cout << "Error opening video stream or file" << endl;
		return -1;
	}
	return 0;
}