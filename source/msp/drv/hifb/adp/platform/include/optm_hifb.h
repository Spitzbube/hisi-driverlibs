/******************************************************************************
  Copyright (C), 2001-2013, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : optm_hifb.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2013/01/29
Last Modified :
Description   :
Function List :
History       :
******************************************************************************/
#ifndef HI_BUILD_IN_BOOT
#include "hi_type.h"
#include "hi_common.h"
#include "hifb_drv_common.h"
#else
#include "hifb_debug.h"
#endif


#ifndef __OPTM_HIFB_H_H__
#define __OPTM_HIFB_H_H__

typedef struct tagOPTM_GFX_CSC_PARA_S
{
	HI_U32               u32Bright;
    HI_U32               u32Contrast;
    HI_U32               u32Saturation;
    HI_U32               u32Hue;
    HI_U32               u32Kr;
    HI_U32               u32Kg;
    HI_U32               u32Kb;
}OPTM_GFX_CSC_PARA_S;

typedef enum tagOPTM_GFX_GP_E
{
	OPTM_GFX_GP_0 = 0x0,/** process gfx0,gfx1,gfx2,gfx3*/
	OPTM_GFX_GP_1,		/** process gfx4,gfx5                */
	OPTM_GFX_GP_BUTT
}OPTM_GFX_GP_E;

typedef struct tagOPTM_GFX_OFFSET_S
{
    HI_U32 u32Left;    /*left offset */
    HI_U32 u32Top;     /*top offset */
    HI_U32 u32Right;   /*right offset */
    HI_U32 u32Bottom;  /*bottom offset */
}OPTM_GFX_OFFSET_S;



/** csc state*/
typedef enum tagOPTM_CSC_STATE_E
{
    OPTM_CSC_SET_PARA_ENABLE = 0x0, 
    OPTM_CSC_SET_PARA_RGB,       
    OPTM_CSC_SET_PARA_BGR,
    OPTM_CSC_SET_PARA_CLUT,
    OPTM_CSC_SET_PARA_CbYCrY,
    OPTM_CSC_SET_PARA_YCbYCr,
    OPTM_CSC_SET_PARA_BUTT 
} OPTM_CSC_STATE_E;

