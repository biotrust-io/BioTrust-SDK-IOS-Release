//
//  ios_face_detector_impl.h
//  BiometricFaceValidator
//
//  Created by Bruno Souza on 17/06/25.
//
#ifndef IOS_FACE_DETECTOR_IMPL_H
#define IOS_FACE_DETECTOR_IMPL_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

struct FaceBoxCpp {
    float confidence;
    float x1, y1, x2, y2;
};

struct ModelConfigCpp {
    float scale, shift_x, shift_y;
    int height, width;
    std::string name;
    bool org_resize;
};

class IOSFaceDetector {
public:
    IOSFaceDetector();
    ~IOSFaceDetector();
    void SetMinFaceSize(int size);
    int LoadModel(const std::string& modelPath, const std::string& paramPath);
    int Detect(cv::Mat& src, std::vector<FaceBoxCpp>& boxes);

private:
    void* net_;
    int input_size_ = 192;
    float threshold_ = 0.6f;
    const float mean_val_[3] = {104.f, 117.f, 123.f};
    int thread_num_ = 2;
    int min_face_size_ = 64;
};

class IOSLive {
public:
    IOSLive();
    ~IOSLive();
    int LoadModels(const std::vector<std::string>& modelPaths,
                   const std::vector<std::string>& paramPaths,
                   const std::vector<ModelConfigCpp>& configs);
    float Detect(cv::Mat& src, FaceBoxCpp& box);

private:
    cv::Rect CalculateBox(FaceBoxCpp& box, int w, int h, ModelConfigCpp& config);
    std::vector<void*> nets_;
    std::vector<ModelConfigCpp> configs_;
    int model_num_ = 0;
    int thread_num_ = 2;
};

#endif

