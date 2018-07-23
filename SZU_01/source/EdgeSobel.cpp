//
// Created by 赵绪言 on 2018/7/23.
//

#include "../header/EdgeSobel.h"

CEdgeSobel::CEdgeSobel() = default;

CEdgeSobel::~CEdgeSobel() = default;

void CEdgeSobel::ExtractEdgeSobel() {
    const char *imagename = "/Users/zhaoxuyan/Desktop/2018.7.23上机/Summer-2018.7.23上机素材/1.图像视频读取代码/boldt.jpg";
    //从文件中读入图像
    img = imread(imagename, 0);

    Mat SobelX;
    Mat SobelY;
    int ksize = 3;
    Sobel(img, SobelX, CV_8U, 1, 0, ksize, 1, 0);
    Sobel(img, SobelX, CV_8U, 0, 1, ksize, 1, 0);
    imshow("X", SobelX);
    //此函数等待按键，按键盘任意键就返回
    waitKey(0);
}


void CEdgeSobel::MySobel(Mat InputImg, Mat &Gray32Mat, float *Operator, int OperatorSize) {
//    InputImg 是灰度图像
    Gray32Mat.create(InputImg.size(), CV_32F);
    Mat_<uchar> dataMat = InputImg;
    Mat_<float> dataResultMat = Gray32Mat;
    int oh = OperatorSize / 2;
    int ow = OperatorSize / 2;
    for (int j = 0; j < InputImg.rows; ++j) {
        for (int i = 0; i < InputImg.cols; ++i) {
            float datavalue = 0;
            for (int p = -oh; p <= oh; ++p) {
                for (int q = 0; q <= ow; ++q) {
                    if (p + j < 0 || p + j > InputImg.rows - 1 || q + i < 0 || q + i > InputImg.cols - 1) {
                        continue;
                    }
                    datavalue += dataMat(j + q, i + q) * Operator[(p + oh) * OperatorSize + (q + ow)];
                }
            }
            dataResultMat(j, i) = saturate_cast<float>(datavalue);
        }
    }

}
