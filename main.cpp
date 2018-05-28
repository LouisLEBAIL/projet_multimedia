#include <opencv2/opencv.hpp>
#include <iostream>
#include "global.cpp"
#include "menu.cpp"
#include <string>

using namespace cv;
using namespace std;



int main(int argc, char** argv){

	cout << "Choisissez votre image" << endl;

	string imageName;
	cin >> imageName;

	// read the image
	src = imread(imageName,IMREAD_COLOR);

	if (!src.data){
      printf("No image data\n");
      return -1;
    }

	do {
		printMenu();
	} while(choiceMenu());

   return 0;
}