//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Sep 24. 2020
//   Author:        NewAuto video team
//================================================================================

#pragma once
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NvsCommonDef.h"

/*! \anchor HUMAN_DETECTION_FEATURE_CONFIG */
/*!
 *  \if ENGLISH
 *   @name Human detection feature config, used in handle creation.
 *  \else
 *   @name 人体检测句柄创建标志
 *  \endif
 */
//!@{
typedef enum {
    HUMAN_DETECTION_FEATURE_FACE_LANDMARK = 0x00000001,        //!< \if ENGLISH Landmarks on human face \else 人脸点位 \endif
    HUMAN_DETECTION_FEATURE_FACE_ACTION = 0x00000002,          //!< \if ENGLISH Actions of human face \else 人脸动作 \endif
    HUMAN_DETECTION_FEATURE_AVATAR_EXPRESSION = 0x00000004,    //!< \if ENGLISH Avatar Expressions of human face \else 人脸Avatar表情 \endif
    HUMAN_DETECTION_FEATURE_VIDEO_MODE = 0x00000008,           //!< \if ENGLISH Video detection mode \else 视频检测模式 \endif
    HUMAN_DETECTION_FEATURE_IMAGE_MODE = 0x00000010,           //!< \if ENGLISH Image detection mode \else 图像检测模式 \endif
    HUMAN_DETECTION_FEATURE_MULTI_THREAD = 0x00000020,         //!< \if ENGLISH Multi thread detection \else 多线程检测 \endif
    HUMAN_DETECTION_FEATURE_SINGLE_THREAD = 0x00000040,        //!< \if ENGLISH Single thread detection \else 单线程检测 \endif
    HUMAN_DETECTION_FEATURE_EXTRA = 0x00000080                //!< \if ENGLISH Extra features of human face \else 其他人脸特征 \endif
}NvsHumanDetectionFeature;
//!@}

/*! \anchor HUMAN_DETECTION_INTEGER_PARAM */
/*!
 *  \if ENGLISH
 *   @name Human detection integer param
 *  \else
 *   @name 人体检测整形参数
 *  \endif
 */
//!@{
typedef enum {
    HUMAN_DETECTION_FACE_COUNT = 0,                 //!< \if ENGLISH Max face detection count \else 最大检测人脸数 \endif
    HUMAN_DETECTION_FREQUENCY = 1                   //!< \if ENGLISH Detection frequency \else 检测频率 \endif
}HumanDetectionIntergerParam;
//!@}

/*! \anchor HUMAN_DETECTION_FLOAT_PARAM */
/*!
 *  \if ENGLISH
 *   @name Human detection float param
 *  \else
 *   @name 人体检测浮点参数
 *  \endif
 */
//!@{
typedef enum {
    HUMAN_DETECTION_CAMERA_FOVY = 0,                //!< \if ENGLISH Camera fovy \else 相机FOVY \endif
    HUMAN_DETECTION_LANDMARKS_SMOOTH_THRESH = 1,    //!< \if ENGLISH Landmarks smooth thresh \else 点位平滑阈值 \endif
    HUMAN_DETECTION_PE_RIGID_SMOOTH_THRESH = 2,     //!< \if ENGLISH Rigid transform smooth thresh \else 刚体变换平滑阈值 \endif
    HUMAN_DETECTION_SNAP_MOUTH_THRESH = 3,          //!< \if ENGLISH Snap mouth thresh \else 合嘴阈值 \endif
    HUMAN_DETECTION_MIN_RATIO = 4                   //!< \if ENGLISH Min face ratio \else 最小检测人脸屏占比 \endif
}NvsHumanDetectionFloatParam;
//!@}

/*! \anchor HUMAN_DETECTION_BOOLEAN_PARAM */
/*!
 *  \if ENGLISH
 *   @name Human detection boolean param
 *  \else
 *   @name 人体检测布尔参数
 *  \endif
 */
//!@{
typedef enum {
    HUMAN_DETECTION_LANDMARKS_SMOOTH = 0,           //!< \if ENGLISH Enable landmarks smooth \else 开启点位平滑 \endif
    HUMAN_DETECTION_PE_RIGID_SMOOTH = 1,            //!< \if ENGLISH Enable rigid transform smooth \else 开启刚体变换平滑 \endif
    HUMAN_DETECTION_PE_RIGID_TRANSFORM = 2,         //!< \if ENGLISH Do rigid transform only \else 只做刚体变换 \endif
    HUMAN_DETECTION_SNAP_MOUTH = 3,                 //!< \if ENGLISH Snap mouth \else 开启合嘴 \endif
    HUMAN_DETECTION_RESET_TRACKING = 4              //!< \if ENGLISH Reset tracking \else 重新跟踪 \endif
}NvHumanDetectionBooleanParam;
//!@}

