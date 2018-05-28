#include <opencv2/opencv.hpp>

using namespace cv;

/** Function Headers */
void Dilation_trackbar( int, void* );

/** @function main */
void Dilation()
{
  /// Create windows
  namedWindow( "Dilation Demo", CV_WINDOW_AUTOSIZE );

  /// Create Dilation Trackbar
  createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
                  &dilation_elem, max_elem,
                  Dilation_trackbar );

  createTrackbar( "Kernel size:\n 2n +1", "Dilation Demo",
                  &dilation_size, max_kernel_size,
                  Dilation_trackbar );

  /// Default start
  Dilation_trackbar( 0, 0 );

  waitKey(0);

  destroyAllWindows();

}

/** @function Dilation */
void Dilation_trackbar( int, void* )
{

  int dilation_type;
  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( dilation_type,
                                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                       Point( dilation_size, dilation_size ) );
  /// Apply the dilation operation
  dilate( src, dst, element );
  imshow( "Dilation Demo", dst );
}