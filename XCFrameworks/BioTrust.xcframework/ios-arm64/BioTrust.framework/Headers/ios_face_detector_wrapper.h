//
// Header Objective-C puro - SEM C++ ou OpenCV
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IOSFaceBoxWrapper : NSObject
@property (nonatomic, assign) float confidence;
@property (nonatomic, assign) float x1;
@property (nonatomic, assign) float y1;
@property (nonatomic, assign) float x2;
@property (nonatomic, assign) float y2;
@end

@interface IOSModelConfigWrapper : NSObject
@property (nonatomic, assign) float scale;
@property (nonatomic, assign) float shiftX;
@property (nonatomic, assign) float shiftY;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int width;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, assign) BOOL orgResize;
@end

@interface IOSFaceDetectorWrapper : NSObject
- (void)setMinFaceSize:(int)size;
- (BOOL)loadModelWithModelPath:(NSString*)modelPath paramPath:(NSString*)paramPath;
- (nullable NSArray<IOSFaceBoxWrapper*>*)detectFacesInImage:(UIImage*)image maxFaces:(int)maxFaces;
@end

@interface IOSLiveDetectorWrapper : NSObject
- (BOOL)loadModelsWithModelPaths:(NSArray<NSString*>*)modelPaths
                      paramPaths:(NSArray<NSString*>*)paramPaths
                         configs:(NSArray<IOSModelConfigWrapper*>*)configs;
- (float)detectLivenessInImage:(UIImage*)image faceBox:(IOSFaceBoxWrapper*)faceBox;
@end

NS_ASSUME_NONNULL_END
