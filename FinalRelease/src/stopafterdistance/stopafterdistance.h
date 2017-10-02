//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: stopafterdistance.h
//
// Code generated for Simulink model 'stopafterdistance'.
//
// Model version                  : 1.87
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Apr  6 09:37:14 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_stopafterdistance_h_
#define RTW_HEADER_stopafterdistance_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef stopafterdistance_COMMON_INCLUDES_
# define stopafterdistance_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // stopafterdistance_COMMON_INCLUDES_

#include "stopafterdistance_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_stopafterdistance_nav_msgs_Odometry In1;// '<S4>/In1'
  SL_Bus_stopafterdistance_nav_msgs_Odometry varargout_2;
  SL_Bus_stopafterdistance_geometry_msgs_Twist In1_o;// '<S5>/In1'
  SL_Bus_stopafterdistance_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
  char_T cv0[26];
} B_stopafterdistance_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S3>/SourceBlock'
  void *SourceBlock_PWORK_f;           // '<S2>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S1>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S1>/SinkBlock'
  robotics_slros_internal_blo_e_T obj_e;// '<S3>/SourceBlock'
  robotics_slros_internal_blo_e_T obj_n;// '<S2>/SourceBlock'
} DW_stopafterdistance_T;

// Parameters (auto storage)
struct P_stopafterdistance_T_ {
  SL_Bus_stopafterdistance_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                                     //  Referenced by: '<S4>/Out1'

  SL_Bus_stopafterdistance_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S2>/Constant'

  SL_Bus_stopafterdistance_geometry_msgs_Twist Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                         //  Referenced by: '<S5>/Out1'

  SL_Bus_stopafterdistance_geometry_msgs_Twist Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                //  Referenced by: '<S3>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant1'

  real_T Constant_Value_j[2];          // Expression: [0 0]
                                       //  Referenced by: '<Root>/Constant'

  real_T Switch_Threshold;             // Expression: 55
                                       //  Referenced by: '<Root>/Switch'

};

// Real-time Model Data Structure
struct tag_RTM_stopafterdistance_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_stopafterdistance_T stopafterdistance_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_stopafterdistance_T stopafterdistance_B;

// Block states (auto storage)
extern DW_stopafterdistance_T stopafterdistance_DW;

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
  extern void stopafterdistance_initialize(void);
  extern void stopafterdistance_step(void);
  extern void stopafterdistance_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_stopafterdistance_T *const stopafterdistance_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


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
//  '<Root>' : 'stopafterdistance'
//  '<S1>'   : 'stopafterdistance/Publish'
//  '<S2>'   : 'stopafterdistance/Subscribe'
//  '<S3>'   : 'stopafterdistance/Subscribe1'
//  '<S4>'   : 'stopafterdistance/Subscribe/Enabled Subsystem'
//  '<S5>'   : 'stopafterdistance/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_stopafterdistance_h_

//
// File trailer for generated code.
//
// [EOF]
//
