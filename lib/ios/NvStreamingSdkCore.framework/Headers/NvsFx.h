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

/*! \file NvsFx.h
*/
#pragma once

#import "NvsObject.h"
#import "NvsCommonDef.h"

/*! \if ENGLISH
 *  \brief Key frame find mode
 *  \else
 *  \brief 关键帧查找方式
 *  \endif
*/
typedef enum {
    NvsKeyFrameFindModeFlag_Before = 1,            //!< \if ENGLISH find key frame before current time \else 查找当前时间点之前的关键帧\endif
    NvsKeyFrameFindModeFlag_After = 2,             //!< \if ENGLISH find key frame after current time \else 查找当前时间点之后的关键帧\endif
} NvsKeyFrameFindModeFlag;

/*! \if ENGLISH
 *  \brief Region Coordinate System Type
 *  \else
 *  \brief 局部特效坐标系类型
 *  \endif
*/
typedef enum {
    NvsRegionCoordinateSystemType_NDC = 0,              //!< \if ENGLISH NDC coordinate system \else NDC坐标系\endif
    NvsRegionCoordinateSystemType_Timeline = 1          //!< \if ENGLISH timeline coordinate system \else timeline坐标系 \endif
} NvsRegionCoordinateSystemType;

/*! \if ENGLISH
 *  @name Face Warp Effect Strategy
 *  \else
 *  @name 人脸变形特效策略
 *  \endif
 */
typedef enum {
    NvsFaceWarpEffectStrategy_Custom = 0x7FFFFFFF       //!< \if ENGLISH Face warp effect custom strategy \else 人脸变形特效自定义策略 \endif
} NvsFaceWarpEffectStrategy;

@class NvsArbitraryData;
@class NvsFxDescription;
@class NvsParticleSystemContext;
@class NvsARFaceContext;
@class NvsPaintingEffectContext;
@class NvsARSceneManipulate;
@class NvsMaskRegionInfo;


/*! \if ENGLISH
 *  \brief Special effects
 *
 *  Special effects are the basic types of different types of effects such as video effects, audio effects, audio Transition, and video transition. Special effects are a key part of the SDK framework.
 *  Derived from each of the different types of effects of the NvsFx class, users can add, remove, and retrieve via a clip instance, or a timeline instance, or a track instance. At the same time, different API interfaces are provided in the special effects class to set and get the effect parameter types.
 *  \warning NvsFx类中，所有public API都在UI线程使用！！！
 *  \else
 *  \brief 特效
 *
 *  特效类是视频特效(Video Fx)，音频特效(Audio Fx)，音频转场(Audio Transition)，视频转场(Video Transition)等不同类型特效的基类。在SDK框架中，特效是很关键的一部分，
 *  派生自NvsFx类的每种不同类型的特效，或通过片段实例，或时间线实例，或轨道实例来添加，移除和获取。同时，特效类中提供了不同的API接口来设置和获取特效参数类型。
 *  \warning NvsFx类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsFx : NvsObject

@property (readonly) NvsFxDescription *description; //!< \if ENGLISH Special effect description. \else 特效描述 \endif

/*! \if ENGLISH
*   \brief Sets effect parameter of integer type.
*   \param fxParam  Effect parameter integer type,please refer to[NVS_PARAM_TYPE_INT] (@ref PARAM_TYPE).
*   \param val Integer value
*   \else
*   \brief 设置特效参数整数值
*   \param fxParam 特效参数整数类型，请参见[NVS_PARAM_TYPE_INT] (@ref PARAM_TYPE)
*   \param val 整形值
*   \endif
*   \sa getIntVal:
*/
- (void)setIntVal:(NSString *)fxParam val:(int)val;

/*! \if ENGLISH
*   \brief Get effect parameter of integer type.
*   \param fxParam  Effect parameter integer type,please refer to[NVS_PARAM_TYPE_INT] (@ref EFFECT_PARAM_TYPE).
*   \return Returns integer value
*   \else
*   \brief 获得特效参数整数值
*   \param fxParam 特效参数整数类型，请参见[NVS_PARAM_TYPE_INT] (@ref EFFECT_PARAM_TYPE)
*   \return 返回整数值
*   \endif
*   \sa setIntVal:val:
*/
- (int)getIntVal:(NSString *)fxParam;

/*! \if ENGLISH
    *  \brief Sets the integer parameter of NvsFx.
    *  \param fxParam The type of the NvsFx's integer parameter. Please refer to [PARAM_TYPE_INT] (@ref PARAM_TYPE).
    *  \param val An integer value.
    *  \param time point time (In microseconds).
    *  \else
    *  \brief 设置特效的整数参数值
    *  \param fxParam 特效的整数参数的类型。请参见[PARAM_TYPE_INT] (@ref PARAM_TYPE)
    *  \param val 整数
    *  \param time 获取值的时间点 (单位为微秒).
    *  \endif
    *  \sa getIntVal
   */
