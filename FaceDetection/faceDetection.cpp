#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


void FaceDetection(int choice){

    namedWindow("Display", WINDOW_AUTOSIZE);

    // Load Face cascade (.xml file)
    CascadeClassifier face_cascade;
    face_cascade.load( "haarcascade_frontalface_alt2.xml" );

    if (choice == 1) {
        //make copy of src in dst
        dst = src.clone();

        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale( dst, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

        // Draw circles on the detected faces
        for( int i = 0; i < faces.size(); i++ )
        {
            Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
            ellipse( dst, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        }

        imshow( "Display", dst );

    } else {
        
        cout << "press escape to close the video" << endl;
        while(1) {

            // Capture frame-by-frame
            cap >> src;

            // If the frame is empty, break immediately
            if (!cap.read(src)) 
            {
                cout << "end of the video!" << endl;
                break;
            }

            //make copy of src in dst
            dst = src.clone();

            // Detect faces
            vector<Rect> faces;
            face_cascade.detectMultiScale( dst, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

            // Draw circles on the detected faces
            for( int i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
                ellipse( dst, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
            }
            
            imshow( "Display", dst );

            // Press  ESC on keyboard to exit
            char c=(char)waitKey(25);
            if(c==27)
                break;
        }

        if (choice == 2) {
            cap = VideoCapture(videoName);
        }

    }

    // Wait for any key stroke
    waitKey(0);

    //destroy all open windows
    destroyAllWindows();
}
/*
int main(int argc, char** argv)
{



    // Read the image file
  Mat image;
  Mat gray;
  image = imread("willy.jpg" , CV_LOAD_IMAGE_COLOR);

  // Load Face cascade (.xml file)
  CascadeClassifier face_cascade;
  face_cascade.load( "haarcascade_frontalface_alt2.xml" );
  
  CascadeClassifier face_cascade2;
  face_cascade2.load( "/opt/opencv/data/haarcascades/haarcascade_frontalface_default.xml" );
  CascadeClassifier eye_cascade;
  eye_cascade.load( "/opt/opencv/data/haarcascades/haarcascade_eye.xml" );
  
  

  // Detect faces
  std::vector<Rect> faces;
  face_cascade.detectMultiScale( image, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

  // Draw circles on the detected faces
    for( int i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    }


    //Define names of the windows
    String window_name1 = "original image";
    

    // Create windows with above names
    namedWindow( window_name1, cv::WINDOW_AUTOSIZE );
    
    

    // Show our images inside the created windows.
    imshow( "original image", image );
    

    waitKey(0);// Wait for any keystroke in the window

    return 0; //destroy all opened windows


}
*/