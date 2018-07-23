//
// Created by 赵绪言 on 2018/7/23.
//

#include "../header/TurnImg.h"

CTurnImg::CTurnImg() = default;

CTurnImg::~CTurnImg() = default;

void CTurnImg::Turn() {
    // 原始图片
    const char *imagename = "/Users/zhaoxuyan/Desktop/2018.7.23上机/Summer-2018.7.23上机素材/1.图像视频读取代码/boldt.jpg";
    //从文件中读入图像
    img = imread(imagename);

    // 创建与原图像同样大小类型的图像
    int rows = img.rows;
    int cols = img.cols;
    Mat result;
    result.create(rows, cols, img.type());

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            result.at<Vec3b>(i, j) = img.at<Vec3b>(i, cols - j - 1);//向右翻转
//            result.at<Vec3b>(i, j) = img.at<Vec3b>(rows - i - 1, j);//向下翻转
//            result.at<Vec3b>(i, j) = img.at<Vec3b>(rows - i - 1, cols - j - 1);//同时向右向下翻转
        }
    }

    imshow("pre", img);
    imshow("result", result);
    waitKey(0);

}
