//
// Created by 赵绪言 on 2018/7/23.
//

#ifndef SZU_01_HAARDETECTION_H
#define SZU_01_HAARDETECTION_H


#include "vector"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class CHaarDectection {
public:
    CascadeClassifier cascade_faceDector;
public:
    CHaarDectection();

    ~CHaarDectection();

    void FaceDetection_Cam();

    void FaceDetection_Img();
};

#endif //SZU_01_HAARDETECTION_H

