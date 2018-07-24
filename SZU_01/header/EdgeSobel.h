//
// Created by 赵绪言 on 2018/7/23.
//

#ifndef SZU_01_EDGE_SOBEL_H
#define SZU_01_EDGE_SOBEL_H

#include "vector"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class CEdgeSobel {
private:
    Mat img;
    float m_OperatorX[9] = { -1,0,1,-2,0,2,-1,0,1 };
    float m_OperatorY[9] = { -1,-2,-1,0,0,0,1,2,1 };
    int OperatorSize = 3;
public:
    CEdgeSobel();

    ~CEdgeSobel();

    void ExtractEdgeSobel();

    void MySobel(Mat InputImg, Mat &Gray32Mat);

    void MySobelProcess();

};

#endif //SZU_01_EDGE_SOBEL_H
