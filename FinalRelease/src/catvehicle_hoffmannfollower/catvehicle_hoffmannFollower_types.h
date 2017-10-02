//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: catvehicle_hoffmannFollower_types.h
//
// Code generated for Simulink model 'catvehicle_hoffmannFollower'.
//
// Model version                  : 1.65
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Apr  6 09:34:55 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_catvehicle_hoffmannFollower_types_h_
#define RTW_HEADER_catvehicle_hoffmannFollower_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Vector3 Angular;
} SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_catvehicle_hoffmannFollower_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_catvehicle_hoffmannFollower_ros_time_Time Stamp;
} SL_Bus_catvehicle_hoffmannFollower_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Quaternion Orientation;
} SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollow_PoseWithCovariance_dtasoq_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollow_PoseWithCovariance_dtasoq_

// MsgType=geometry_msgs/PoseWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Pose
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Pose Pose;
} SL_Bus_catvehicle_hoffmannFollow_PoseWithCovariance_dtasoq;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollow_TwistWithCovariance_xhbtyw_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollow_TwistWithCovariance_xhbtyw_

// MsgType=geometry_msgs/TwistWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Twist
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Twist Twist;
} SL_Bus_catvehicle_hoffmannFollow_TwistWithCovariance_xhbtyw;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_catvehicle_hoffmannFollower_std_msgs_Header Header;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_catvehicle_hoffmannFollow_PoseWithCovariance_dtasoq Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_catvehicle_hoffmannFollow_TwistWithCovariance_xhbtyw Twist;
} SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry;

#endif

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_blo_j_T
#define typedef_robotics_slros_internal_blo_j_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_blo_j_T;

#endif                                 //typedef_robotics_slros_internal_blo_j_T

#ifndef typedef_struct_T_catvehicle_hoffmannF_T
#define typedef_struct_T_catvehicle_hoffmannF_T

typedef struct {
  char_T f0[4];
} struct_T_catvehicle_hoffmannF_T;

#endif                                 //typedef_struct_T_catvehicle_hoffmannF_T

#ifndef typedef_struct_T_catvehicle_hoffman_j_T
#define typedef_struct_T_catvehicle_hoffman_j_T

typedef struct {
  char_T f0[8];
} struct_T_catvehicle_hoffman_j_T;

#endif                                 //typedef_struct_T_catvehicle_hoffman_j_T

#ifndef typedef_struct_T_catvehicle_hoffma_jx_T
#define typedef_struct_T_catvehicle_hoffma_jx_T

typedef struct {
  char_T f0[7];
} struct_T_catvehicle_hoffma_jx_T;

#endif                                 //typedef_struct_T_catvehicle_hoffma_jx_T

#ifndef typedef_struct_T_catvehicle_hoffm_jx4_T
#define typedef_struct_T_catvehicle_hoffm_jx4_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_catvehicle_hoffm_jx4_T;

#endif                                 //typedef_struct_T_catvehicle_hoffm_jx4_T

// Parameters (auto storage)
typedef struct P_catvehicle_hoffmannFollower_T_ P_catvehicle_hoffmannFollower_T;

// Forward declaration for rtModel
typedef struct tag_RTM_catvehicle_hoffmannFo_T RT_MODEL_catvehicle_hoffmannF_T;

#endif                                 // RTW_HEADER_catvehicle_hoffmannFollower_types_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
