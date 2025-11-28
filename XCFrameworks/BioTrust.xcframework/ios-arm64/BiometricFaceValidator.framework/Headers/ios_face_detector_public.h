//
//  ios_face_detector_public.h
//  BiometricFaceValidator
//
//  Created by Bruno Souza on 17/06/25.
//

#ifndef IOS_FACE_DETECTOR_PUBLIC_H
#define IOS_FACE_DETECTOR_PUBLIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

struct FaceBox {
    float confidence;
    float x1, y1, x2, y2;
};

struct ModelConfig {
    float scale, shift_x, shift_y;
    int height, width;
    char name[256];
    bool org_resize;
};

void* CreateFaceDetector(void);
void DestroyFaceDetector(void* detector);
void SetMinFaceSize(void* detector, int size);
int LoadFaceDetectionModel(void* detector, const char* modelPath, const char* paramPath);
int DetectFacesFromUIImage(void* detector, void* uiImage, struct FaceBox* boxes, int maxBoxes);

void* CreateLiveDetector(void);
void DestroyLiveDetector(void* liveDetector);
int LoadLiveModels(void* liveDetector, const char** modelPaths, const char** paramPaths, struct ModelConfig* configs, int modelCount);
float DetectLivenessFromUIImage(void* liveDetector, void* uiImage, struct FaceBox* faceBox);

#ifdef __cplusplus
}
#endif

#endif
