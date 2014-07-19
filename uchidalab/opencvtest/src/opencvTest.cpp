#include <iostream>
#include "opencv/cv.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"

using namespace std;
using namespace cv;

int main(){
    CvCapture *cap = cvCaptureFromFile("./20120426.mp4");;
    
    if(cap == nullptr){
        cerr << "input error" << endl;
        exit(1);
    }

    Mat img, dst;
    // 動画から画像を読み込み
    img = cvQueryFrame(cap);
    // 90°回転
    transpose(img, dst);
    flip(dst,dst,1);

    // SIFTを使って特徴量をとってみる
    SiftFeatureDetector detector;
    vector<KeyPoint> keypoints;
    detector.detect(dst, keypoints);

    // SIFT特徴量を円として描画
    // 半径はベクトルの大きさから決定
    for(auto it = keypoints.begin(); it != keypoints.end(); ++it){
        circle( dst, Point(it->pt.x, it->pt.y), saturate_cast<int>(it->size*0.5),Scalar(255,255,0));
    }

    imshow("Image", dst);
    
    waitKey(0);

    cvReleaseCapture(&cap);
    
    return 0;
}
