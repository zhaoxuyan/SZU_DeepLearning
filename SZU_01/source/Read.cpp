//
// Created by 赵绪言 on 2018/7/23.
//
#include "../header/Read.h"

CRead::CRead() = default;

CRead::~CRead() = default;

void CRead::Read_Show() {
    const char *imagename = "/Users/zhaoxuyan/Desktop/SZU DeepLearning/2018.7.23上机/Summer-2018.7.23上机素材/1.图像视频读取代码/boldt.jpg";
    //从文件中读入图像
    img = imread(imagename);
    //如果读入图像失败
    if (img.empty()) {
        fprintf(stderr, "Can not load image %s\n", imagename);
        exit(0);
    }
    //显示图像
    namedWindow("image", 1);
    cout << "函数功能：读入并显示和保存一张图像" << endl;
    imwrite("save.jpg", img);
    imshow("image", img);
    //此函数等待按键，按键盘任意键就返回
    waitKey(0);
}

void CRead::Read_Video_FromCam() {
//    string filename = "/Users/zhaoxuyan/Desktop/2018.7.23上机/Summer-2018.7.23上机素材/1.图像视频读取代码/face_test.avi";
//    VideoCapture capture(filename);

    VideoCapture capture(0);

    if (!capture.isOpened())//检查摄像头是否成功打开
    {
        printf("视频没有读取成功\n");
        exit(0);
    }
    //这里必须两个一起设置才能生效，宽和高
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 1920);//1080);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);//1080);
    //capture.set(CV_CAP_PROP_SHARPNESS,100);//1080);

    Mat frame;//当前视频帧

    int i = 0;
    while (true) {
        if (!capture.read(frame)) {
            break;
        }
        imshow("video", frame);
        waitKey(30);
        if (i++ > 100) {
            break;
        }
    }
}


void CRead::Read_Video() {
    //string filename="face_test.avi";
    //VideoCapture capture(filename);

    string filename = "/Users/zhaoxuyan/Downloads/画乌龟.mp4";//打开的视频文件
    capture.open(filename);

    double rate = capture.get(CV_CAP_PROP_FPS);//获取视频文件的帧率
    int delay = cvRound(1000.000 / rate);

    if (!capture.isOpened())//判断是否打开视频文件
    {
        printf("离开\n");
        exit(0);
    } else {
        while (true) {
            Mat frame;
            capture >> frame;//读出每一帧的图像
            if (frame.empty()) break;
            imshow("处理前视频", frame);
            //processiamge(frame);
            imshow("处理后视频", frame);
            waitKey(delay);
        }
    }


}


