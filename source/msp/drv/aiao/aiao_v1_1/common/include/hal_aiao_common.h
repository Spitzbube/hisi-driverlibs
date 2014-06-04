/******************************************************************************

Copyright (C), 2009-2019, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hal_aiao_common.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2012/09/22
Last Modified :
Description   : aiao
Function List :
History       :
* main\1    2012-09-22   z40717     init.
******************************************************************************/
#ifndef __HI_HAL_AIAO_COMMON_H__
#define __HI_HAL_AIAO_COMMON_H__

#include "hi_type.h"
#include "hi_debug.h"
#include "hi_module.h"

#include "hi_unf_common.h"

#include "circ_buf.h"


#define AIAO_ASSERT(x, param1, param2)
#define AIAO_ASSERT_NULL(ptr)

/***************************** Macro Definition ******************************/
#if 1
/* S40V2 system defination of AIAO  */
#ifdef AIAO_SW_SIMULAUTE
#define AIAO_IRQ_NUM 79
#else
#define ENA_AIAO_ISR
#define AIAO_IRQ_NUM (84+32)
#endif
#endif

#if defined (CHIP_TYPE_hi3716cv200)   /* cv200  asic&fpga  */ \
        || defined (CHIP_TYPE_hi3719cv100) || defined (CHIP_TYPE_hi3718cv100) \
        || defined (CHIP_TYPE_hi3719mv100) || defined (CHIP_TYPE_hi3719mv100_a)\
        || defined (CHIP_TYPE_hi3718mv100) 
//#define AIAO_PLL_307MHZ 1             /* cv200 fpga */
#define AIAO_PLL_492MHZ 1               /* cv200 asic, default*/  /*491.52M*/
//#define AIAO_PLL_600MHZ 1               /* cv200 asic*/
//#define AIAO_PLL_750MHZ 1               /* cv200 asic*/

#elif defined (CHIP_TYPE_hi3716cv200es)   /* S40V200 asic */
#define AIAO_PLL_600MHZ 1
#else
#error YOU MUST DEFINE  CHIP_TYPE!
#endif

#define AIAO_SYSCRG_REGOFFSET (0x0118)    
#define AIAO_CBB_REGBASE    (0xf8cd0000)

#define AIAO_COM_OFFSET      0x0000
#define AIAO_CRG_OFFSET      0x0100
#define AIAO_RX_OFFSET       0x1000
#define AIAO_TX_OFFSET       0x2000
#define AIAO_TXSDPIF_OFFSET  0x3000
#define AIAO_SDPIFER_OFFSET  0x4000


#define AIAO_CBB_REGBANDSIZE 0x10000
#define AIAO_COMREG_BANDSIZE 0x200
#define AIAO_RX_REG_BANDSIZE 0x100
#define AIAO_TX_REG_BANDSIZE 0x100
#define AIAO_TXSPDIF_REG_BANDSIZE 0x100
#define AIAO_SPDIFER_REG_BANDSIZE 0x1000  /* special */

/* hardware board i2s port */
#define AIAO_MAX_EXT_I2S_NUMBER (2)   /* rx/tx */

/* AIAO TX/RX Port */
#define AIAO_MAX_RX_PORT_NUMBER (8)
#define AIAO_MAX_TX_PORT_NUMBER (8)
#define AIAO_MAX_TXSPDIF_PORT_NUMBER (4)
#define AIAO_MAX_PORT_NUMBER (AIAO_MAX_RX_PORT_NUMBER + AIAO_MAX_TX_PORT_NUMBER + AIAO_MAX_TXSPDIF_PORT_NUMBER)

/* AIAO TX/RX Direction */
#define AIAO_VOL_6dB (0x7f)
#define AIAO_VOL_0dB (0x79)
#define AIAO_VOL_infdB (0x28)
#define AIAO_VOL_MAX_dB (AIAO_VOL_6dB)
#define AIAO_VOL_MIN_dB (AIAO_VOL_infdB)

/* AIAO TX/RX Direction */
#define AIAO_DIR_RX (0)
#define AIAO_DIR_TX (1)

