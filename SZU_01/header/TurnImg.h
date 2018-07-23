//
// Created by 赵绪言 on 2018/7/23.
//

#ifndef SZU_01_TURNIMG_H
#define SZU_01_TURNIMG_H
#include "vector"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
class CTurnImg{
private:
    Mat img;
public:
    CTurnImg();
    ~CTurnImg();
    void Turn();
};
#endif //SZU_01_TURNIMG_H
