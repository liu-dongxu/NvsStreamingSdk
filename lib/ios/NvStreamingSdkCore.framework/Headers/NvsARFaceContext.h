//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Dec 29. 2016
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>

/*! \if ENGLISH
*   \brief Detects configuration options
*   \else
*   \brief 检测配置选项
*   \endif
*/
typedef enum
{
    NvsObjectTrackingType_Face = 0,        //!< \if ENGLISH Detects faces \else 检测人脸 \endif
    NvsObjectTrackingType_Animal        //!< \if ENGLISH Detects animal \else 检测动物 \endif
} NvsObjectTrackingType;


typedef enum
{
    NvsObjectLandmarkType_Face = 0,        //!< \if ENGLISH face landmark \else 人脸标记点 \endif
    NvsObjectLandmarkType_Animal           //!< \if ENGLISH animal landmark \else 动物标记点 \endif
} NvsObjectLandmarkType;

typedef enum
{
    NvsObjectActionType_Face_Detect = 0x00000001L,              //!< \if ENGLISH face detected \else 检测到脸 \endif
    NvsObjectActionType_Face_Lips_Upward = 0x00000040L,              //!< \if ENGLISH lips upward \else 嘴角上扬 \endif
    NvsObjectActionType_Face_Lips_Pouted = 0x00000080L,           //!< \if ENGLISH face lips pouted \else 嘟嘴 \endif
    NvsObjectActionType_Eye_Blink = 0x00000002L,        //!< \if ENGLISH eye blink \else 眨眼 \endif
    NvsObjectActionType_Mouth_Ah = 0x00000004L,   //!< \if ENGLISH mouth open \else 嘴巴大张 \endif
    NvsObjectActionType_Head_Yaw = 0x00000008L,   //!< \if ENGLISH head yaw \else 摇头 \endif
    NvsObjectActionType_Head_Pitch = 0x00000010L,   //!< \if ENGLISH head pitch \else 点头 \endif
    NvsObjectActionType_Brow_Jump = 0x00000020L,  //!< \if ENGLISH brow jump \else 眉毛挑动 \endif

    NvsObjectActionType_Hand_Detect = 0x00000100L,              //!< \if ENGLISH hand detected \else 检测到手 \endif
    NvsObjectActionType_Hand_OK = 0x00000200L,              //!< \if ENGLISH ok hand \else OK手势 \endif
    NvsObjectActionType_Hand_Scissor = 0x00000400L,           //!< \if ENGLISH scissor hand \else 剪刀手 \endif
    NvsObjectActionType_Hand_Good = 0x00000800L,        //!< \if ENGLISH good hand \else 大拇哥 \endif
    NvsObjectActionType_Hand_Palm = 0x00001000L,   //!< \if ENGLISH hand palm \else 手掌 \endif
    NvsObjectActionType_Hand_Pistol = 0x00002000L,  //!< \if ENGLISH pistol hand \else 手枪手势 \endif
    NvsObjectActionType_Hand_Love = 0x00004000L,              //!< \if ENGLISH love hand \else 爱心手势 \endif
    NvsObjectActionType_Hand_Holdup = 0x00008000L,              //!< \if ENGLISH holdup hand \else 托手手势 \endif
    NvsObjectActionType_Hand_Congratulate = 0x00020000L,           //!< \if ENGLISH congratulate hand \else 恭贺（抱拳) \endif
    NvsObjectActionType_Hand_Finger_Heart = 0x00040000L,        //!< \if ENGLISH finger heart \else 单手比爱心 \endif
    NvsObjectActionType_Hand_Finger_Index = 0x00100000L,   //!< \if ENGLISH finger index \else 食指指尖 \endif
    NvsObjectActionType_Hand_Fist = 0x00200000L,  //!< \if ENGLISH fist \else  拳头手势\endif
    NvsObjectActionType_Hand_666 = 0x00400000L,              //!< \if ENGLISH 666 hand \else 666 \endif
    NvsObjectActionType_Hand_Bless = 0x00800000L,              //!< \if ENGLISH bless \else 双手合十 \endif
    NvsObjectActionType_Hand_ILoveYou = 0x010000000000L,           //!< \if ENGLISH  i love you \else 手势ILoveYou \endif
    NvsObjectActionType_Hand_Ssh = 0x400000000000L        //!< \if ENGLISH shush \else  手势嘘\endif
}NvsObjectDetectActionType;

@protocol NvsARFaceContextDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Notifies that the face props starts loading.
 *  \param itemPath Face props path
 *  \else
 *  \brief 通知人脸道具开始加载
 *  \param itemPath 人脸道具路径
 *  \endif
 */
- (void)notifyFaceItemLoadingBegin:(NSString *)itemPath ;

/*! \if ENGLISH
 *  \brief Notifies the completion of loading face props
 *  \else
 *  \brief 通知人脸道具加载完成
 *  \endif
 */
- (void)notifyFaceItemLoadingFinish ;

/*! \if ENGLISH
     *  \brief Notifies the error of loading face props
     *  \else
     *  \brief 通知人脸道具加载出错
     *  \endif
     */
- (void)notifyFaceItemLoadingFailed:(NSString *)itemPath error:(int) error ;

/*! \if ENGLISH
 *  \brief Notifies that item landmark.
 *  \param landmark object landmark
 *  \param objectCount,
 *  \param objectType (face or animal)
 *  \param timestamp landmark timestamp
 *  \else
 *  \brief 标记点回调
 *  \param landmark 标记点数据
 *  \param landmarkSize 包含标记点的物体数量
 *  \param objectType 包含标记点的物体类型(人脸或者猫脸)
 *  \param timestamp 获取到标记点时间戳
 *  \endif
 */
- (void)notifyObjectLandmark:(NSArray*)landmark size:(int)landmarkSize type:(NvsObjectLandmarkType)type timeStamp:(int64_t)timestamp;

    /*! \if ENGLISH
     *  \brief Notifies the detected of hand/face action type.
     *  \param face/hand action type ref [ACTION_TYPE_XXX]
     *  \else
     *  \brief 通知检测到的人脸/手部动作。ref [ACTION_TYPE_XXX]
     *  \endif
     */
- (void)notifyDetectedAction:(long long)actionType ;
@end

/*!
 *  \if ENGLISH
 *  \brief ARFace context
 *  \warning In the NvsARFaceContext class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief ARFace上下文
 *  \warning NvsARFaceContext类中，所有public API都在UI线程使用！！！
 *  \endif
 */
@interface NvsARFaceContext : NSObject

@property (nonatomic, weak) id<NvsARFaceContextDelegate> delegate;

- (void)setInternalContext:(void *)internalContext;
- (bool)isFaceTracking;
- (bool)isObjectTracking:(NvsObjectTrackingType)trackingType;
- (void)setReloadCurSticker;

@end
