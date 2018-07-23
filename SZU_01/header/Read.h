//
// Created by 赵绪言 on 2018/7/23.
//

#ifndef SZU_01_READIMG_H
#define SZU_01_READIMG_H

#include "vector"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class CRead {
private:
    Mat img;
    VideoCapture capture;
public:
    CRead();

    ~CRead();

    void Read_Show();

    void Read_Video_FromCam();

    void Read_Video();
};

#endif //SZU_01_READIMG_H
