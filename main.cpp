#include <opencv2/opencv.hpp>
#include <iostream>
#include "menu.cpp"

using namespace cv;
using namespace std;



int main(int argc, char** argv){

	do {
		printFirstMenu();
	} while(choiceFirstMenu());

   return 0;
}