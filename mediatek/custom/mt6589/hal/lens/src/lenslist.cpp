

#include <utils/Log.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <math.h>

#include "MediaHal.h"

//#include "lens_custom_cfg.h"
//#include "msdk_lens_exp.h"
#include "camera_custom_lens.h"
//#include "lens.h"
//nclude "image_sensor.h"
#include "kd_imgsensor.h"

extern PFUNC_GETLENSDEFAULT pDummy_getDefaultData;

#if defined(SENSORDRIVE)
extern PFUNC_GETLENSDEFAULT pSensorDrive_getDefaultData;
#endif

#if defined(FM50AF)
extern PFUNC_GETLENSDEFAULT pFM50AF_getDefaultData;
#endif

#if defined(MT9P017AF)
extern PFUNC_GETLENSDEFAULT pMT9P017AF_getDefaultData;
#endif
//modified by zhfan, pr450349, porting diablox main camera imx135 VCM driver dw9714a
#if defined(DW9714A)
extern PFUNC_GETLENSDEFAULT pDW9714A_getDefaultData;
#endif
//[begin]496059 zhfan imx135 sunny module lens compatible 2013-07-26
#if defined(DW9714A_LENS50016)
extern PFUNC_GETLENSDEFAULT pDW9714ALens50016_getDefaultData;
#endif
//[end]496059 zhfan


#if defined(OV8825AF)
extern PFUNC_GETLENSDEFAULT pOV8825AF_getDefaultData;
#endif

MSDK_LENS_INIT_FUNCTION_STRUCT LensList[MAX_NUM_OF_SUPPORT_LENS] =
{
	{DUMMY_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},

#if defined(SENSORDRIVE)
	{DUMMY_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},	

    //  for backup lens, need assign correct SensorID
    //{OV5642_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},
#endif

#if defined(OV8825AF)
		{OV8825_SENSOR_ID, OV8825AF_LENS_ID, "OV8825AF", pOV8825AF_getDefaultData},
#endif
#if defined(FM50AF)
	{DUMMY_SENSOR_ID, FM50AF_LENS_ID, "FM50AF", pFM50AF_getDefaultData},
#endif

    //  for new added lens, need assign correct SensorID
#if defined(MT9P017AF)
	{MT9P017MIPI_SENSOR_ID, MT9P017AF_LENS_ID, "MT9P017AF", pMT9P017AF_getDefaultData},
#endif
//modified by zhfan, pr450349, porting diablox main camera imx135 VCM driver dw9714a
#if defined(DW9714A)
    {IMX135_SENSOR_ID, DW9714A_LENS_ID, "DW9714A", pDW9714A_getDefaultData},
#endif
//[begin]496059 zhfan imx135 sunny module lens compatible 2013-07-26
#if defined(DW9714A_LENS50016)
    {IMX135_LENS50016_SENSOR_ID, DW9714A_LENS50016_LENS_ID, "DW9714A_LENS50016", pDW9714ALens50016_getDefaultData},
#endif
//[end]496059 zhfan
//[begin]496059 zhfan imx135 sunny module lens compatible 2013-07-26
#if defined(DW9714A)
    {IMX135TRULY_SENSOR_ID, DW9714A_LENS_ID, "DW9714A", pDW9714A_getDefaultData},
#endif  SENSOR_DRVNAME_IMX135TRULY_MIPI_RAW
//[end]496059 zhfan
    //  for new added lens, need assign correct SensorID

};

UINT32 GetLensInitFuncList(PMSDK_LENS_INIT_FUNCTION_STRUCT pLensList)
{
    memcpy(pLensList, &LensList[0], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT)* MAX_NUM_OF_SUPPORT_LENS);
    return MHAL_NO_ERROR;
} // GetLensInitFuncList()