/*! \anchor HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT */
/*!
 *  \if ENGLISH
 *   @name Human detection video frame pixel format
 *  \else
 *   @name 人体检测图像格式
 *  \endif
 */
//!@{
typedef enum {
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_NV21 = 0,          //!< \if ENGLISH YUV  4:2:0   12bpp (2 channels, one channel is a continuous luminance channel, and the other channel is a VU component interlaced) \else  YUV  4:2:0   12bpp ( 2通道, 一个通道是连续的亮度通道, 另一通道为VU分量交错 ) \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_NV12 = 1,          //!< \if ENGLISH YUV  4:2:0   12bpp (2 channels, one channel is a continuous luminance channel, and the other channel is a UV component interlaced) \else  YUV  4:2:0   12bpp ( 2通道, 一个通道是连续的亮度通道, 另一通道为UV分量交错 ) \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_YUV420 = 2,        //!< \if ENGLISH YUV  4:2:0   12bpp (3 channels, one luminance channel, the other two are U component and V component channels. All channels are continuous) \else  YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另两个为U分量和V分量通道, 所有通道都是连续的 ) \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_RGBA8 = 3,         //!< \if ENGLISH RGBA 32bpp \else  RGBA 32bpp \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_BGRA8 = 4,         //!< \if ENGLISH BGRA 32bpp \else  BGRA 32bpp \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_RGB8 = 5,          //!< \if ENGLISH RGB 24bpp \else  RGB 24bpp \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_BGR8 = 6,          //!< \if ENGLISH BGR 24bpp \else  BGR 24bpp \endif
    HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT_GRAY8 = 7          //!< \if ENGLISH GRAY 8bpp \else  GRAY 8bpp \endif
}NvsHumanDetectionVideoFramePixelFormat;
//!@}

/*! \anchor HUMAN_DETECTION_DETECTION_CONFIG */
/*!
 *  \if ENGLISH
 *   @name Human detection config used when detecting.
 *  \else
 *   @name 人体检测时设置的标志位
 *  \endif
 */
//!@{
typedef enum {
    HUMAN_DETECTION_FACE_FEATURE_2D = 0x00000001,                //!< \if ENGLISH Face landmarks detection \else 人脸点位检测 \endif
    HUMAN_DETECTION_FACE_FEATURE_3D = 0x00000002,                //!< \if ENGLISH Face pose estimation \else 人脸姿态检测 \endif
    HUMAN_DETECTION_FACE_FEATURE_FULL = 0x00000003               //!< \if ENGLISH All face feature \else 所有人脸相关检测 \endif
}NvsHumanDetectionFaceFeatureType;


typedef enum {
    HUMAN_DETECTION_FACE_ACTION_EYE_BLINK = 0x00000001,          //!< \if ENGLISH Eye blink \else 眨眼 \endif
    HUMAN_DETECTION_FACE_ACTION_LIPS_PART = 0x00000002,          //!< \if ENGLISH Lips part \else 张嘴 \endif
    HUMAN_DETECTION_FACE_ACTION_YAW = 0x00000004,                //!< \if ENGLISH Shake head \else 摇头 \endif
    HUMAN_DETECTION_FACE_ACTION_PITCH = 0x00000008,              //!< \if ENGLISH Nod \else 点头 \endif
    HUMAN_DETECTION_FACE_ACTION_BROW_JUMP = 0x00000010,          //!< \if ENGLISH Raise brow \else 挑眉 \endif
    HUMAN_DETECTION_FACE_ACTION_FULL = 0x0000001F                //!< \if ENGLISH All face actions \else 所有人脸动作 \endif
}NvsHumanDetectionFaceAction;

typedef enum {
    HUMAN_DETECTION_AVATAR_EXPRESSION = 0x00000001,            //!< \if ENGLISH Avatar expression \else Avatar表情 \endif
}NvsHumanDetectionAvartaType;
//!@}

NVS_EXPORT @interface NvsDetectionPosition2D : NSObject

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;

@end

NVS_EXPORT @interface NvsDetectionPosition3D : NSObject

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat z;

@end

NVS_EXPORT @interface NvsDetectionConfig : NSObject

@property (nonatomic, assign) int64_t faceFeature;
@property (nonatomic, assign) int64_t faceAction;
@property (nonatomic, assign) int64_t avatarExpression;

@end

NVS_EXPORT @interface NvsFaceData2D : NSObject

@property (assign, nonatomic) NvsRect bbox;
@property (strong, nonatomic) NSArray <NvsDetectionPosition2D *>*points;
@property (strong, nonatomic) NSArray *visibilities;
@property (assign, nonatomic) CGFloat yaw;
@property (assign, nonatomic) CGFloat pitch;
@property (assign, nonatomic) CGFloat roll;