/* AIAO TX TYPE */
#define AIAO_TX_I2S (0)
#define AIAO_TX_SPDIF (1)

/* AIAO TX/RX stop/start */
#define AIAO_STOP (0)
#define AIAO_START (1)

/* AIAO TX/RX Unit */
#define AIAO_FIFO_UNITBYTES (256/8)  /* aiao min process unit */

/* AIAO TX/RX Buffer */
#define AIAO_BUFFER_ADDR_ALIGN (128)
#define AIAO_BUFFER_SIZE_ALIGN (128)
#define AIAO_BUFFER_SIZE_MAX ((0x1L << 24) - AIAO_BUFFER_ADDR_ALIGN)
#define AIAO_BUFFER_SIZE_MIN (AIAO_BUFFER_SIZE_ALIGN)
#define AIAO_BUFFER_ALEMPTY_SIZE_ALIGN (AIAO_BUFFER_SIZE_ALIGN)
#define AIAO_BUFFER_ALEMPTY_SIZE_MIN (AIAO_BUFFER_SIZE_ALIGN)
#define AIAO_BUFFER_ALFULL_SIZE_ALIGN (AIAO_BUFFER_SIZE_ALIGN)
#define AIAO_BUFFER_ALFULL_SIZE_MIN (AIAO_BUFFER_SIZE_ALIGN)

#define AIAO_BUFFER_PERIODNUM_MIN (2)
#define AIAO_BUFFER_PERIODNUM_MAX (128)
#define AIAO_BUFFER_PERIODSIZE_MIN (AIAO_BUFFER_SIZE_ALIGN)
#define AIAO_BUFFER_PERIODSIZE_MAX (AIAO_BUFFER_SIZE_MAX / AIAO_BUFFER_PERIODNUM_MAX)

//#define AIAO_DF_PeriodBufSize 4096
#define AIAO_DF_PeriodBufSize 2048

#define AIAO_DF_FadeInRate AIAO_FADE_RATE_16
#define AIAO_DF_FadeOutRate AIAO_FADE_RATE_8


/* AIAO MAX TX/RX Port Definition */
typedef enum
{
    AIAO_PORT_RX0 = 0x00,
    AIAO_PORT_RX1 = 0x01,
    AIAO_PORT_RX2 = 0x02,
    AIAO_PORT_RX3 = 0x03,
    AIAO_PORT_RX4 = 0x04,
    AIAO_PORT_RX5 = 0x05,
    AIAO_PORT_RX6 = 0x06,
    AIAO_PORT_RX7 = 0x07,

    AIAO_PORT_TX0 = 0x10,
    AIAO_PORT_TX1 = 0x11,
    AIAO_PORT_TX2 = 0x12,
    AIAO_PORT_TX3 = 0x13,
    AIAO_PORT_TX4 = 0x14,
    AIAO_PORT_TX5 = 0x15,
    AIAO_PORT_TX6 = 0x16,
    AIAO_PORT_TX7 = 0x17,

    AIAO_PORT_SPDIF_TX0 = 0x20,
    AIAO_PORT_SPDIF_TX1 = 0x21,
    AIAO_PORT_SPDIF_TX2 = 0x22,
    AIAO_PORT_SPDIF_TX3 = 0x23,

    AIAO_PORT_BUTT = 0xff,
} AIAO_PORT_ID_E;

typedef enum
{
    AIAO_MODE_RXI2S = 0,
    AIAO_MODE_TXI2S,
    AIAO_MODE_TXSPDIF,
} AIAO_PORT_MODE_E;

typedef enum
{
    AIAO_SPDIFPORT_SOURCE_TX0 = 0,
    AIAO_SPDIFPORT_SOURCE_TX1 = 1,
    AIAO_SPDIFPORT_SOURCE_TX2 = 2,
    AIAO_SPDIFPORT_SOURCE_TX3 = 3,
    AIAO_SPDIFPORT_SOURCE_RX0 = 4,
    AIAO_SPDIFPORT_SOURCE_RX1 = 5,
} AIAO_SPDIFPORT_SOURCE_E;