typedef enum optm_COLOR_SPACE_E
{
    OPTM_CS_UNKNOWN = 0,
    
    OPTM_CS_BT601_YUV_LIMITED,/* BT.601 */
    OPTM_CS_BT601_YUV_FULL,
    OPTM_CS_BT601_RGB_LIMITED,
    OPTM_CS_BT601_RGB_FULL,    

    OPTM_CS_BT709_YUV_LIMITED,/* BT.709 */
    OPTM_CS_BT709_YUV_FULL,
    OPTM_CS_BT709_RGB_LIMITED,
    OPTM_CS_BT709_RGB_FULL,
    
    OPTM_CS_BUTT
} OPTM_COLOR_SPACE_E;



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            initial operation
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
typedef struct
{
	/*gfx init*/
	/*CNcomment:ͼ�γ�ʼ��*/
	HI_S32 (*OPTM_GfxInit)(HI_VOID);

	/*gfx deinit*/
	/*CNcomment:ͼ��ȥ��ʼ��*/
	HI_S32 (*OPTM_GfxDeInit)(HI_VOID);

	/*open layer*/
	/*CNcomment:ͼ���*/
	HI_S32 (*OPTM_GfxOpenLayer)(HIFB_LAYER_ID_E enLayerId);

	/*close layer*/
	/*CNcomment:ͼ��ر�*/
	HI_S32 (*OPTM_GfxCloseLayer)(HIFB_LAYER_ID_E enLayerId);

	/*enable/disable layer*/
	/*CNcomment:ͼ��ʹ�ܻ��߷�ʹ��*/
	HI_S32 (*OPTM_GfxSetEnable)(HIFB_LAYER_ID_E enLayerId, HI_BOOL bEnable);

	/*mask layer*/
	/*CNcomment:�Ƿ�����ͼ��*/
	HI_S32 (*OPTM_GfxMaskLayer)(HIFB_LAYER_ID_E enLayerId, HI_BOOL bMask);

	/*set layer address*/
	/*CNcomment:����ͼ����ʾ��ַ*/
	HI_S32 (*OPTM_GfxSetLayerAddr)(HIFB_LAYER_ID_E enLayerId, HI_U32 u32Addr);

	/*set layer stride*/
	/*CNcomment:����ͼ���о�*/
	HI_S32 (*OPTM_GfxSetLayerStride)(HIFB_LAYER_ID_E enLayerId, HI_U32 u32Stride);

	/*set layer data format*/
	/*CNcomment:����ͼ�����ظ�ʽ*/
	HI_S32 (*OPTM_GfxSetLayerDataFmt)(HIFB_LAYER_ID_E enLayerId, HIFB_COLOR_FMT_E enDataFmt);

	HI_S32 (*OPTM_GfxSetColorReg)(HIFB_LAYER_ID_E u32LayerId, HI_U32 u32OffSet, HI_U32 u32Color, HI_S32 UpFlag);

	/*wait for vertical blank*/
	/*CNcomment:�ȴ���ֱ����*/
	HI_S32 (*OPTM_GfxWaitVBlank)(HIFB_LAYER_ID_E u32LayerId);

	/*set layer deflick level*/
	/*CNcomment:���ÿ�������*/
	HI_S32 (*OPTM_GfxSetLayerDeFlicker)(HIFB_LAYER_ID_E enLayerId, HIFB_DEFLICKER_S *pstDeFlicker);

	/*set layer alpha*/
	/*CNcomment:����ͼ��alpha ֵ*/
	HI_S32 (*OPTM_GfxSetLayerAlpha)(HIFB_LAYER_ID_E enLayerId, HIFB_ALPHA_S *pstAlpha);

	/*set layer rect*/
	/*CNcomment:����ͼ���������*/
	HI_S32 (*OPTM_GfxSetLayerRect)(HIFB_LAYER_ID_E enLayerId, const HIFB_RECT *pstRect);

	/*set graphics process device Inrect and Outrect*/
	/*CNcomment:����ͼ������������������*/
	HI_S32 (*OPTM_GfxSetGpRect)(OPTM_GFX_GP_E enGpId, const HIFB_RECT *pstInputRect);

	HI_S32 (*OPTM_GfxSetGpInPutSize)(OPTM_GFX_GP_E enGpId, HI_U32 u32Width, HI_U32 u32Height);

	/*set layer key mask*/
	/*CNcomment:����ͼ��colorkey mask*/
	HI_S32 (*OPTM_GfxSetLayKeyMask)(HIFB_LAYER_ID_E enLayerId, const HIFB_COLORKEYEX_S *pstColorkey);
#if 0
	/* set bit-extension mode */
	HI_S32 OPTM_GfxSetLayerBitExtMode(HIFB_LAYER_ID_E enLayerId, OPTM_GFX_BITEXTEND_E enBtMode);
#endif

	/*set layer pre mult*/
	/*CNcomment:����ͼ��Ԥ��*/
	HI_S32 (*OPTM_GfxSetLayerPreMult)(HIFB_LAYER_ID_E enLayerId, HI_BOOL bEnable);

	/*set clut address*/
	/*CNcomment:����CLUT ��ַ*/
	HI_S32 (*OPTM_GfxSetClutAddr)(HIFB_LAYER_ID_E enLayerId, HI_U32 u32PhyAddr);

	HI_S32 (*OPTM_GfxGetOSDData)(HIFB_LAYER_ID_E enLayerId, HIFB_OSD_DATA_S *pstLayerData);

	/*set call back*/
	/*CNcomment:ע��ص�����*/
	HI_S32 (*OPTM_GfxSetCallback)(HIFB_LAYER_ID_E enLayerId, IntCallBack pCallBack, HIFB_CALLBACK_TPYE_E eIntType);

	/*update layer register*/
	/*CNcomment:���¼Ĵ���*/
	HI_S32 (*OPTM_GfxUpLayerReg)(HIFB_LAYER_ID_E enLayerId);

	/*enable/disable stereo*/
	/*CNcomment:����3D ʹ�ܻ��߷�ʹ��*/
	HI_S32 (*OPTM_GfxSetTriDimEnable)(HIFB_LAYER_ID_E enLayerId, HI_U32 bEnable);

	/*set stereo mode*/
	/*CNcomment:����3D ģʽSBS/TB/MVC*/
	HI_S32 (*OPTM_GfxSetTriDimMode)(HIFB_LAYER_ID_E enLayerId, HIFB_STEREO_MODE_E enMode);

	/*set stereo address*/
	/*CNcomment:����3D ģʽ�����۵�ַ*/
	HI_S32 (*OPTM_GfxSetTriDimAddr)(HIFB_LAYER_ID_E enLayerId, HI_U32 u32TriDimAddr);

	/*enable/disable compression*/
	/*CNcomment:����ѹ��ʹ�ܻ��߷�ʹ��*/
	HI_S32 (*OPTM_GfxSetLayerDeCmpEnable)(HIFB_LAYER_ID_E enLayerId, HI_BOOL bEnable);

	/*set gfx compression address*/
	/*CNcomment:����ѹ����ַ*/
	HI_S32 (*OPTM_GfxSetGfxCmpAddr)(HIFB_LAYER_ID_E enLayerId, HI_U32 u32CmpAddr);

	/*set the compression rect*/
	/*CNcomment:����ѹ����������*/
	HI_S32 (*OPTM_GfxSetGfxCmpRect)(HIFB_LAYER_ID_E enLayerId, const HIFB_RECT *pstRect);

	/*handle compression to flip the compression address and uncompression address*/
	/*CNcomment:*/
	HI_S32 (*OPTM_GfxGfxCmpHandle)(HIFB_LAYER_ID_E enLayerId);

	/*pause compression*/
	/*CNcomment:��ͣѹ��*/
	HI_S32 (*OPTM_GfxPauseCompression)(HIFB_LAYER_ID_E u32LayerId);

	/*resume compression*/
	/*CNcomment:�ָ�ѹ��*/
	HI_S32 (*OPTM_GfxResumeCompression)(HIFB_LAYER_ID_E u32LayerId);


	/*set the priority of layer in gp*/
	/*CNcomment:����ͼ����GP �е����ȼ�*/
	HI_S32 (*OPTM_GfxSetLayerPriority)(HIFB_LAYER_ID_E u32LayerId, HIFB_ZORDER_E enZOrder);

	/*get the priority of layer in gp*/
	/*CNcomment:��ȡͼ����GP �е����ȼ�*/
	HI_S32 (*OPTM_GfxGetLayerPriority)(HIFB_LAYER_ID_E u32LayerId, HI_U32 *pU32Priority);
	/*��ȡͼ���������*/
	HI_S32 (*OPTM_GFX_GetDevCap)(const HIFB_CAPABILITY_S **pstCap);
	/*��ȡͼ�����������С*/
	HI_S32 (*OPTM_GfxGetOutRect)(OPTM_GFX_GP_E enGpId, HIFB_RECT * pstOutputRect);
	/*��ȡͼ������������С*/
	HI_S32 (*OPTM_GfxGetLayerRect)(HIFB_LAYER_ID_E enLayerId, HIFB_RECT *pstRect);
	/*�����û�����GP����ֱ��ʱ�־*/
	HI_S32 (*OPTM_GFX_SetGpInUsrFlag)(OPTM_GFX_GP_E enGpId, HI_BOOL bFlag);
	/*��ȡ�û�����GP����ֱ��ʱ�־*/
	HI_S32 (*OPTM_GFX_GetGpInUsrFlag)(OPTM_GFX_GP_E enGpId);
	/*�����û�����GP����ֱ��ʱ�־*/
	HI_S32 (*OPTM_GFX_SetGpInInitFlag)(OPTM_GFX_GP_E enGpId, HI_BOOL bFlag);
	/*��ȡ�û�����GP����ֱ��ʱ�־*/
	HI_S32 (*OPTM_GFX_GetGpInInitFlag)(OPTM_GFX_GP_E enGpId);
	/*set gfx mask flag*/
	HI_S32 (*OPTM_GFX_SetGfxMask)(OPTM_GFX_GP_E enGpId, HI_BOOL bFlag);
	/*get gfx mask flag*/
	HI_S32 (*OPTM_GFX_GetGfxMask)(OPTM_GFX_GP_E enGpId);
	HI_S32 (*OPTM_GfxGetDispFMTSize)(OPTM_GFX_GP_E enGpId, HIFB_RECT *pstOutRect);
	HI_S32 (*OPTM_GFX_ClearLogoOsd)(HIFB_LAYER_ID_E enLayerId);
	HI_S32 (*OPTM_GFX_SetStereoDepth)(HIFB_LAYER_ID_E enLayerId, HI_S32 s32Depth);
}OPTM_GFX_OPS_S;

