#include <opencv2/opencv.hpp>

using namespace cv;

/** Function Headers */
void Erosion_trackbar( int, void* );

/** @function main */
int Erosion()
{

  /// Create windows
  namedWindow( "Erosion Demo", CV_WINDOW_AUTOSIZE );

  /// Create Erosion Trackbar
  createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
                  &erosion_elem, max_elem,
                  Erosion_trackbar );

  createTrackbar( "Kernel size:\n 2n +1", "Erosion Demo",
                  &erosion_size, max_kernel_size,
                  Erosion_trackbar );

  /// Default start
  Erosion_trackbar( 0, 0 );

  waitKey(0);

  destroyAllWindows();
  
  return 0;
}

/**  @function Erosion  */
void Erosion_trackbar( int, void* )
{
  int erosion_type;
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( erosion_size, erosion_size ) );

  /// Apply the erosion operation
  erode( src, dst, element );
  imshow( "Erosion Demo", dst );
}