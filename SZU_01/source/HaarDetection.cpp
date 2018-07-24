#include "../header/HaarDetection.h"
#include "../header/Utils.h"


CHaarDectection::CHaarDectection() {
    // 预定义分类器
    string cascade_path1 = "/Users/zhaoxuyan/anaconda/pkgs/opencv-3.1.0-np112py27_1/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";

    if (cascade_faceDector.empty()) {
        cascade_faceDector.load(cascade_path1);
    }

    if (cascade_faceDector.empty()) {
        cout << "没有找到haarcascade_frontalface_alt.xml文件" << endl;
    }
}

CHaarDectection::~CHaarDectection() = default;

void CHaarDectection::FaceDetection_Cam() {
    Mat img;
    Mat grayscaleFrame;
    VideoCapture cam(0);
    auto frame_width = static_cast<int>(cam.get(CV_CAP_PROP_FRAME_WIDTH));
    auto frame_height = static_cast<int>(cam.get(CV_CAP_PROP_FRAME_HEIGHT));
    VideoWriter video("face_dectection.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));

    if (!cam.isOpened()) exit(0);
    while (true) {
        cam >> img;
        // 灰度化
        cvtColor(img, grayscaleFrame, CV_BGR2GRAY);
        equalizeHist(grayscaleFrame, grayscaleFrame);
        // Rect矩阵（左上角坐标x,y h w）
        vector<Rect> faces;

        // 只检测脸最大的人
        int flag0 = CASCADE_FIND_BIGGEST_OBJECT | CASCADE_DO_ROUGH_SEARCH;
        // 检测多个人
        // int flag1 = CASCADE_SCALE_IMAGE;

        float searchScaleFactor = 1.1f;
        int minNeighbors = 4;
        cascade_faceDector.detectMultiScale(grayscaleFrame, faces, searchScaleFactor, minNeighbors, flag0,
                                            Size(20, 20));
        for (auto &face : faces) {
            Point pt1(face.x + face.width, face.y + face.height);
            Point pt2(face.x, face.y);
            rectangle(img, pt1, pt2, cvScalar(0, 255, 255, 0), 2, 8, 0);
        }
        imshow("Result", img);
        video.write(img);
        if (waitKey(30) >= 0) break;
    }

}

void CHaarDectection::FaceDetection_Img() {
    Mat img;
    Mat grayscaleFrame;

    const char *imagename = "img_1.jpg";
    //从文件中读入图像
    img = imread(imagename);

    // 灰度化
    cvtColor(img, grayscaleFrame, CV_BGR2GRAY);
    equalizeHist(grayscaleFrame, grayscaleFrame);
    // Rect矩阵（左上角坐标x,y h w）
    vector<Rect> faces;

    // 只检测脸最大的人
    int flag0 = CASCADE_FIND_BIGGEST_OBJECT | CASCADE_DO_ROUGH_SEARCH;
    // 检测多个人
    // int flag1 = CASCADE_SCALE_IMAGE;

    float searchScaleFactor = 1.1f;
    int minNeighbors = 2;
    cascade_faceDector.detectMultiScale(grayscaleFrame, faces, searchScaleFactor, minNeighbors, flag0,
                                        Size(20, 20));
    for (auto &face : faces) {
        Point pt1(face.x + face.width, face.y + face.height);
        Point pt2(face.x, face.y);
        rectangle(img, pt1, pt2, cvScalar(0, 255, 255, 0), 2, 8, 0);
    }

    // 在图片上显示人脸数量
    auto faces_num = static_cast<int>(faces.size());
    CUtils utils;
    string res = utils.int2string(faces_num);
    putText(img, "Faces num:" + res, Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255), 2, 8);//在图片上写文字
    imshow("Result", img);
    waitKey(0);
}