- (void)setIntValAtTime:(NSString *)fxParam val:(int)val time:(int64_t)time;

/*! \if ENGLISH
 *  \brief Gets the integer parameter of NvsFx.
 *  \param fxParam The type of the NvsFx's integer parameter. Please refer to [PARAM_TYPE_INT].
 *  \param time point time (In microseconds).
 *  \return Returns the integer value.
 *  \else
 *  \brief 获得特效的整数参数值
 *  \param fxParam 特效的整数参数的类型。请参见[PARAM_TYPE_INT] (@ref PARAM_TYPE)
 *  \param time 获取值的时间点 (单位为微秒).
 *  \return 返回获得的整数值
 *  \endif
 *  \sa setIntVal
*/
- (int)getIntValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of float type.
*   \param fxParam  Effect parameter float type,please refer to[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \param val Float value
*   \else
*   \brief 设置特效参数浮点值
*   \param fxParam 特效参数浮点类型，请参见[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \param val 浮点值
*   \endif
*   \sa getFloatVal:
*/
- (void)setFloatVal:(NSString *)fxParam val:(double)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of float type.
*   \param fxParam Effect parameter float type,please refer to[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \return Returns double value
*   \else
*   \brief 获得特效参数浮点值
*   \param fxParam 特效参数浮点数类型，请参见[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \return 返回double值
*   \endif
*   \sa setFloatVal:val:
*/
- (double)getFloatVal:(NSString *)fxParam;

/*! \if ENGLISH
 *  \brief Sets the float parameter of NvsFx.
 *  \param fxParam The type of the NvsFx's float parameter. Please refer to [PARAM_TYPE_FLOAT].
 *  \param val An float value.
 *  \param time point time (In microseconds).
 *  \else
 *  \brief 设置特效的浮点值参数值
 *  \param fxParam 特效的浮点数参数的类型。请参见[PARAM_TYPE_FLOAT] (@ref PARAM_TYPE)
 *  \param val 浮点值
 *  \param time 获取值的时间点 (单位为微秒).
 *  \endif
 *  \sa getFloatVal
*/
- (void)setFloatValAtTime:(NSString *)fxParam val:(double)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the float parameter of NvsFx.
*  \param fxParam The type of the NvsFx's float parameter. Please refer to [PARAM_TYPE_FLOAT].
*  \param time point time (In microseconds).
*  \return Returns the double value.
*  \else
*  \brief 获得特效浮点值参数值
*  \param fxParam 特效的浮点数参数的类型。请参见[PARAM_TYPE_FLOAT] (@ref PARAM_TYPE)
*  \param time 在某个时间点获取值 (单位为微秒).
*  \return 返回获得的double值
*  \endif
*  \sa setFloatVal
*/
- (double)getFloatValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of BOOL type.
*   \param fxParam Effect parameter BOOL type,please refer to[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \param val BOOL value
*   \else
*   \brief 设置特效参数布尔值
*   \param fxParam 特效参数布尔值类型，请参见[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \param val 布尔值
*   \endif
*   \sa getBooleanVal:
*/
- (void)setBooleanVal:(NSString *)fxParam val:(BOOL)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of BOOL type.
*   \param fxParam Effect parameter BOOL type,please refer to[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \return Returns BOOL value,YES means it successfully get the boolean value; NO means it fails.
*   \else
*   \brief 获得特效参数布尔值
*   \param fxParam 特效参数布尔值类型，请参见[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \return 返回布尔值。YES 成功获取特效参数布尔值；NO 获取参数布尔值失败。
*   \endif
*   \sa setBooleanVal:val:
*/
- (BOOL)getBooleanVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Sets the boolean parameter of NvsFx.
*  \param fxParam The type of the NvsFx's float parameter. Please refer to [PARAM_TYPE_BOOL].
*  \param val A boolean value.
*  \param time point time (In microseconds).
*  \else
*  \brief 设置特效布尔值参数值
*  \param fxParam 特效的布尔值参数的类型。请参见[PARAM_TYPE_BOOL] (@ref PARAM_TYPE)
*  \param val 布尔值
*  \param time 在某个时间点获取值 (单位为微秒).
*  \endif
*  \sa getBooleanVal
*/
- (void)setBooleanValAtTime:(NSString *)fxParam val:(BOOL)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the boolean parameter of NvsFx.
*  \param fxParam The type of the NvsFx's float parameter. Please refer to [PARAM_TYPE_BOOL].
*  \param time point time (In microseconds).
*  \return Returns the boolean value.
*  \else
*  \brief 获得特效的布尔值参数值
*  \param fxParam 特效的布尔值参数的类型。请参见[PARAM_TYPE_BOOL] (@ref PARAM_TYPE)
*  \param time 在某个时间点获取值 (单位为微秒).
*  \return 返回获得的布尔值
*  \endif
*  \sa setBooleanVal
*/
- (BOOL)getBooleanValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of string type.
*   \param fxParam Effect parameter string type,please refer to[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \param val String value
*   \else
*   \brief 设置特效参数字符串值
*   \param fxParam 特效参数字符串类型，请参见[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \param val 字符串值
*   \endif
*   \sa getStringVal:
*/
- (void)setStringVal:(NSString *)fxParam val:(NSString *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of string value.
*   \param fxParam Effect parameter string type,please refer to[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \return Returns string value.
*   \else
*   \brief 获得特效参数字符串值
*   \param fxParam 特效参数字符串类型，请参见[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \return 返回字符串指针
*   \endif
*   \sa setStringVal:val:
*/
- (NSString *)getStringVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Sets the string parameter of NvsFx.
*  \param fxParam The type of the NvsFx's string parameter. Please refer to [PARAM_TYPE_STRING].
*  \param val A string value.
*  \param time point time (In microseconds).
*  \else
*  \brief 设置特效字符串参数值
*  \param fxParam 特效的字符串参数的类型。请参见[PARAM_TYPE_STRING] (@ref PARAM_TYPE)
*  \param val 字符串
*  \param time 关键帧的时间 (单位为微秒).
*  \endif
*  \sa getStringVal
*/
- (void)setStringValAtTime:(NSString *)fxParam val:(NSString *)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the string parameter of NvsFx.
*  \param fxParam The type of the NvsFx's string parameter. Please refer to [PARAM_TYPE_STRING].
*  \param time current time (In microseconds).
*  \return Returns the string value.
*  \else
*  \brief 获得特效字符串参数值
*  \param fxParam 特效的字符串参数的类型。请参见[PARAM_TYPE_STRING] (@ref PARAM_TYPE)
*  \param time 获取值的时间 (单位为微秒).
*  \return 返回获得的字符串
*  \endif
*  \sa setStringVal
*/
- (NSString *)getStringValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of color type.
*   \param fxParam Effect parameter color type,please refer to[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \param val Color value
*   \else
*   \brief 设置特效参数颜色值
*   \param fxParam 特效参数颜色类型，请参见[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \param val 颜色值
*   \endif
*   \sa getColorVal:
*/
- (void)setColorVal:(NSString *)fxParam val:(NvsColor *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of color value.
*   \param fxParam Effect parameter color type,please refer to[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \return Returns Color value.
*   \else
*   \brief 获得特效参数颜色值
*   \param fxParam 特效参数颜色类型，请参见[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \return 返回自定义颜色对象
*   \endif
*   \sa setColorVal:val:
*/
- (NvsColor)getColorVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Sets the color parameter of NvsFx.
*  \param fxParam The type of the NvsFx's color parameter. Please refer to [PARAM_TYPE_COLOR].
*  \param val [NvsColor] (@ref NvsColor) Customized color object.
*  \param time point time (In microseconds).
*  \else
*  \brief 设置特效颜色值参数值
*  \param fxParam 特效的颜色参数的类型。请参见[PARAM_TYPE_COLOR] (@ref PARAM_TYPE)
*  \param val [NvsColor] (@ref NvsColor)自定义颜色对象
*  \param time 获取值的时间点 (单位为微秒).
*  \endif
*  \sa getColorVal
*/
- (void)setColorValAtTime:(NSString *)fxParam val:(NvsColor *)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the color parameter of NvsFx.
*  \param fxParam The type of the NvsFx's color parameter. Please refer to [PARAM_TYPE_COLOR].
*  \param time point time (In microseconds).
*  \return Returns the customized color object[NvsColor].
*  \else
*  \brief 获得特效颜色值参数值
*  \param fxParam 特效的颜色参数的类型。请参见[PARAM_TYPE_COLOR] (@ref PARAM_TYPE)
*  \param time 获取值的时间点 (单位为微秒).
*  \return 返回获得的自定义颜色[NvsColor] (@ref NvsColor)对象
*  \endif
*  \sa setColorVal
*/
- (NvsColor)getColorValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of 2D coordinates type.
*   \param fxParam Effect parameter 2D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \param val 2D coordinates value
*   \else
*   \brief 设置特效参数二维坐标
*   \param fxParam 特效参数二维坐标类型，请参见[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \param val 二维坐标
*   \endif
*   \sa getPosition2DVal:
*/
- (void)setPosition2DVal:(NSString *)fxParam val:(NvsPosition2D *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of 2D coordinates value.
*   \param fxParam Effect parameter 2D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \return Returns 2D coordinates value.
*   \else
*   \brief 获得特效参数二维坐标
*   \param fxParam 特效参数二维坐标类型，请参见[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \return 返回二维坐标
*   \endif
*   \sa setPosition2DVal:val:
*/
- (NvsPosition2D)getPosition2DVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Sets the two dimentional coordinates parameter of NvsFx.
*  \param fxParam The type of the NvsFx's two dimentional coordinates parameter. Please refer to [PARAM_TYPE_POSITION2D].
*  \param time point time (In microseconds).
*  \param val Two dimentional coordinates object[NvsPosition2D].
*  \else
*  \brief 设置特效二维坐标参数值
*  \param fxParam 特效的二维坐标参数的类型。请参见[PARAM_TYPE_POSITION2D] (@ref PARAM_TYPE)
*  \param val 二维坐标[NvsPosition2D] (@ref NvsPosition2D)对象
*  \param time 关键帧的时间 (单位为微秒).
*  \endif
*  \sa getPosition2DVal
*  \sa setPosition3DVal
*/
- (void)setPosition2DValAtTime:(NSString *)fxParam val:(NvsPosition2D *)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the two dimentional coordinates parameter of NvsFx.
*  \param fxParam The type of the NvsFx's two dimentional coordinates parameter. Please refer to [PARAM_TYPE_POSITION2D].
*  \param time current time (In microseconds).
*  \return Returns the two dimentional coordinates object[NvPosition2D].
*  \else
*  \brief 获得特效二维坐标参数值
*  \param fxParam 特效的二维坐标参数的类型。请参见[PARAM_TYPE_POSITION2D] (@ref PARAM_TYPE)
*  \param time 关键帧的时间 (单位为微秒).
*  \return 返回获得的二维坐标[NvPosition2D] (@ref NvsPosition2D)对象
*  \endif
*  \sa setPosition2DVal
*  \sa getPosition3DVal
*/
- (NvsPosition2D)getPosition2DValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of 3D coordinates type.
*   \param fxParam Effect parameter 3D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \param val 3D coordinates value
*   \else
*   \brief 设置特效参数三维坐标
*   \param fxParam 特效参数三维坐标类型，请参见[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \param val 三维坐标
*   \endif
*   \sa getPosition3DVal:
*/
- (void)setPosition3DVal:(NSString *)fxParam val:(NvsPosition3D *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of 3D coordinates value.
*   \param fxParam Effect parameter 3D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \return Returns 3D coordinates value.
*   \else
*   \brief 获得特效参数三维坐标
*   \param fxParam 特效参数三维坐标类型，请参见[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \return 返回三维坐标
*   \endif
*   \sa setPosition2DVal:val:
*/
- (NvsPosition3D)getPosition3DVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Sets the three dimentional coordinates parameter of NvsFx.
*  \param fxParam The type of the NvsFx's three dimentional coordinates parameter. Please refer to [PARAM_TYPE_POSITION3D].
*  \param val Three dimentional coordinates object[NvsPosition3D].
*  \param time current time (In microseconds).
*  \else
*  \brief 设置特效三维坐标参数值
*  \param fxParam 特效的三维坐标参数的类型。请参见[PARAM_TYPE_POSITION3D] (@ref PARAM_TYPE)
*  \param val 三维坐标[NvsPosition3D] (@ref NvsPosition3D)对象
*  \param time 关键帧的时间 (单位为微秒).
*  \endif
*  \sa getPosition3DVal
*  \sa setPosition2DVal
*/
- (void)setPosition3DValAtTime:(NSString *)fxParam val:(NvsPosition3D *)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the three dimentional coordinates parameter of NvsFx.
*  \param fxParam The type of the NvsFx's three dimentional coordinates parameter. Please refer to [PARAM_TYPE_POSITION3D].
*  \param time current time (In microseconds).
*  \return Returns the three dimentional coordinates object[NvPosition3D].
*  \else
*  \brief 获得特效三维坐标参数值
*  \param fxParam 特效的三维坐标参数的类型。请参见[PARAM_TYPE_POSITION3D] (@ref PARAM_TYPE)
*  \param time 关键帧的时间 (单位为微秒).
*  \return 返回获得的三维坐标[NvsPosition3D] (@ref NvsPosition3D)对象
*  \endif
*  \sa setPosition3DVal
*  \sa getPosition2DVal
*/
- (NvsPosition3D)getPosition3DValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets effect parameter of menu type.
*   \param fxParam Effect parameter menu type,please refer to[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \param val Menu value
*   \else
*   \brief 设置特效参数菜单值
*   \param fxParam 特效参数菜单类型，请参见[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \param val 字符串
*   \endif
*   \sa getMenuVal:
*/
- (void)setMenuVal:(NSString *)fxParam val:(NSString *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of menu value.
*   \param fxParam Effect parameter menu type,please refer to[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \return Returns menu value.
*   \else
*   \brief 获得特效参数菜单值
*   \param fxParam 特效参数菜单类型，请参见[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \return 返回菜单值
*   \endif
*   \sa setMenuVal:val:
*/
- (NSString *)getMenuVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Sets the menu parameter of NvsFx.
*  \param fxParam The type of the NvsFx's menu parameter. Please refer to [PARAM_TYPE_MENU].
*  \param val A string value.
*  \param time current time (In microseconds).
*  \else
*  \brief 设置特效菜单参数值
*  \param fxParam 特效的菜单参数的类型。请参见[PARAM_TYPE_MENU] (@ref PARAM_TYPE)
*  \param val 字符串
*  \param time 关键帧的时间 (单位为微秒).
*  \endif
*  \sa getMenuVal
*/
- (void)setMenuValAtTime:(NSString *)fxParam val:(NSString *)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Gets the menu parameter of NvsFx.
*  \param fxParam The type of the NvsFx's menu parameter. Please refer to [PARAM_TYPE_MENU].
*  \param time current time (In microseconds).
*  \return Returns the menu value of NvsFx.
*  \else
*  \brief 获得特效菜单参数值
*  \param fxParam 特效的菜单参数的类型。请参见[PARAM_TYPE_MENU] (@ref PARAM_TYPE)
*  \param time 关键帧的时间 (单位为微秒).
*  \return 返回获得的菜单
*  \endif
*  \sa setMenuVal
*/
- (NSString *)getMenuValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*   \brief Sets the effect parameter of custom type.
*   \param fxParam The type of custom data parameter for the effect
*   \param val NvsArbitraryData data value
*   \else
*   \brief 设置自定义数据参数值
*   \param fxParam 特效自定义数据参数的类型
*   \param val NvsArbitraryData数据值
*   \endif
*/
- (void)setArbDataVal:(NSString *)fxParam val:(NvsArbitraryData *)val;

/*! \if ENGLISH
*   \brief Gets the effect parameter of custom type.
*   \param fxParam The type of custom data parameter for the effect
*   \return Returns the custom data of NvsFx.
*   \else
*   \brief 设置自定义数据参数值
*   \param fxParam 特效自定义数据参数的类型
*   \param val NvsArbitraryData数据值
*   \return 返回获得的自定义数据参数值.
*   \endif
*/
- (NvsArbitraryData *)getArbDataVal:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Gets the custom data parameter of NvsFx at certain time.
*  \param fxParam The type of the NvsFx's custom data parameter. Please refer to [PARAM_TYPE_MENU].
*  \param time current time (In microseconds).
*  \return Returns the custom data parameter of NvsFx at certain time.
*  \else
*  \brief 获得特效自定义数据参数值
*  \param fxParam 特效的自定义数据参数值的类型。请参见[PARAM_TYPE_MENU] (@ref PARAM_TYPE)
*  \param time 关键帧的时间 (单位为微秒).
*  \return 返回获得的自定义数据参数值
*  \endif
*  \sa setMenuVal
*/
- (NvsArbitraryData *)getArbDataValAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*  \brief Sets custom data parameter value.
*  \param fxParam The type of custom data parameter for the effect.
*  \param time current time (In microseconds).
*  \param val String.
*  \else
*  \brief 设置自定义数据参数值
*  \param fxParam 特效的自定义数据参数的类型
*  \param val 字符串
*  \param time 关键帧的时间 (单位为微秒).
*  \endif
*  \sa getMenuVal
*/
- (void)setArbDataValAtTime:(NSString *)fxParam val:(NvsArbitraryData *)val time:(int64_t)time;

/*! \if ENGLISH
*  \brief Remove key frame at time from key frame list.
*  \param fxParam The type of custom data parameter for the effect.
*  \param time current time (In microseconds).
*  \return Returns succeeded
*  \else
*  \brief 删除参数某一个时间点的关键帧
*  \param fxParam 特效的数据参数
*  \param time 关键帧的时间 (单位为微秒).
*  \return 返回是否执行成功
*  \endif
*  \sa getMenuVal
*/
- (bool)removeKeyframeAtTime:(NSString *)fxParam time:(int64_t)time;

/*! \if ENGLISH
*  \brief Remove all key frame from key frame list.
*  \param fxParam The type of custom data parameter for the effect.
*  \return Returns succeeded
*  \else
*  \brief 删除参数的所有关键帧
*  \param fxParam 特效的数据参数
*  \return 返回是否执行成功
*  \endif
*/
- (bool)removeAllKeyframe:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Check has key frame list of param.
*  \param fxParam The type of custom data parameter for the effect.
*  \return Returns whether there is a key frame list
*  \else
*  \brief 当前参数是否有关键帧列表
*  \param fxParam 特效的数据参数
*  \return 返回是否有关键帧列表
*  \endif
*/
- (bool)hasKeyframeList:(NSString *)fxParam;

/*! \if ENGLISH
*  \brief Get key frame in list at current time.
*  \param fxParam The type of custom data parameter for the effect.
*  \param time current time(In microseconds).
*  \param flags flag of finding mode,Please refer to [KEY_FRAME_FIND_MODE].
*  \return Returns key frame time before current time,  If there is no key before this time point, return - 1
*  \else
*  \brief 当前参数是否有关键帧列表
*  \param fxParam 特效的数据参数
*  \param time 时间位置 (单位为微秒).
*  \param flags 查找标志位，请参见[KEY_FRAME_FIND_MODE] (@ref KEY_FRAME_FIND_MODE).
*  \return 返回在当前时间位置的关键帧时间位置，如果没有找到对应关键帧返回-1
*  \endif
*/
- (int64_t)findKeyframeTime:(NSString *)fxParam time:(int64_t)time flags:(int)flags;

/*! \if ENGLISH
*   \brief Set the filter intensity.
*   \param intensity The filter intensity value. The value range is generally [0,1]. 0 means the filter has no effect, the default value is 1.
*   \else
*   \brief 设置滤镜的强度
*   \param intensity 滤镜强度值，取值范围一般为[0,1]，为0则滤镜无效果，为1则为默认效果
*   \endif
*   \sa getFilterIntensity
*   \since 2.0.2
*/
-(void)setFilterIntensity:(float)intensity;

/*! \if ENGLISH
*   \brief Gets the filter intensity.
*   \return Returns the filter intensity.
*   \else
*   \brief 获得滤镜的强度
*   \return 返回滤镜的强度值
*   \endif
*   \sa setFilterIntensity:
*   \since 2.0.2
*/
-(float)getFilterIntensity;

/*! \if ENGLISH
 *  \brief Sets the mask of the filter.
 *  \param useMask Wether use mask to limit the filter's region
 *  \else
 *  \brief 设置滤镜遮罩
 *  \param useMask 使用滤镜遮罩，仅在有图像的区域添加滤镜效果
 *  \endif
 *  \sa getFilterMask
 *  \since 2.14.1
 */
-(void)setFilterMask:(bool)useMask;

/*! \if ENGLISH
 *  \brief Gets the usage of the filter's mask.
 *  \return Returns the usage of the filter's mask.
 *  \else
 *  \brief 获得是否使用滤镜遮罩
 *  \return 返回是否使用了滤镜遮罩
 *  \endif
 *  \sa setFilterMask
 *  \since 2.14.1
 */
-(bool)getFilterMask;

/*! \if ENGLISH
 *  \brief Sets whether the filter is regional.
 *  \param regional whether the filter is regional. true means regional, while false means the opposite.
 *  \else
 *  \brief 设置滤镜是否为局部滤镜
 *  \param regional 是否为局部滤镜，true为局部滤镜，false不是
 *  \endif
 *  \sa getRegional
 *  \since 2.10.1
 */
-(void)setRegional:(BOOL)isRegional;

/*! \if ENGLISH
 *  \brief Gets whether the filter is regional.
 *  \return Returns whether the filter is regional.
 *  \else
 *  \brief 获得滤镜是否为局部滤镜
 *  \return 返回滤镜是否为局部滤镜
 *  \endif
 *  \sa setRegional
 *  \since 2.10.1
 */
-(BOOL)getRegional;

/*! \if ENGLISH
 *  \brief Sets whether the regional filter ignore Background.
 *  \param regional whether the regional filter ignores Background. true means ignored, while false means the opposite.
 *  \else
 *  \brief 设置局部滤镜是否消除背景
 *  \param regional 是否为局部滤镜消除背景，true为消除，false不是
 *  \endif
 *  \sa getIgnoreBackground
 *  \since 2.15.1
 */
-(void)setIgnoreBackground:(BOOL)isIgnoreBackground;

/*! \if ENGLISH
 *  \brief Gets whether the regional filter ignores Background.
 *  \return Returns whether the regional filter ignores Background.
 *  \else
 *  \brief 获得局部滤镜是否消除背景
 *  \return 返回局部滤镜是否消除背景
 *  \endif
 *  \sa setIgnoreBackground
 *  \since 2.15.1
 */
-(BOOL)getIgnoreBackground;


/*! \if ENGLISH
 *  \brief Sets whether the regional filter inverse region.
 *  \param regional whether the regional filter inverse region. true means inversed, while false means the opposite.
 *  \else
 *  \brief 设置局部滤镜是否反选区域
 *  \param regional 是否为局部滤镜反选区域，true为反选，false不是
 *  \endif
 *  \sa getInverseRegion
 *  \since 2.15.1
 */
-(void)setInverseRegion:(BOOL)isInverseRegion;

/*! \if ENGLISH
 *  \brief Gets whether the regional filter inverse region.
 *  \return Returns whether the regional filter inverses region.
 *  \else
 *  \brief 获得局部滤镜是否反选区域
 *  \return 返回局部滤镜是否反选区域
 *  \endif
 *  \sa setInverseRegion
 *  \since 2.15.1
 */
-(BOOL)getInverseRegion;

/*! \if ENGLISH
 *  \brief Get the region of this regional filter.
 *  \return Returns the region of this regional filter. It is composed with a series of points, which are in NDC coordinate system.
 *  \else
 *  \brief 获取局部滤镜的控制范围
 *  \return 返回局部滤镜的控制范围，点的坐标在NDC坐标系中
 *  \endif
 *  \sa setRegion:
 *  \since 2.14.0
 */
-(NSArray *)getRegion;

/*! \if ENGLISH
 *  \brief Sets the region of this regional filter.
 *  \param region the effective region of this filter. It is composed with a series of points, which are in NDC coordinate system.
 *  \else
 *  \brief 设置局部滤镜的控制范围
 *  \param region 局部滤镜的控制范围, 由一系列连续的点构成，点的坐标在NDC坐标系中
 *  \endif
 *  \sa getRegion
 *  \since 2.10.1
 */
-(void)setRegion:(NSArray *)region;

/*! \if ENGLISH
 *  \brief Get the region of this regional filter.
 *  \return region the effective region of this filter. It could be series of points, cubic bezier curve or ellipse, which are in NDC coordinate system.
 *  \else
 *  \brief 获取局部滤镜的控制范围
 *  \return region 局部滤镜的控制范围, 构成控制区域的可以是点，贝塞尔曲线或者椭圆，对应的坐标系为NDC坐标系
 *  \endif
 *  \since 2.16.0
*/
-(NvsMaskRegionInfo *)getRegionInfo;

/*! \if ENGLISH
 *  \brief Sets the region of this regional filter.
 *  \param region the effective region of this filter. It could be series of points, cubic bezier curve or ellipse, which are in NDC coordinate system.
 *  \else
 *  \brief 设置局部滤镜的控制范围
 *  \param region 局部滤镜的控制范围, 构成控制区域的可以是点，贝塞尔曲线或者椭圆，对应的坐标系为NDC坐标系
 *  \endif
 *  \since 2.16.0
 */
-(void)setRegionInfo:(NvsMaskRegionInfo *)info;

/*! \if ENGLISH
 *  \brief Sets the region of this regional filter at certain time.
 *  \param region the effective region of this filter. It could be series of points, cubic bezier curve or ellipse, which are in NDC coordinate system.
 *  \else
 *  \brief 设置某时刻局部滤镜的控制范围
 *  \param region 局部滤镜的控制范围, 构成控制区域的可以是点，贝塞尔曲线或者椭圆，对应的坐标系为NDC坐标系
 *  \endif
 *  \since 2.16.0
 */
-(void)setRegionInfoAtTime:(NvsMaskRegionInfo *)info time:(int64_t)time;

/*! \if ENGLISH
 *  \brief Get the region of this regional filter at certain time.
 *  \return region the effective region of this filter. It could be series of points, cubic bezier curve or ellipse, which are in NDC coordinate system.
 *  \else
 *  \brief 获取某时刻局部滤镜的控制范围
 *  \return region 局部滤镜的控制范围, 构成控制区域的可以是点，贝塞尔曲线或者椭圆，对应的坐标系为NDC坐标系
 *  \endif
 *  \since 2.16.1
*/
-(NvsMaskRegionInfo *)getRegionInfoAtTime:(int64_t)time;

/*! \if ENGLISH
 *  \brief Sets the feather width of this regional filter(0-1000).
 *  \param featherWidth feather width of regional filter
 *  \else
 *  \brief 设置局部滤镜的羽化宽度(0-1000)
 *  \param featherWidth 局部滤镜的羽化宽度
 *  \endif
 *  \sa getRegionalFeatherWidth
 *  \since 2.10.1
 */
-(void)setRegionalFeatherWidth:(float)featherWidth;

/*! \if ENGLISH
 *  \brief Gets the feather width of this regional filter.
 *  \return Returns the feather width of this regional filter.
 *  \else
 *  \brief 获得局部滤镜的羽化宽度
 *  \return 返回局部滤镜的羽化宽度
 *  \endif
 *  \sa setRegionalFeatherWidth
 *  \since 2.10.1
 */
-(float)getRegionalFeatherWidth;

/*! \if ENGLISH
 *  \brief Sets the feather width of this regional filter at certain time.
 *  \param featherWidth feather width of regional filter
 *  \param time time of regional filter
 *  \else
 *  \brief 设置局部滤镜的羽化宽度
 *  \param featherWidth 局部滤镜的羽化宽度
 *  \param time 局部滤镜的的时间
 *  \endif
 *  \sa getRegionalFeatherWidthAtTime:
 *  \since 2.16.1
 */
- (void)setRegionalFeatherWidthAtTime:(float)featherWidth time:(int64_t)time;

/*! \if ENGLISH
 *  \brief Gets the feather width of this regional filter at certain time.
 *  \return Returns the feather width of this regional filter at certain time.
 *  \else
 *  \brief 获得某一时刻局部滤镜的羽化宽度
 *  \return 返回某一时刻局部滤镜的羽化宽度
 *  \endif
 *  \sa setRegionalFeatherWidth:time:
 *  \since 2.16.1
 */
- (float)getRegionalFeatherWidthAtTime:(int64_t)time;

/*! \if ENGLISH
 *  \brief Sets the coordinate system of the region.
 *  \param type coordinate system type of the region, NDC as the default.
 *  \else
 *  \brief 设置局部滤镜所在坐标系类型，默认为NDC坐标系
 *  \param coordinateSystem 局部滤镜所在坐标系
 *  \endif
 *  \sa getRegionCoordinateSystemType
 *  \since 2.16.1
 */
-(void)setRegionCoordinateSystemType:(int)type;

/*! \if ENGLISH
 *  \brief Gets the coordinate system of the region.
 *  \return Returns the coordinate system of the region.
 *  \else
 *  \brief 获得局部滤镜所在坐标系类型
 *  \return 返回局部滤镜所在坐标系类型
 *  \endif
 *  \sa setRegionCoordinateSystemType
 *  \since 2.16.1
 */
-(int)getRegionCoordinateSystemType;

/*! \if ENGLISH
*   \brief Gets the particle effect context.
*   \return Returns a pointer to a particle effect context.
*   \else
*   \brief 获得粒子特效上下文
*   \return 返回指向粒子特效上下文的指针
*   \endif
*/
- (NvsParticleSystemContext *)getParticleSystemContext;

/*! \if ENGLISH
 *  \brief Get face effect context pointer.
 *  \return Return face effect context pointer.
 *  \else
 *  \brief 获得人脸特效上下文指针
 *  \return 返回指向人脸特效上下文句柄指针
 *  \endif
*/
- (NvsARFaceContext *)getARFaceContext;

/*! \if ENGLISH
*   \brief Gets the particle effect context.
*   \return Returns a pointer to a hand-drawn effect context.
*   \else
*   \brief 获得手绘特效上下文
*   \return 返回指向手绘特效上下文指针
*   \endif
*/
- (NvsPaintingEffectContext *)getPaintingEffectContext;

/*! \if ENGLISH
 *  \brief Get the AR scene operation pointer.
 *  \return Return the AR scene operation pointer.
 *  \else
 *  \brief 获得AR场景操作指针
 *  \return 返回指向AR场景操作指针
 *  \endif
*/
- (NvsARSceneManipulate *)getARSceneManipulate;

/*! \if ENGLISH
 *  \brief Sets the value of the defined parameter in the expression.
 *  \param varName The parameters defined in the expression
 *  \param varValue The value of a parameter in an expression
 *  \else
 *  \brief 设置表达式中定义参数的值
 *  \param varName 表达式中定义的参数
 *  \param varValue 表达式中参数对应的值
 *  \endif
 *  \since 2.16.1
 */
- (void)setExprVar:(NSString *)varName varValue:(double)varValue;

/*! \if ENGLISH
 *  \brief Gets the value of the defined parameter in the expression.
 *  \param varName The parameters defined in the expression
 *  \return Returns the value of the parameter defined in the expression
 *  \else
 *  \brief 获得表达式中定义参数的值
 *  \param varName 表达式中定义的参数
 *  \return 返回表达式中定义参数的值
 *  \endif
 *  \since 2.16.1
 */
- (double)getExprVar:(NSString *)varName;

/*! \if ENGLISH
 *  \brief Clears the value of the defined parameter in the expression and sets it to the default value of 0.
 *  \param varName The parameters defined in the expression
 *  \else
 *  \brief 清空表达式中定义参数的值，并设置为默认值0
 *  \param varName 表达式中定义的参数
 *  \endif
 *  \since 2.16.1
 */
- (void)clearExprVar:(NSString *)varName;

/*! \if ENGLISH
 *  \brief Clears the value of all parameters defined in the expression and sets it to the default value of 0.
 *  \param varName The parameters defined in the expression
 *  \else
 *  \brief 清空表达式中定义的全部参数的值，并设置为默认值0
 *  \param varName 表达式中定义的参数
 *  \endif
 *  \since 2.16.1
 */
- (void)clearExprVarCtx;
@end
