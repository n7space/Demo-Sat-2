/* Body file for function ObjectDetector
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "objectdetector.h"

#define OBJECT_DETECTOR_INVALID_STEP  -10000
#define OBJECT_DETECTOR_MIDDLE_STEP  100
#define OBJECT_DETECTOR_MAX_DATA_SIZE   1000

static bool objectdetector_isEnabled = false;
static bool objectdetector_isInitialized = false;
static int objectdetector_anchorStep = OBJECT_DETECTOR_INVALID_STEP;
static int objectdetector_minStep = 1000000;
static int objectdetector_maxStep = -1000000;
static int objectdetector_stepData[OBJECT_DETECTOR_MAX_DATA_SIZE];
static int objectdetector_lastDistance = 1000;

static asn1SccLidar objectdetector_lidar;
static asn1SccLidarConfig objectdetector_lidarConfig = {
    .mMP6500Config = {
        .mStepPioConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_D,
                           .mPinConfig = 27,
                           .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Output,
                           .mControlConfig = PioHwas_Control_pioHwas_Control_Pio},
        .mDirPioConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_C,
                          .mPinConfig = 19,
                          .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Output,
                          .mControlConfig = PioHwas_Control_pioHwas_Control_Pio},
    },
            .mLeftEndSwitchConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_D,
                                     .mPinConfig = 28,
                                     .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Input,
                                     .mControlConfig = PioHwas_Control_pioHwas_Control_Pio},
            .mRightEndSwitchConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_A,
                                      .mPinConfig = 6,
                                      .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Input,
                                      .mControlConfig = PioHwas_Control_pioHwas_Control_Pio}};

static asn1SccTEnabled objectdetector_debugEnabled = false;
static int64_t objectdetector_debugStep = 0;


static inline int max(const int a, const int b) {
   return a > b ? a : b;
}

static inline int min(const int a, const int b) {
   return a < b ? a : b;
}

void objectdetector_startup(void)
{
   // NOP, initialization on first use
}


void objectdetector_PI_ObjectDetection_SetEnabled( const asn1SccTEnabled * isEnabled)
{
   if (*isEnabled && !objectdetector_isInitialized) {
      objectdetector_RI_Lidar_InitLidarCmd_Pi(&objectdetector_lidar, &objectdetector_lidarConfig);
      objectdetector_isInitialized = true;
   }
   if (*isEnabled == objectdetector_isEnabled) {
      // Avoid unnecessary actions on the fragile LIDAR driver
      return;
   }
   objectdetector_anchorStep = OBJECT_DETECTOR_MIDDLE_STEP;

   if (*isEnabled){
      objectdetector_RI_Lidar_EnableCmd_Pi();
   }
   else {
      objectdetector_RI_Lidar_DisableCmd_Pi();
   }
   objectdetector_isEnabled = *isEnabled;
}

static inline void objectdetector_gatherData() {
   if (objectdetector_maxStep == objectdetector_minStep)
   {
      return;
   }
   int minIndex = objectdetector_minStep;
   int minValue = INT32_MAX;
   for (int i = objectdetector_minStep; i <= objectdetector_maxStep; i++) {
      if (objectdetector_stepData[i] < minValue) {
         minIndex = i;
         minValue = objectdetector_stepData[i];
      }
   }
   asn1SccTObjectDetectionReport report = {
      .position =
         -1.0f + 2.0f *((minIndex - objectdetector_minStep)
         /(float)(objectdetector_maxStep - objectdetector_minStep)),
      .distance = minValue,
      .status = TValidityStatus_vs_ok
   };
   objectdetector_RI_ObjectDetection_Report(&report);
}

void objectdetector_PI_LidarTrigger_ReturnDataCmd_Ri
      (const asn1SccLidarTriggerInterfaceType_ReturnDataCmd_Type *IN_inputparam)

{
   if (objectdetector_debugEnabled) {
      objectdetector_debugStep++;
      if (objectdetector_debugStep % 16 == 0) {
         objectdetector_RI_debug_hk(&(IN_inputparam->data));
      }
   }
   if (!objectdetector_isEnabled) {
      return;
   }
   int step = IN_inputparam->data.mStep;
   step = min(step, OBJECT_DETECTOR_MAX_DATA_SIZE);
   step = max(step, 0);
   if (IN_inputparam->data.mTfLunaData.mDistance > 0) {
      objectdetector_lastDistance = IN_inputparam->data.mTfLunaData.mDistance;
      objectdetector_stepData[step] = IN_inputparam->data.mTfLunaData.mDistance;
   }
   else {
      objectdetector_stepData[step] = objectdetector_lastDistance;
   }

   objectdetector_maxStep = max(objectdetector_maxStep, step);
   objectdetector_minStep = min(objectdetector_minStep, step);
   if (objectdetector_anchorStep == OBJECT_DETECTOR_INVALID_STEP) {
      objectdetector_anchorStep = step;
   }
   else if (objectdetector_anchorStep == step) {
      objectdetector_gatherData();
   }
}

void objectdetector_PI_Debug_SetEnabled( const asn1SccTEnabled * enabled) {
   objectdetector_debugEnabled = *enabled;
}

void objectdetector_PI_UartErrorReporting_OverrunError_Ri( void ) {
  // Ignore for now
}

void objectdetector_PI_LidarTrigger_ReturnErrorCmd_Ri
      (const asn1SccLidarTriggerInterfaceType_ReturnErrorCmd_Type *IN_inputparam)

{
   // Ignore for now
}


