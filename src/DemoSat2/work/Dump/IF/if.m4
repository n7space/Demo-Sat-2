divert(-1)
/*
*  This m4 file uses the following diverts:
*    1 for overall structure
*    5 for cast functions for GUI parameter subtypes
*    7 for num functions on Enum types
*    10 for signals
*    20 for functions
*/dnl
include(templates.m4)
divert(-1)
define(`m4_afechwasdriver_afechwas_getvaluecmd_ri',`sunsensordriver_afechwas_getvaluecmd_pi')dnl
define(`m4_afechwasdriver_AfecHwas_GetValueCmd_Ri_provider',`sunsensordriver')dnl
define(`m4_afechwasdriver_interruptmanagement_disableinterrupt_ri',`hwas_interruptmanagement_disableinterrupt_pi')dnl
define(`m4_afechwasdriver_InterruptManagement_DisableInterrupt_Ri_provider',`hwas')dnl
define(`m4_afechwasdriver_interruptmanagement_enableinterrupt_ri',`hwas_interruptmanagement_enableinterrupt_pi')dnl
define(`m4_afechwasdriver_InterruptManagement_EnableInterrupt_Ri_provider',`hwas')dnl
define(`m4_afechwasdriver_interruptsubscriptionmanagement_subscribetointerrupt_ri',`hwas_interruptsubscriptionmanagement_subscribetointerrupt_pi')dnl
define(`m4_afechwasdriver_InterruptSubscriptionManagement_SubscribeToInterrupt_Ri_provider',`hwas')dnl
define(`m4_afechwasdriver_rawmemoryaccess_readword_ri',`hwas_rawmemoryaccess_readword_pi')dnl
define(`m4_afechwasdriver_RawMemoryAccess_ReadWord_Ri_provider',`hwas')dnl
define(`m4_afechwasdriver_rawmemoryaccess_writeword_ri',`hwas_rawmemoryaccess_writeword_pi')dnl
define(`m4_afechwasdriver_RawMemoryAccess_WriteWord_Ri_provider',`hwas')dnl
define(`m4_egse_tc',`manager_tc')dnl
define(`m4_egse_tc_provider',`manager')dnl
define(`m4_hwas_interruptsubscription_interrupt_ri',`interruptproxy_interruptsubscription_interrupt_ri')dnl
define(`m4_hwas_InterruptSubscription_Interrupt_Ri_provider',`interruptproxy')dnl
define(`m4_interruptproxy_interruptsubscription_interrupt_pi_afec',`afechwasdriver_interruptsubscription_interrupt_pi')dnl
define(`m4_interruptproxy_InterruptSubscription_Interrupt_Pi_Afec_provider',`afechwasdriver')dnl
define(`m4_interruptproxy_interruptsubscription_interrupt_pi_uart',`uarthwasdriver_interruptsubscription_interrupt_pi')dnl
define(`m4_interruptproxy_InterruptSubscription_Interrupt_Pi_Uart_provider',`uarthwasdriver')dnl
define(`m4_lidardriver_lidartrigger_returndatacmd_ri',`objectdetector_lidartrigger_returndatacmd_ri')dnl
define(`m4_lidardriver_LidarTrigger_ReturnDataCmd_Ri_provider',`objectdetector')dnl
define(`m4_lidardriver_lidartrigger_returnerrorcmd_ri',`objectdetector_lidartrigger_returnerrorcmd_ri')dnl
define(`m4_lidardriver_LidarTrigger_ReturnErrorCmd_Ri_provider',`objectdetector')dnl
define(`m4_lidardriver_mp6500_initmp6500cmd_ri',`mp6500driver_mp6500_initmp6500cmd_pi')dnl
define(`m4_lidardriver_MP6500_InitMP6500Cmd_Ri_provider',`mp6500driver')dnl
define(`m4_lidardriver_mp6500_setdirectionleftcmd_ri',`mp6500driver_mp6500_setdirectionleftcmd_pi')dnl
define(`m4_lidardriver_MP6500_SetDirectionLeftCmd_Ri_provider',`mp6500driver')dnl
define(`m4_lidardriver_mp6500_setdirectionrightcmd_ri',`mp6500driver_mp6500_setdirectionrightcmd_pi')dnl
define(`m4_lidardriver_MP6500_SetDirectionRightCmd_Ri_provider',`mp6500driver')dnl
define(`m4_lidardriver_mp6500_stepcmd_ri',`mp6500driver_mp6500_stepcmd_pi')dnl
define(`m4_lidardriver_MP6500_StepCmd_Ri_provider',`mp6500driver')dnl
define(`m4_lidardriver_piohwas_getpin_ri',`piohwasdriver_piohwas_getpin_pi')dnl
define(`m4_lidardriver_PioHwas_GetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_lidardriver_piohwas_initpin_ri',`piohwasdriver_piohwas_initpin_pi')dnl
define(`m4_lidardriver_PioHwas_InitPin_Ri_provider',`piohwasdriver')dnl
define(`m4_lidardriver_piohwas_resetpin_ri',`piohwasdriver_piohwas_resetpin_pi')dnl
define(`m4_lidardriver_PioHwas_ResetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_lidardriver_piohwas_setpin_ri',`piohwasdriver_piohwas_setpin_pi')dnl
define(`m4_lidardriver_PioHwas_SetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_lidardriver_tfluna_inittflunacmd_ri',`tflunadriver_tfluna_inittflunacmd_pi')dnl
define(`m4_lidardriver_TfLuna_InitTfLunaCmd_Ri_provider',`tflunadriver')dnl
define(`m4_manager_objectdetection_setenabled',`objectdetector_objectdetection_setenabled')dnl
define(`m4_manager_ObjectDetection_SetEnabled_provider',`objectdetector')dnl
define(`m4_manager_propulsion_changestatecmd_pi',`propulsiondriver_propulsion_changestatecmd_pi')dnl
define(`m4_manager_Propulsion_ChangeStateCmd_Pi_provider',`propulsiondriver')dnl
define(`m4_manager_propulsion_initpropulsioncmd_pi',`propulsiondriver_propulsion_initpropulsioncmd_pi')dnl
define(`m4_manager_Propulsion_InitPropulsionCmd_Pi_provider',`propulsiondriver')dnl
define(`m4_manager_sunsensor_initsunsensorcmd_pi',`sunsensordriver_sunsensor_initsunsensorcmd_pi')dnl
define(`m4_manager_SunSensor_InitSunSensorCmd_Pi_provider',`sunsensordriver')dnl
define(`m4_manager_sunsensor_requestdatacmd_pi',`sunsensordriver_sunsensor_requestdatacmd_pi')dnl
define(`m4_manager_SunSensor_RequestDataCmd_Pi_provider',`sunsensordriver')dnl
define(`m4_manager_hk',`egse_hk')dnl
define(`m4_manager_hk_provider',`egse')dnl
define(`m4_manager_tm',`egse_tm')dnl
define(`m4_manager_tm_provider',`egse')dnl
define(`m4_mp6500driver_piohwas_getpin_ri',`piohwasdriver_piohwas_getpin_pi')dnl
define(`m4_mp6500driver_PioHwas_GetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_mp6500driver_piohwas_initpin_ri',`piohwasdriver_piohwas_initpin_pi')dnl
define(`m4_mp6500driver_PioHwas_InitPin_Ri_provider',`piohwasdriver')dnl
define(`m4_mp6500driver_piohwas_resetpin_ri',`piohwasdriver_piohwas_resetpin_pi')dnl
define(`m4_mp6500driver_PioHwas_ResetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_mp6500driver_piohwas_setpin_ri',`piohwasdriver_piohwas_setpin_pi')dnl
define(`m4_mp6500driver_PioHwas_SetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_objectdetector_lidar_disablecmd_pi',`lidardriver_lidar_disablecmd_pi')dnl
define(`m4_objectdetector_Lidar_DisableCmd_Pi_provider',`lidardriver')dnl
define(`m4_objectdetector_lidar_enablecmd_pi',`lidardriver_lidar_enablecmd_pi')dnl
define(`m4_objectdetector_Lidar_EnableCmd_Pi_provider',`lidardriver')dnl
define(`m4_objectdetector_lidar_initlidarcmd_pi',`lidardriver_lidar_initlidarcmd_pi')dnl
define(`m4_objectdetector_Lidar_InitLidarCmd_Pi_provider',`lidardriver')dnl
define(`m4_objectdetector_objectdetection_report',`manager_objectdetection_report')dnl
define(`m4_objectdetector_ObjectDetection_Report_provider',`manager')dnl
define(`m4_piohwasdriver_rawmemoryaccess_readword_ri',`hwas_rawmemoryaccess_readword_pi')dnl
define(`m4_piohwasdriver_RawMemoryAccess_ReadWord_Ri_provider',`hwas')dnl
define(`m4_piohwasdriver_rawmemoryaccess_writeword_ri',`hwas_rawmemoryaccess_writeword_pi')dnl
define(`m4_piohwasdriver_RawMemoryAccess_WriteWord_Ri_provider',`hwas')dnl
define(`m4_propulsiondriver_piohwas_getpin_ri',`piohwasdriver_piohwas_getpin_pi')dnl
define(`m4_propulsiondriver_PioHwas_GetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_propulsiondriver_piohwas_initpin_ri',`piohwasdriver_piohwas_initpin_pi')dnl
define(`m4_propulsiondriver_PioHwas_InitPin_Ri_provider',`piohwasdriver')dnl
define(`m4_propulsiondriver_piohwas_resetpin_ri',`piohwasdriver_piohwas_resetpin_pi')dnl
define(`m4_propulsiondriver_PioHwas_ResetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_propulsiondriver_piohwas_setpin_ri',`piohwasdriver_piohwas_setpin_pi')dnl
define(`m4_propulsiondriver_PioHwas_SetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_sunsensordriver_afechwas_getvaluecmd_ri',`afechwasdriver_afechwas_getvaluecmd_pi')dnl
define(`m4_sunsensordriver_AfecHwas_GetValueCmd_Ri_provider',`afechwasdriver')dnl
define(`m4_sunsensordriver_afechwas_initinstance_ri',`afechwasdriver_afechwas_initinstance_pi')dnl
define(`m4_sunsensordriver_AfecHwas_InitInstance_Ri_provider',`afechwasdriver')dnl
define(`m4_sunsensordriver_sunsensorreturn_returndatacmd_ri',`manager_sunsensorreturn_returndatacmd_ri')dnl
define(`m4_sunsensordriver_SunSensorReturn_ReturnDataCmd_Ri_provider',`manager')dnl
define(`m4_tflunadriver_tflunareturn_errorreaddatacmd_ri',`lidardriver_tflunareturn_errorreaddatacmd_pi')dnl
define(`m4_tflunadriver_TfLunaReturn_ErrorReadDataCmd_Ri_provider',`lidardriver')dnl
define(`m4_tflunadriver_tflunareturn_readdatacmd_ri',`lidardriver_tflunareturn_readdatacmd_pi')dnl
define(`m4_tflunadriver_TfLunaReturn_ReadDataCmd_Ri_provider',`lidardriver')dnl
define(`m4_tflunadriver_uarthwas_inituartcmd_ri',`uarthwasdriver_uarthwas_inituartcmd_pi')dnl
define(`m4_tflunadriver_UartHwas_InitUartCmd_Ri_provider',`uarthwasdriver')dnl
define(`m4_tflunadriver_uarthwas_readbyteasynccmd_ri',`uarthwasdriver_uarthwas_readbyteasynccmd_pi')dnl
define(`m4_tflunadriver_UartHwas_ReadByteAsyncCmd_Ri_provider',`uarthwasdriver')dnl
define(`m4_tflunadriver_uarthwas_sendbyteasynccmd_ri',`uarthwasdriver_uarthwas_sendbyteasynccmd_pi')dnl
define(`m4_tflunadriver_UartHwas_SendByteAsyncCmd_Ri_provider',`uarthwasdriver')dnl
define(`m4_uarthwasdriver_interruptmanagement_disableinterrupt_ri',`hwas_interruptmanagement_disableinterrupt_pi')dnl
define(`m4_uarthwasdriver_InterruptManagement_DisableInterrupt_Ri_provider',`hwas')dnl
define(`m4_uarthwasdriver_interruptmanagement_enableinterrupt_ri',`hwas_interruptmanagement_enableinterrupt_pi')dnl
define(`m4_uarthwasdriver_InterruptManagement_EnableInterrupt_Ri_provider',`hwas')dnl
define(`m4_uarthwasdriver_interruptsubscriptionmanagement_subscribetointerrupt_ri',`hwas_interruptsubscriptionmanagement_subscribetointerrupt_pi')dnl
define(`m4_uarthwasdriver_InterruptSubscriptionManagement_SubscribeToInterrupt_Ri_provider',`hwas')dnl
define(`m4_uarthwasdriver_piohwas_getpin_ri',`piohwasdriver_piohwas_getpin_pi')dnl
define(`m4_uarthwasdriver_PioHwas_GetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_uarthwasdriver_piohwas_initpin_ri',`piohwasdriver_piohwas_initpin_pi')dnl
define(`m4_uarthwasdriver_PioHwas_InitPin_Ri_provider',`piohwasdriver')dnl
define(`m4_uarthwasdriver_piohwas_resetpin_ri',`piohwasdriver_piohwas_resetpin_pi')dnl
define(`m4_uarthwasdriver_PioHwas_ResetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_uarthwasdriver_piohwas_setpin_ri',`piohwasdriver_piohwas_setpin_pi')dnl
define(`m4_uarthwasdriver_PioHwas_SetPin_Ri_provider',`piohwasdriver')dnl
define(`m4_uarthwasdriver_rawmemoryaccess_readword_ri',`hwas_rawmemoryaccess_readword_pi')dnl
define(`m4_uarthwasdriver_RawMemoryAccess_ReadWord_Ri_provider',`hwas')dnl
define(`m4_uarthwasdriver_rawmemoryaccess_writeword_ri',`hwas_rawmemoryaccess_writeword_pi')dnl
define(`m4_uarthwasdriver_RawMemoryAccess_WriteWord_Ri_provider',`hwas')dnl
define(`m4_uarthwasdriver_uarthwas_readbyteasynccmd_ri',`tflunadriver_uarthwas_readbyteasynccmd_pi')dnl
define(`m4_uarthwasdriver_UartHwas_ReadByteAsyncCmd_Ri_provider',`tflunadriver')dnl
define(`m4_uarthwasdriver_uarthwas_sendbyteasynccmd_ri',`tflunadriver_uarthwas_sendbyteasynccmd_pi')dnl
define(`m4_uarthwasdriver_UartHwas_SendByteAsyncCmd_Ri_provider',`tflunadriver')dnl
define(`m4_env_pps',`manager_pps')dnl
define(`m4_env_pps_provider',`manager')dnl
divert(1)dnl
system taste;
/*
 *
 * Data View
 *
 */
include(dataview.if)

type math = abstract
    integer abs(integer);
    real abs(real);
    integer fix(real);
    real power(real, real);
    integer Shift_Left(integer, integer);
    integer Shift_Right(integer, integer);
    integer ceil(real);
    integer floor(real);
    real float(integer);
    integer round(real);
    real sin(real);
    real cos(real);
    integer trunc(real);
endabstract;

type enum_functions = abstract
undivert(7)
endabstract;


divert(20)
m4_sporadic_itf_handler(
    afechwasdriver,
    afechwas_getvaluecmd_pi,
    AfecHwasInterfaceType_GetValueCmd_Type,
     0,
     1)

// ERROR: Interface "AfecHwas_InitInstance_Pi" in function "AfecHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "InterruptSubscription_Interrupt_Pi" in function "AfecHwasDriver" has unsupported kind: "PROTECTED_OPERATION"









include(afechwasdriver.if)

m4_sporadic_itf_gui_handler(
    egse,
    hk,
    `THouseKeepingReport',
)

m4_sporadic_itf_gui_handler(
    egse,
    tm,
    `TTM',
)


m4_sporadic_itf_gui_provider(
    egse,
    tc,
    `TTC',
    `Egse_tc_request',
)
divert(5)
    TTC cast_Egse_tc_request_to_TTC(Egse_tc_request);
divert(10)


m4_gui_handler(egse)

// ERROR: Interface "InterruptManagement_DisableInterrupt_Pi" in function "HWAS" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "InterruptManagement_EnableInterrupt_Pi" in function "HWAS" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "InterruptSubscriptionManagement_SubscribeToInterrupt_Pi" in function "HWAS" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "RawMemoryAccess_ReadWord_Pi" in function "HWAS" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "RawMemoryAccess_WriteWord_Pi" in function "HWAS" has unsupported kind: "PROTECTED_OPERATION"




include(hwas.if)

m4_c_function(interruptproxy,(InterruptSubscription_Interrupt_Ri,(interrupt),(InterruptNumber),(PARAM_IN), 0),

)

m4_sporadic_itf_handler(
    lidardriver,
    lidar_disablecmd_pi,
    ,
     0,
     1)

m4_sporadic_itf_handler(
    lidardriver,
    lidar_enablecmd_pi,
    ,
     0,
     1)

// ERROR: Interface "Lidar_InitLidarCmd_Pi" in function "LidarDriver" has unsupported kind: "PROTECTED_OPERATION"

m4_sporadic_itf_handler(
    lidardriver,
    tflunareturn_errorreaddatacmd_pi,
    TfLunaReturnInterfaceType_ErrorReadDataCmd_Type,
     0,
     1)

m4_sporadic_itf_handler(
    lidardriver,
    tflunareturn_readdatacmd_pi,
    TfLunaReturnInterfaceType_ReadDataCmd_Type,
     0,
     1)














include(lidardriver.if)

// ERROR: Interface "MP6500_InitMP6500Cmd_Pi" in function "MP6500Driver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "MP6500_SetDirectionLeftCmd_Pi" in function "MP6500Driver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "MP6500_SetDirectionRightCmd_Pi" in function "MP6500Driver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "MP6500_StepCmd_Pi" in function "MP6500Driver" has unsupported kind: "PROTECTED_OPERATION"







include(mp6500driver.if)

m4_c_function(manager,// ERROR: Interface "ObjectDetection_Report" in function "Manager" has unsupported kind: "SPORADIC_OPERATION"

(SunSensorReturn_ReturnDataCmd_Ri,(chOutput),(ConversionData),(PARAM_IN), 0),

(pps,(),(),(), 0),

// ERROR: Interface "tc" in function "Manager" has unsupported kind: "SPORADIC_OPERATION"

)

m4_c_function(objectdetector,// ERROR: Interface "LidarTrigger_ReturnDataCmd_Ri" in function "ObjectDetector" has unsupported kind: "SPORADIC_OPERATION"

// ERROR: Interface "LidarTrigger_ReturnErrorCmd_Ri" in function "ObjectDetector" has unsupported kind: "SPORADIC_OPERATION"

(ObjectDetection_SetEnabled,(isEnabled),(TEnabled),(PARAM_IN), 0),

)

// ERROR: Interface "PioHwas_GetPin_Pi" in function "PioHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "PioHwas_InitPin_Pi" in function "PioHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "PioHwas_ResetPin_Pi" in function "PioHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "PioHwas_SetPin_Pi" in function "PioHwasDriver" has unsupported kind: "PROTECTED_OPERATION"





include(piohwasdriver.if)

m4_timer_handler(propulsiondriver,timer_idle)
// ERROR: Interface "Propulsion_ChangeStateCmd_Pi" in function "PropulsionDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "Propulsion_InitPropulsionCmd_Pi" in function "PropulsionDriver" has unsupported kind: "PROTECTED_OPERATION"







include(propulsiondriver.if)

m4_sporadic_itf_handler(
    sunsensordriver,
    afechwas_getvaluecmd_pi,
    AfecHwasInterfaceType_GetValueCmd_TypeNotify,
     0,
     1)

// ERROR: Interface "SunSensor_InitSunSensorCmd_Pi" in function "SunSensorDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "SunSensor_RequestDataCmd_Pi" in function "SunSensorDriver" has unsupported kind: "PROTECTED_OPERATION"






include(sunsensordriver.if)

// ERROR: Interface "TfLuna_InitTfLunaCmd_Pi" in function "TfLunaDriver" has unsupported kind: "PROTECTED_OPERATION"

m4_sporadic_itf_handler(
    tflunadriver,
    uarthwas_readbyteasynccmd_pi,
    UartHwasInterfaceType_ReadByteAsyncCmd_TypeNotify,
     0,
     1)

m4_sporadic_itf_handler(
    tflunadriver,
    uarthwas_sendbyteasynccmd_pi,
    UartHwasInterfaceType_SendByteAsyncCmd_TypeNotify,
     0,
     1)








include(tflunadriver.if)

// ERROR: Interface "InterruptSubscription_Interrupt_Pi" in function "UartHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "UartHwas_InitUartCmd_Pi" in function "UartHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

// ERROR: Interface "UartHwas_OverrunError_Pi" in function "UartHwasDriver" has unsupported kind: "PROTECTED_OPERATION"

m4_sporadic_itf_handler(
    uarthwasdriver,
    uarthwas_readbyteasynccmd_pi,
    UartHwasInterfaceType_ReadByteAsyncCmd_Type,
     0,
     1)

m4_sporadic_itf_handler(
    uarthwasdriver,
    uarthwas_sendbyteasynccmd_pi,
    UartHwasInterfaceType_SendByteAsyncCmd_Type,
     0,
     1)














include(uarthwasdriver.if)



divert(1)
type assign = abstract
undivert(5)
endabstract;

/*
 *
 * Interface View
 *
 */
signal set_timer(integer);
signal reset_timer();

undivert(10)

undivert(20)

endsystem;

priorityrules
undivert(30)
endpriorityrules;
