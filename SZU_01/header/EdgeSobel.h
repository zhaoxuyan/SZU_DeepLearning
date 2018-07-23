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
public:
    CEdgeSobel();

    ~CEdgeSobel();

    void ExtractEdgeSobel();

    void MySobel(Mat InputImg, Mat &Gray32Mat, float *Operator, int OperatorSize);

};

#endif //SZU_01_EDGE_SOBEL_H