typedef enum
{
    AIAO_RX_CRG0 = 0,
    AIAO_RX_CRG1,
    AIAO_RX_CRG2,
    AIAO_RX_CRG3,
    AIAO_RX_CRG4,
    AIAO_RX_CRG5,
    AIAO_RX_CRG6,
    AIAO_RX_CRG7,
    AIAO_TX_CRG0,
    AIAO_TX_CRG1,
    AIAO_TX_CRG2,
    AIAO_TX_CRG3,
    AIAO_TX_CRG4,
    AIAO_TX_CRG5,
    AIAO_TX_CRG6,
    AIAO_TX_CRG7,
    AIAO_CRG_BUTT = 0xffff,
} AIAO_CRG_SOURCE_E;

typedef enum
{
    AIAO_CRG_MODE_MASTER = 0,
    AIAO_CRG_MODE_SLAVE,
    AIAO_CRG_MODE_DUPLICATE,
} AIAO_CRG_MODE_E;

typedef enum
{
    AIAO_TX0 = 0,
    AIAO_TX1,
    AIAO_TX2,
    AIAO_TX3,
    AIAO_TX4,
    AIAO_TX5,
    AIAO_TX6,
    AIAO_TX7,
    AIAO_RX0,
    AIAO_RX1,
    AIAO_RX2,
    AIAO_RX3,
    AIAO_RX4,
    AIAO_RX5,
    AIAO_RX6,
    AIAO_RX7,
} AIAO_I2S_SOURCE_E;

typedef enum
{
    AIAO_I2S_SD0 = 0,
    AIAO_I2S_SD1,
    AIAO_I2S_SD2,
    AIAO_I2S_SD3,
} AIAO_I2S_SD_E;

typedef enum
{
    AIAO_BIT_DEPTH_8  = 8,
    AIAO_BIT_DEPTH_16 = 16,
    AIAO_BIT_DEPTH_24 = 24,
} AIAO_BITDEPTH_E;

typedef enum
{
    AIAO_I2S_CHNUM_1  = 1,
    AIAO_I2S_CHNUM_2  = 2,
    AIAO_I2S_CHNUM_4  = 4,
    AIAO_I2S_CHNUM_8  = 8,
    AIAO_I2S_CHNUM_16 = 16,
} AIAO_I2S_CHNUM_E;

typedef enum
{
    AIAO_MODE_I2S = 0,
    AIAO_MODE_PCM = 1,

    AIAO_MODE_BUTT
} AIAO_I2S_MODE_E;

typedef enum
{
    AIAO_MODE_EDGE_RISE = 1,
    AIAO_MODE_EDGE_FALL = 0,
} AIAO_I2S_EDGE_E;

typedef enum
{
    AIAO_TRACK_MODE_STEREO = 0,
    AIAO_TRACK_MODE_DOUBLE_LEFT,
    AIAO_TRACK_MODE_DOUBLE_RIGHT,
    AIAO_TRACK_MODE_EXCHANGE,
    AIAO_TRACK_MODE_DOUBLE_MONO,
    AIAO_TRACK_MODE_ONLY_RIGHT,
    AIAO_TRACK_MODE_ONLY_LEFT,
    AIAO_TRACK_MODE_MUTED,

    AIAO_TRACK_MODE_BUTT
} AIAO_TRACK_MODE_E;
typedef enum
{
    AIAO_FADE_RATE_1   = 0,
    AIAO_FADE_RATE_2   = 1,
    AIAO_FADE_RATE_4   = 2,
    AIAO_FADE_RATE_8   = 3,
    AIAO_FADE_RATE_16  = 4,
    AIAO_FADE_RATE_32  = 5,
    AIAO_FADE_RATE_64  = 6,
    AIAO_FADE_RATE_128 = 7,
} AIAO_FADE_RATE_E;