HI_VOID OPTM_GFX_GetOps(OPTM_GFX_OPS_S *ops);
#ifdef HI_BUILD_IN_BOOT
HI_S32 OPTM_GfxInit(HI_VOID);
HI_S32 OPTM_GfxOpenLayer(HIFB_LAYER_ID_E enLayerId);
HI_S32 OPTM_GfxCloseLayer(HIFB_LAYER_ID_E enLayerId);
HI_S32 OPTM_GfxOpenSlvLayer(HIFB_LAYER_ID_E enLayerId);
HI_S32 OPTM_GfxSetLayerAlpha(HIFB_LAYER_ID_E enLayerId, HIFB_ALPHA_S *pstAlpha);
HI_S32 OPTM_GfxSetLayerAddr(HIFB_LAYER_ID_E enLayerId, HI_U32 u32Addr);
HI_S32 OPTM_GfxSetLayerStride(HIFB_LAYER_ID_E enLayerId, HI_U32 u32Stride);
HI_S32 OPTM_GfxSetLayerDataFmt(HIFB_LAYER_ID_E enLayerId, HIFB_COLOR_FMT_E enDataFmt);
HI_S32 OPTM_GfxSetLayerRect(HIFB_LAYER_ID_E enLayerId, const HIFB_RECT *pstRect);
HI_S32 OPTM_GfxSetLayKeyMask(HIFB_LAYER_ID_E enLayerId, const HIFB_COLORKEYEX_S *pstColorkey);
HI_VOID OPTM_Wbc2Isr(HI_VOID* pParam0, HI_VOID *pParam1);
HI_S32 OPTM_GfxSetEnable(HIFB_LAYER_ID_E enLayerId, HI_BOOL bEnable);
HI_S32 OPTM_GfxSetGpRect(OPTM_GFX_GP_E enGpId, const HIFB_RECT * pstInputRect);
HI_S32 OPTM_GfxUpLayerReg(HIFB_LAYER_ID_E enLayerId);
HIFB_GFX_MODE_EN OPTM_Get_GfxWorkMode(HI_VOID);
HI_S32 OPTM_GpInitFromDisp(OPTM_GFX_GP_E enGPId);
HI_S32 OPTM_GfxSetDispFMTSize(OPTM_GFX_GP_E enGpId, const HI_RECT_S *pstOutRect);
#endif
#endif /* __OPTM_HIFB_H_H__*/
