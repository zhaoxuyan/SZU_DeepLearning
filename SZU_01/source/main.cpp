//
// Created by 赵绪言 on 2018/7/23.
//
#include "../header/HaarDetection.h"
#include "../header/Read.h"
#include "../header/TurnImg.h"
#include "../header/EdgeSobel.h"


int main() {
    // 读图片、Camera、视频
    CRead cRead;
    //cRead.Read_Show();
    //cRead.Read_Video();

    // 左右翻转图片
    CTurnImg cTurnImg;
    //cTurnImg.Turn();

    // 边缘提取——Sobel算子
    CEdgeSobel edgeSobel;
    edgeSobel.MySobelProcess();
    // edgeSobel.ExtractEdgeSobel();

    // 人脸检测
    CHaarDectection haarDectection;
    // 摄像头实时检测人脸
    //haarDectection.FaceDetection_Cam();
    // 静态照片检测人脸
    // haarDectection.FaceDetection_Img();


    return 0;
}