typedef enum
{
    AIAO_RX_INT0 = 0,
    AIAO_RX_INT1,
    AIAO_RX_INT2,
    AIAO_RX_INT3,
    AIAO_RX_INT4,
    AIAO_RX_INT5,
    AIAO_RX_INT6,
    AIAO_RX_INT7,

    AIAO_TX_INT0 = 16,
    AIAO_TX_INT1,
    AIAO_TX_INT2,
    AIAO_TX_INT3,
    AIAO_TX_INT4,
    AIAO_TX_INT5,
    AIAO_TX_INT6,
    AIAO_TX_INT7,

    AIAO_SPDIFTX_INT0 = 24,
    AIAO_SPDIFTX_INT1,
    AIAO_SPDIFTX_INT2,
    AIAO_SPDIFTX_INT3,

    AIAO_INT_BUTT = 28
} AIAO_TOP_INT_E;

typedef enum
{
    AIAO_TXINT0_BUF_TRANSFINISH = 0,
    AIAO_TXINT1_BUF_EMPTY  = 1,
    AIAO_TXINT2_BUF_AEMPTY = 2,
    AIAO_TXINT3_BUF_FIFOEMPTY = 3,
    AIAO_TXINT4_IF_FIFOEMPTY = 4,
    AIAO_TXINT5_STOP_DONE = 5,
    AIAO_TXINT6_MUTEFADE_DONE  = 6,
    AIAO_TXINT7_DATA_BROKEN  = 7,
    AIAO_TXINT_ALL = 0xff,
} AIAO_TX_INTMODE_E;

#define AIAO_TXINT0_BUF_TRANSFINISH_MASK (1 << ((HI_U32)AIAO_TXINT0_BUF_TRANSFINISH))
#define AIAO_TXINT1_BUF_EMPTY_MASK (1 << ((HI_U32)AIAO_TXINT1_BUF_EMPTY))
#define AIAO_TXINT2_BUF_AEMPTY_MASK (1 << ((HI_U32)AIAO_TXINT2_BUF_AEMPTY))
#define AIAO_TXINT3_BUF_FIFOEMPTY_MASK (1 << ((HI_U32)AIAO_TXINT3_BUF_FIFOEMPTY))
#define AIAO_TXINT4_IF_FIFOEMPTY_MASK (1 << ((HI_U32)AIAO_TXINT4_IF_FIFOEMPTY))
#define AIAO_TXINT5_STOP_DONE_MASK (1 << ((HI_U32)AIAO_TXINT5_STOP_DONE))
#define AIAO_TXINT6_MUTEFADE_DONE_MASK (1 << ((HI_U32)AIAO_TXINT6_MUTEFADE_DONE))
#define AIAO_TXINT7_DATA_BROKEN_MASK (1 << ((HI_U32)AIAO_TXINT7_DATA_BROKEN))

typedef enum
{
    AIAO_RXINT0_BUF_TRANSFINISH = 0,
    AIAO_RXINT1_BUF_FULL  = 1,
    AIAO_RXINT2_BUF_AFULL = 2,
    AIAO_RXINT3_BUF_FIFOFULL = 3,
    AIAO_RXINT4_IF_FIFOFULL = 4,
    AIAO_RXINT5_STOP_DONE = 5,
    AIAO_RXINT_ALL = 0x3f,
} AIAO_RX_INTMODE_E;

#define AIAO_RXINT0_BUF_TRANSFINISH_MASK (1 << ((HI_U32)AIAO_RXINT0_BUF_TRANSFINISH))
#define AIAO_RXINT1_BUF_FULL_MASK (1 << ((HI_U32)AIAO_RXINT1_BUF_FULL))
#define AIAO_RXINT2_BUF_AFULL_MASK (1 << ((HI_U32)AIAO_RXINT2_BUF_AFULL))
#define AIAO_RXINT3_BUF_FIFOFULL_MASK (1 << ((HI_U32)AIAO_RXINT3_BUF_FIFOFULL))
#define AIAO_RXINT4_IF_FIFOFULL_MASK (1 << ((HI_U32)AIAO_RXINT4_IF_FIFOFULL))
#define AIAO_RXINT5_STOP_DONE_MASK (1 << ((HI_U32)AIAO_RXINT5_STOP_DONE))

