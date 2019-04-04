#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int your_conv( cv::Mat src,
               cv::Mat dst,
               cv::Mat kernel,
               int stride,
               int padding
               )
{
    int src_height = src.rows;
    int src_width = src.cols;

    int kernel_height = kernel.rows;
    int kernel_width = kernel.cols;

    int dst_height = ((src_height-kernel_height+2*padding) / stride)+1;
    int dst_width  = ((src_width-kernel_width+2*padding) / stride)+1;

    // src.ptr<unsigned char>(i)[ calculate INDEX ]


    // MAKE YOUR OWN CONVOLUTION PROCESS
	for(int i =0; i<dst_width; i=i+3){
	    for(int j=0; j<dst_height; j++){
		cv::Mat R<int>(i,j) = src_height[i][j]*kernel[j][i/3]
		}
	}

	for(int i =1; i<dst_width; i=i+3){
	    for(int j=0; j<dst_height; j++){
		cv::Mat G<int>(i,j) = src_height[i][j]*kernel[j][i/3+1]
		}
	}

	for(int i =2; i<dst_width; i=i+3){
	    for(int j=0; j<dst_height; j++){
		cv::Mat B<int>(i,j) = src_height[i][j]*kernel[j][i/3+2]
		}
	}

	for(int i =0; i<dst_width; i=i+3){
	    for(int j=0; j<dst_height; j++){
		cv::Mat dst<int>(i,j) = cv::Mat R<int>(i,j)
		cv::Mat dst<int>(i+1,j) = cv::Mat G<int>(i,j)
		cv::Mat dst<int>(i+2,j) = cv::Mat B<int>(i,j)
    // if success
    return 0

    // if fail - in the case of wrong parameters...
    // return -1
}

int main ( int argc, char** argv )
{
    if (argc < 2) {
        std::cout << "no filename given." << std::endl;
        std::cout << "usage: " << argv[0] << " image" << std::endl;
        return -1;
    }

    cv::Mat src, kernel, dst;

    // Load an image
    src = cv::imread( argv[1] );
    if( !src.data )  { return -1; }

    // Make filter
    kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);


    // Run 2D filter
    //cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    // ---------------------------
    your_conv(src,dst,kernel,1,0);
    // ---------------------------

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
