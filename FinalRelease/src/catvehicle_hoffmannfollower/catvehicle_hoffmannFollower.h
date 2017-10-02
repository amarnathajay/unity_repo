//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: catvehicle_hoffmannFollower.h
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
#ifndef RTW_HEADER_catvehicle_hoffmannFollower_h_
#define RTW_HEADER_catvehicle_hoffmannFollower_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef catvehicle_hoffmannFollower_COMMON_INCLUDES_
# define catvehicle_hoffmannFollower_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // catvehicle_hoffmannFollower_COMMON_INCLUDES_ 

#include "catvehicle_hoffmannFollower_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  real_T MultiportSwitch[903];         // '<S5>/Multiport Switch'
  creal_T r[301];
  real_T ys[301];                      // '<S5>/straight line'
  real_T xs[301];                      // '<S5>/straight line'
  SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry In1;// '<S16>/In1'
  SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry varargout_2;
  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
} B_catvehicle_hoffmannFollower_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S6>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S4>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S4>/SinkBlock'
  robotics_slros_internal_blo_j_T obj_l;// '<S6>/SourceBlock'
} DW_catvehicle_hoffmannFollowe_T;

// Parameters (auto storage)
struct P_catvehicle_hoffmannFollower_T_ {
  SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                                               //  Referenced by: '<S16>/Out1'

  SL_Bus_catvehicle_hoffmannFollower_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S6>/Constant'

  SL_Bus_catvehicle_hoffmannFollower_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                      //  Referenced by: '<S1>/Constant'

  real_T k1_Value;                     // Expression: 0
                                       //  Referenced by: '<S2>/k1'

  real_T pathChoice_Value;             // Expression: 1
                                       //  Referenced by: '<S5>/pathChoice '

  real_T radius_Value;                 // Expression: 36.6
                                       //  Referenced by: '<S5>/radius'

  real_T startpoint_Value[2];          // Expression: [0 0]
                                       //  Referenced by: '<S5>/start point'

  real_T len_Value;                    // Expression: 36.6
                                       //  Referenced by: '<S5>/len'

  real_T heading_Value;                // Expression: 0
                                       //  Referenced by: '<S5>/heading'

  real_T refVelocity_Value;            // Expression: 3
                                       //  Referenced by: '<Root>/refVelocity'

  real_T Switch_Threshold;             // Expression: 4
                                       //  Referenced by: '<S2>/Switch'

  real_T k_Value;                      // Expression: .7
                                       //  Referenced by: '<S2>/k'

  real_T Gain_Gain;                    // Expression: -1
                                       //  Referenced by: '<S2>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_catvehicle_hoffmannFo_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_catvehicle_hoffmannFollower_T catvehicle_hoffmannFollower_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_catvehicle_hoffmannFollower_T catvehicle_hoffmannFollower_B;

// Block states (auto storage)
extern DW_catvehicle_hoffmannFollowe_T catvehicle_hoffmannFollower_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void catvehicle_hoffmannFollower_initialize(void);
  extern void catvehicle_hoffmannFollower_step(void);
  extern void catvehicle_hoffmannFollower_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_catvehicle_hoffmannF_T *const catvehicle_hoffmannFollower_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'catvehicle_hoffmannFollower'
//  '<S1>'   : 'catvehicle_hoffmannFollower/Blank Message'
//  '<S2>'   : 'catvehicle_hoffmannFollower/Hoffmann Controller'
//  '<S3>'   : 'catvehicle_hoffmannFollower/Produce waypoints'
//  '<S4>'   : 'catvehicle_hoffmannFollower/Publish'
//  '<S5>'   : 'catvehicle_hoffmannFollower/Select desired path'
//  '<S6>'   : 'catvehicle_hoffmannFollower/Subscribe3'
//  '<S7>'   : 'catvehicle_hoffmannFollower/quaternion2heading'
//  '<S8>'   : 'catvehicle_hoffmannFollower/Hoffmann Controller/calculate delta'
//  '<S9>'   : 'catvehicle_hoffmannFollower/Hoffmann Controller/calculate e'
//  '<S10>'  : 'catvehicle_hoffmannFollower/Produce waypoints/Blank Message1'
//  '<S11>'  : 'catvehicle_hoffmannFollower/Produce waypoints/Publish1'
//  '<S12>'  : 'catvehicle_hoffmannFollower/Produce waypoints/yaw2quat'
//  '<S13>'  : 'catvehicle_hoffmannFollower/Produce waypoints/yaw2quat/Rotation Angles to Quaternions'
//  '<S14>'  : 'catvehicle_hoffmannFollower/Select desired path/circle centered'
//  '<S15>'  : 'catvehicle_hoffmannFollower/Select desired path/straight line'
//  '<S16>'  : 'catvehicle_hoffmannFollower/Subscribe3/Enabled Subsystem'
//  '<S17>'  : 'catvehicle_hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles'
//  '<S18>'  : 'catvehicle_hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S19>'  : 'catvehicle_hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S20>'  : 'catvehicle_hoffmannFollower/quaternion2heading/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_catvehicle_hoffmannFollower_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