typedef enum
{
    AIAO_STOP_IMMEDIATE = 0,
    AIAO_STOP_FADEOUT = 1,
} AIAO_PORT_STOPMODE_E;

typedef enum
{
    AIAO_SAMPLE_RATE_UNKNOWN = 0,
    AIAO_SAMPLE_RATE_8K   = 8000,
    AIAO_SAMPLE_RATE_11K  = 11025,
    AIAO_SAMPLE_RATE_12K  = 12000,
    AIAO_SAMPLE_RATE_16K  = 16000,
    AIAO_SAMPLE_RATE_22K  = 22050,
    AIAO_SAMPLE_RATE_24K  = 24000,
    AIAO_SAMPLE_RATE_32K  = 32000,
    AIAO_SAMPLE_RATE_44K  = 44100,
    AIAO_SAMPLE_RATE_48K  = 48000,
    AIAO_SAMPLE_RATE_88K  = 88200,
    AIAO_SAMPLE_RATE_96K  = 96000,
    AIAO_SAMPLE_RATE_176K = 176400,
    AIAO_SAMPLE_RATE_192K = 192000,

    AIAO_SAMPLE_RATE_BUTT
} AIAO_SAMPLE_RATE_E;

/* SPDIF output mode */
typedef enum
{
    AIAO_SPDIF_MODE_PCM = 0,      /* linear pcm    */
    AIAO_SPDIF_MODE_COMPRESSED,   /* non linear pcm(bit stream) */
    AIAO_SPDIF_MODE_BUTT
} AIAO_SPDIF_MODE_E;

typedef HI_VOID AIAO_IsrFunc (AIAO_PORT_ID_E enPortID, HI_U32 u32IntRawStatus,void *);//HI_ALSA_AI_SUPPORT

typedef struct
{
    HI_U32 u32PeriodBufSize;
    HI_U32 u32PeriodNumber;         /* 2/4/8 */
} AIAO_BufAttr_S;

typedef struct
{
    HI_U32 u32BUFF_SADDR;
    HI_U32 u32BUFF_SIZE;
    HI_U32 u32BUFF_WPTR;
    HI_U32 u32BUFF_RPTR;
    HI_U32 u32PeriodBufSize;
    HI_U32 u32ThresholdSize;
} AIAO_BufInfo_S;

typedef struct
{
    /* common */
    AIAO_CRG_MODE_E  enCrgMode;
    AIAO_I2S_CHNUM_E enChNum;
    AIAO_BITDEPTH_E  enBitDepth;

    /* i2s AIAO_CRG_MODE_MASTER & AIAO_CRG_MODE_SLAVE only */
    AIAO_I2S_EDGE_E enRiseEdge;

    /* i2s/spdif AIAO_CRG_MODE_MASTER only */
    AIAO_SAMPLE_RATE_E enRate;
    HI_U32             u32FCLK_DIV;
    HI_U32             u32BCLK_DIV;

    /* i2s AIAO_CRG_MODE_DUPLICATE only */
    AIAO_CRG_SOURCE_E eCrgSource;

    /* i2s rx/tx only */
    HI_U32            u32PcmDelayCycles;
    AIAO_I2S_MODE_E   enI2SMode;
    AIAO_I2S_SOURCE_E enSource;
    AIAO_I2S_SD_E     enSD0;
    AIAO_I2S_SD_E     enSD1;
    AIAO_I2S_SD_E     enSD2;
    AIAO_I2S_SD_E     enSD3;

    /* i2s rx only */
    HI_S32 bMultislot;
} AIAO_IfAttr_S;

/* void internal mmz */
typedef struct
{
    HI_U32  u32BufPhyAddr;  
    HI_U32  u32BufVirAddr;  
    HI_U32  u32BufSize;
} AIAO_MEM_ATTR_S;