@end

NVS_EXPORT @interface NvsFaceData3D : NSObject

@property (strong, nonatomic) NSArray <NvsDetectionPosition3D *>*vertices;
@property (strong, nonatomic) NvsDetectionPosition3D *trans;
@property (strong, nonatomic) NvsDetectionPosition3D *rot;

@end

NVS_EXPORT @interface NvsFaceFeature : NSObject

@property (assign, nonatomic) NSInteger faceId;
@property (assign, nonatomic) CGFloat score;
@property (strong, nonatomic) NvsFaceData2D* faceData2D;
@property (strong, nonatomic) NvsFaceData3D* faceData3D;
@property (strong, nonatomic) NSArray *actions;
@property (strong, nonatomic) NSArray *avatarExpressions;

@end


NVS_EXPORT @interface NvsHumanFeature : NSObject

@property(nonatomic, strong) NSMutableArray<NvsFaceFeature *>*faceFeatureArray;

- (NSUInteger)getFaceFeatureCount;

- (void)addFaceFeatureArray:(NvsFaceFeature *)faceFeature;

- (void)removeFaceFeatureArrayByIndexes:(NSUInteger)index;

@end

NVS_EXPORT @interface NvsHumanDetectionHandle : NSObject

@property(assign, nonatomic) int64_t humanDetectHandle;

/*! \if ENGLISH
 *  \brief Set integer parameter value.
 *  \param param Parameter needs to be set, please refer to [HUMAN_DETECTION_INTEGER_PARAM].
 *  \param value Value set to the param.
 *  \else
 *  \param param 需要设置的参数, 请参见[人体检测整形参数](@ref HUMAN_DETECTION_INTEGER_PARAM).
 *  \param value 设置的参数值.
 *  \endif
 *  \since 2.17.2
 */
- (void)setDetectionIntegerParam:(int)param value:(int)value;

/*! \if ENGLISH
 *  \brief Set integer parameter value.
 *  \param param Parameter needs to be set, please refer to [HUMAN_DETECTION_FLOAT_PARAM].
 *  \param value Value set to the param.
 *  \else
 *  \param param 需要设置的参数, 请参见[人体检测浮点参数](@ref HUMAN_DETECTION_FLOAT_PARAM).
 *  \param value 设置的参数值.
 *  \endif
 *  \since 2.17.2
 */
- (void)setDetectionFloatParam:(int)param value:(float)value;

/*! \if ENGLISH
 *  \brief Set integer parameter value.
 *  \param param Parameter needs to be set, please refer to [HUMAN_DETECTION_BOOLEAN_PARAM].
 *  \param value Value set to the param.
 *  \else
 *  \param param 需要设置的参数, 请参见[人体检测布尔参数](@ref HUMAN_DETECTION_BOOLEAN_PARAM).
 *  \param value 设置的参数值.
 *  \endif
 *  \since 2.17.2
 */
- (void)setDetectionBooleanParam:(int)param value:(BOOL)value;

/*! \if ENGLISH
 *  \brief Detect human features.
 *  \param imageBuffer Buffer where image is stored.
 *  \param pixelFormat Pixel format, please refer to [HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT].
 *  \param imageWidth Image width.
 *  \param imageHeight Image height.
 *  \param imageStride Image stride in bytes.
 *  \param orientation Head orientation, the angle the image needs to be rotated clockwise to make sure the head is upward.
 *  \param config Features needs to be detected, please refer to [HUMAN_DETECTION_DETECTION_CONFIG].
 *  \return Returns features detected.
 *  \else
 *  \brief 检测人体特征.
 *  \param imageBuffer 图像地址.
 *  \param pixelFormat 图像格式，请参见[人体检测图像格式](@ref HUMAN_DETECTION_VIDEO_FRAME_PIXEL_FORMAT).
 *  \param imageWidth 图像宽度.
 *  \param imageHeight 图像高度.
 *  \param imageStride 图像跨度，以字节为单位.
 *  \param orientation 人脸朝向，顺时针旋转多少度可以使人脸朝上.
 *  \param config 需要检测的特征配置，请参见[人体检测时设置的标志位](@ref HUMAN_DETECTION_DETECTION_CONFIG).
 *  \return Returns features detected.
 *  \endif
 *  \since 2.17.2
 */
- (NvsHumanFeature*)detect:(void *)imageBuffer pixelFormat:(int)pixelFormat
                                                   imageWidth:(int)imageWidth
                                                  imageHeight:(int)imageHeight
                                                  imageStride:(int)imageStride
                                                  orientation:(int)orientation
                                                  config:(NvsDetectionConfig*)config;

@end
