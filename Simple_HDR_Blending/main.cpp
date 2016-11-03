#include <stdio.h>
#include <iostream>

// From OpenCV-2.4.13
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {

    double alpha = 0.5;
    double beta;

    Mat image_1;
    Mat image_2;
    Mat image_3;
    Mat image_4;
    Mat image_5;
    Mat image_6;
    Mat image_7;
    Mat image_8;
    Mat image_output;

    // Read different images
    image_1 = imread("dark_1.jpg");
    image_2 = imread("light_1.jpg");
    image_3 = imread("dark_2.jpg");
    image_4 = imread("light_2.jpg");
    image_5 = imread("normal.jpg");

    // Check loading
    if (image_1.empty()) {
        cout << "Error loading first image" << endl;
        return -1;
    }
    if (image_2.empty()) {
        cout << "Error loading second image" << endl;
        return -1;
    }
    if (image_3.empty()) {
        cout << "Error loading third image" << endl;
        return -1;
    }
    if (image_4.empty()) {
        cout << "Error loading fourth image" << endl;
        return -1;
    }
    if (image_5.empty()) {
        cout << "Error loading fifth image" << endl;
        return -1;
    }

    // Set JPEG lossy compression to minimal
    vector <int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    // 100% best possible quality
    compression_params.push_back(100);

    // Set 1
    beta = (1.0 - alpha);
    addWeighted(image_1, alpha, image_2, beta, 0.0, image_output);
    imwrite("Image_Blend_50_1.jpg", image_output, compression_params);

    // Set 2
    beta = (1.0 - alpha);
    addWeighted(image_3, alpha, image_4, beta, 0.0, image_output);
    imwrite("Image_Blend_50_2.jpg", image_output, compression_params);

    image_6 = imread("Image_Blend_50_1.jpg");
    image_7 = imread("Image_Blend_50_2.jpg");

    // Check loading
    if (image_6.empty()) {
        cout << "Error loading sixth image" << endl;
        return -1;
    }
    if (image_7.empty()) {
        cout << "Error loading seventh image" << endl;
        return -1;
    }

    beta = (1.0 - alpha);
    addWeighted(image_5, alpha, image_6, beta, 0.0, image_output);
    imwrite("Image_Blend_balanced.jpg", image_output, compression_params);

    image_8 = imread("Image_Blend_balanced.jpg");

    // Check loading
    if (image_8.empty()) {
        cout << "Error loading eighth image" << endl;
        return -1;
    }

    addWeighted(image_7, alpha, image_8, beta, 0.0, image_output);
    imwrite("Image_HDR.jpg", image_output, compression_params);

    return 0;
}