typedef struct
{
    AIAO_IfAttr_S     stIfAttr;
    AIAO_BufAttr_S    stBufConfig;
    AIAO_TRACK_MODE_E enTrackMode;
    AIAO_FADE_RATE_E  enFadeInRate;        /* tx only */
    AIAO_FADE_RATE_E  enFadeOutRate;       /* tx only */
    HI_S32            bMute;
    HI_S32            bMuteFade;           /* tx only */
    HI_U32            u32VolumedB;
    HI_S32            bByBass;
    HI_BOOL bExtDmaMem; 
    AIAO_MEM_ATTR_S   stExtMem;
    
    AIAO_IsrFunc      *pIsrFunc;
	void *substream;  //only for alsa isr HI_ALSA_AI_SUPPORT
} AIAO_PORT_USER_CFG_S;

typedef struct
{
    AIAO_IfAttr_S     stIfAttr;
    AIAO_BufAttr_S    stBufConfig;
} AIAO_PORT_ATTR_S;

typedef struct
{
    HI_U32  u32BufPhyAddr;
    HI_U32  u32BufPhyWptr;
    HI_U32  u32BufPhyRptr;
    HI_U32  u32BufVirAddr;
    HI_U32  u32BufVirWptr;
    HI_U32  u32BufVirRptr;
    HI_U32  u32BufSize;
} AIAO_RBUF_ATTR_S;

typedef struct
{
    /* Tx/RX */
    HI_U32 uDMACnt;
    HI_U32 uBusTimeOutCnt;        /* update at isr */

    /* Rx only */
    HI_U32 uTotalByteRead;
    HI_U32 uTryReadCnt;
    HI_U32 uBufFullCnt;            /* update at rx isr */
    HI_U32 uBufFullWarningCnt;     /* update at rx isr */
    HI_U32 uBusFiFoFullCnt;        /* update at rx isr */
    HI_U32 uInfFiFoFullCnt;        /* update at rx isr */

    /* tx only */
    HI_U32 uTotalByteWrite;
    HI_U32 uTryWriteCnt;
    HI_U32 uBufEmptyCnt;          /* update at tx isr */
    HI_U32 uBufEmptyWarningCnt;   /* update at tx isr */
    HI_U32 uBusFiFoEmptyCnt;      /* update at tx isr */
    HI_U32 uInfFiFoEmptyCnt;      /* update at tx isr */
    HI_U32 uInfEmptyCntReal;      /* update at tx isr */
} AIAO_PROC_STAUTS_S;

typedef enum
{
    AIAO_PORT_STATUS_STOP = 0,
    AIAO_PORT_STATUS_START,
    AIAO_PORT_STATUS_STOP_PENDDING,
} AIAO_PORT_STATUS_E;

typedef struct
{
    AIAO_PROC_STAUTS_S   stProcStatus;
    AIAO_PORT_USER_CFG_S stUserConfig;
    AIAO_BufInfo_S       stBuf;
    CIRC_BUF_S           stCircBuf;
    AIAO_PORT_STATUS_E   enStatus;
} AIAO_PORT_STAUTS_S;

typedef HI_VOID AIAO_ISR (HI_VOID * handle, HI_U32 status);

//#define PORT2CHID(x) (((HI_U32)(x)) & 0x0f)

static inline HI_U32 PORT2CHID(AIAO_PORT_ID_E enPortID)
{
    if (enPortID <= AIAO_PORT_RX7)
    {
        return (enPortID&0x0f);
    }
    else if (enPortID<=AIAO_PORT_TX7 && enPortID>=AIAO_PORT_TX0)
    {
        return (enPortID&0x0f);
    }
    else if (enPortID<=AIAO_PORT_SPDIF_TX3&& enPortID>=AIAO_PORT_SPDIF_TX0)
    {
        return (enPortID&0x0f);
    }
    else
    {
        return 0;  /* avoid TQE */
    }
}

static inline HI_U32 AIAOFrameSize(AIAO_I2S_CHNUM_E enCh, AIAO_BITDEPTH_E enBitDepth)
{
    HI_U32 uFrameSize = 0;

    switch (enBitDepth)
    {
    case AIAO_BIT_DEPTH_8:
        uFrameSize = ((HI_U32)enCh) * sizeof(HI_U8);
        break;
    case AIAO_BIT_DEPTH_16:
        uFrameSize = ((HI_U32)enCh) * sizeof(HI_U16);
        break;
    case AIAO_BIT_DEPTH_24:
        uFrameSize =  ((HI_U32)enCh) * sizeof(HI_U32);
        break;
    }

    return uFrameSize;
}

