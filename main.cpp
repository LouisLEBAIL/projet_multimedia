#include <opencv2/opencv.hpp>
#include <iostream>
#include "menu.cpp"
#include <string>

using namespace cv;
using namespace std;



int main(int argc, char** argv){

	cout << "Choisissez votre image" << endl;

	string imageName;
	cin >> imageName;

	// read the image
	 Mat src = imread(imageName,IMREAD_COLOR);

	if (!src.data){
      printf("No image data\n");
      return -1;
    }

	bool stop = true;

	while (stop){
		printMenu();
		stop = choiceMenu(stop,src);
	}

   return 0;
}