static inline HI_U32  PORT2ID(AIAO_PORT_ID_E enPortID)
{
    HI_U32 ChnId = PORT2CHID(enPortID);

    if (!((HI_U32)enPortID & 0x30))
    {
        ChnId += (HI_U32)AIAO_RX_INT0;
    }
    else if (((HI_U32)enPortID & 0x10))
    {
        ChnId += (HI_U32)AIAO_TX_INT0;
    }
    else if (((HI_U32)enPortID & 0x20))
    {
        ChnId += (HI_U32)AIAO_SPDIFTX_INT0;
    }
    else
    {
        ChnId = 0;   /* avoid TQE */
    }

    return ChnId;  /* convert to golbal ID */
}

static inline AIAO_PORT_ID_E  ID2PORT(HI_U32 ID)
{
    AIAO_PORT_ID_E     enPortID;

    if (ID<=AIAO_RX_INT7)
    {
        ID  -= (HI_U32)AIAO_RX_INT0;
        enPortID = (AIAO_PORT_ID_E)(ID);
    }
    else if (ID<=AIAO_TX_INT7 && ID>=AIAO_TX_INT0)
    {
        ID -= (HI_U32)AIAO_TX_INT0;
        ID += 0x10;
        enPortID = (AIAO_PORT_ID_E)(ID);
    }
    else if (ID<=AIAO_SPDIFTX_INT3 && ID>=AIAO_SPDIFTX_INT0)
    {
        ID -= (HI_U32)AIAO_SPDIFTX_INT0;
        ID += 0x20;
        enPortID = (AIAO_PORT_ID_E)(ID);
    }
    else
    {
        enPortID = AIAO_PORT_BUTT;
    }

    return enPortID;  
}

static inline AIAO_PORT_MODE_E PORT2MODE(AIAO_PORT_ID_E enPortID)
{
    if (!((HI_U32)enPortID & 0x30))
    {
        return AIAO_MODE_RXI2S;
    }
    else if (((HI_U32)enPortID & 0x10))
    {
        return AIAO_MODE_TXI2S;
    }
    else
    {
        return AIAO_MODE_TXSPDIF;
    }
}


static inline HI_S32  PORT2DIR(AIAO_PORT_ID_E enPortID)
{
    if (0 == ((HI_U32)enPortID & 0x30))
    {
        return AIAO_DIR_RX;
    }
    else
    {
        return AIAO_DIR_TX;
    }
}

static inline HI_S32  Port2IntStatus(AIAO_PORT_ID_E enPortID, HI_U32 IntStatus)
{
    HI_U32 ID = PORT2ID(enPortID);

    return (IntStatus >> ID) & 0x01;
}

typedef struct hiAIAO_Port_GetCapability_S
{
    HI_U32 u32Capability;
} AIAO_Port_GetCapability_S;

typedef struct hiAIAO_Port_Open_S
{
    AIAO_PORT_ID_E              enPortID;
    AIAO_PORT_USER_CFG_S *pstConfig;
} AIAO_Port_Open_S;

typedef struct hiAIAO_Port_Close_S
{
    AIAO_PORT_ID_E enPortID;
} AIAO_Port_Close_S;

typedef struct hiAIAO_Port_Start_S
{
    AIAO_PORT_ID_E enPortID;
} AIAO_Port_Start_S;

typedef struct hiAIAO_Port_SelectSpdifSource_S
{
    AIAO_PORT_ID_E       enPortID;
    AIAO_SPDIFPORT_SOURCE_E eSrcChnId;
} AIAO_Port_SelectSpdifSource_S;

typedef struct hiAIAO_Port_SetSpdifOutPort_S
{
    AIAO_PORT_ID_E       enPortID;
    HI_S32 bEn;
} AIAO_Port_SetSpdifOutPort_S;

typedef struct hiAIAO_Port_Stop_S
{
    AIAO_PORT_ID_E       enPortID;
    AIAO_PORT_STOPMODE_E enStopMode;
} AIAO_Port_Stop_S;


typedef struct hiAIAO_Port_Mute_S
{
    AIAO_PORT_ID_E enPortID;
    HI_BOOL        bMute;
} AIAO_Port_Mute_S;

typedef struct hiAIAO_Port_Volume_S
{
    AIAO_PORT_ID_E enPortID;
    HI_U32         u32VolumedB;
} AIAO_Port_Volume_S;

typedef struct hiAIAO_Port_TrackMode_S
{
    AIAO_PORT_ID_E    enPortID;
    AIAO_TRACK_MODE_E enTrackMode;
} AIAO_Port_TrackMode_S;

typedef struct hiAIAO_Port_GetUserConfig_S
{
    AIAO_PORT_ID_E       enPortID;
    AIAO_PORT_USER_CFG_S stUserConfig;
} AIAO_Port_GetUserConfig_S;

typedef struct hiAIAO_Port_GetSTATUS_S
{
    AIAO_PORT_ID_E     enPortID;
    AIAO_PORT_STAUTS_S stStatus;
} AIAO_Port_GetSTATUS_S;

typedef struct hiAIAO_Port_ReadData_S
{
    AIAO_PORT_ID_E enPortID;
    HI_U8 *        pu32Dest;
    HI_U32         u32DestSize;

    HI_U32 u32ReadBytes;
} AIAO_Port_ReadData_S;

typedef struct hiAIAO_Port_WriteData_S
{
    AIAO_PORT_ID_E enPortID;
    HI_U8 *        pu32Src;
    HI_U32         u32SrcLen;
    HI_U32         u32WriteBytes;
} AIAO_Port_WriteData_S;

typedef struct hiAIAO_Port_BufStatus_S
{
    AIAO_PORT_ID_E enPortID;
    HI_U32         u32DataSize;
    HI_U32         u32FreeSize;
} AIAO_Port_BufStatus_S;

typedef struct hiAIAO_Dbg_Reg_S
{
    HI_S32 isRead;
    HI_U32 u32RegAddrBase;
    HI_U32 u32RegAddrOffSet;
    HI_U32 u32RegValue;
} AIAO_Dbg_Reg_S;

typedef struct hiAIAO_I2SDataSel_S
{
    AIAO_I2S_SD_E     enSD0;
    AIAO_I2S_SD_E     enSD1;
    AIAO_I2S_SD_E     enSD2;
    AIAO_I2S_SD_E     enSD3;
} AIAO_I2SDataSel_S;

typedef struct hiAIAO_Port_I2SDataSel_S
{
    AIAO_PORT_ID_E     enPortID;
    AIAO_I2SDataSel_S  stSdSel;
} AIAO_Port_I2SDataSel_S;


//for ALSA      //NO USED
typedef struct 
{
    HI_U32 u32Channels;
    HI_U32 u32SamplerRate;
    HI_U32 u32BitDepth;
    HI_VOID *pAddr;
} AIAO_DAC_STATUS;

typedef struct 
{
    HI_U32 u32InitFlag; /* bit0: rx, bit1: tx */   //HI_BOOL u32InitFlag;  
    AIAO_PORT_ID_E     enTxPortID;
    AIAO_I2S_SOURCE_E  enTxSource;
    AIAO_CRG_MODE_E    enTxCrgMode;
    AIAO_CRG_SOURCE_E  enTxCrgSource;

    AIAO_PORT_ID_E     enRxPortID;
    AIAO_I2S_SOURCE_E  enRxSource;
    AIAO_CRG_MODE_E    enRxCrgMode;
    AIAO_CRG_SOURCE_E  enRxCrgSource;
    
    AIAO_IfAttr_S      stIfCommonAttr;
} AIAO_I2S_BOARD_CONFIG;

#endif  // __HI_HAL_AIAO_COMMON_H__
