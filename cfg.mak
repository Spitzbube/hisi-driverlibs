#
# Automatically generated make config: don't edit
# SDK version: KERNELVERSION
# Thu Oct 24 19:17:36 2013
#

#
# Base
#
CFG_LINUX_PRODUCT=y
# CFG_ANDROID_PRODUCT is not set
CFG_PRODUCT_TYPE=linux
CFG_HI3716CV200=y
# CFG_HI3716CV200ES is not set
# CFG_HI3718CV100 is not set
# CFG_HI3718MV100 is not set
# CFG_HI3719CV100 is not set
# CFG_HI3719MV100 is not set
# CFG_HI3719MV100_A is not set
CFG_HI_CHIP_TYPE=hi3716cv200
CFG_ARM_HISIV200_LINUX=y
CFG_HI_TOOLCHAINS_NAME=arm-hisiv200-linux
# CFG_HI_LOADER_SUPPORT is not set
# CFG_HI_OPTM_SIZE_SUPPORT is not set

#
# Board
#

#
# Ethernet Config
#
CFG_HI_ETH_SUPPORT=y
CFG_HI_ETH_UP_PHYADDR=2
CFG_HI_ETH_DOWN_PHYADDR=1

#
# Flash Config
#
# CFG_HI_NAND_SUPPORT is not set
# CFG_HI_SPI_SUPPORT is not set
CFG_HI_EMMC_SUPPORT=y

#
# Tuner Config
#
CFG_HI_TUNER_NUMBER=1

#
# First Tuner Config
#
CFG_HI_TUNER_SIGNAL_CAB=y
# CFG_HI_TUNER_SIGNAL_SAT is not set
# CFG_HI_TUNER_SIGNAL_DVB_T is not set
# CFG_HI_TUNER_SIGNAL_DVB_T2 is not set
# CFG_HI_TUNER_SIGNAL_ISDB_T is not set
# CFG_HI_TUNER_SIGNAL_ATSC_T is not set
# CFG_HI_TUNER_SIGNAL_DTMB is not set
# CFG_HI_TUNER_DEV_TYPE_XG_3BL is not set
# CFG_HI_TUNER_DEV_TYPE_CD1616 is not set
# CFG_HI_TUNER_DEV_TYPE_ALPS_TDAE is not set
# CFG_HI_TUNER_DEV_TYPE_TDCC is not set
# CFG_HI_TUNER_DEV_TYPE_TDA18250 is not set
# CFG_HI_TUNER_DEV_TYPE_CD1616_DOUBLE is not set
# CFG_HI_TUNER_DEV_TYPE_MT2081 is not set
# CFG_HI_TUNER_DEV_TYPE_TMX7070X is not set
# CFG_HI_TUNER_DEV_TYPE_R820C is not set
# CFG_HI_TUNER_DEV_TYPE_MXL203 is not set
# CFG_HI_TUNER_DEV_TYPE_AV2011 is not set
# CFG_HI_TUNER_DEV_TYPE_SHARP7903 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL101 is not set
# CFG_HI_TUNER_DEV_TYPE_MXL603 is not set
# CFG_HI_TUNER_DEV_TYPE_IT9170 is not set
# CFG_HI_TUNER_DEV_TYPE_IT9133 is not set
# CFG_HI_TUNER_DEV_TYPE_TDA6651 is not set
CFG_HI_TUNER_DEV_TYPE_TDA18250B=y
# CFG_HI_TUNER_DEV_TYPE_M88TS2022 is not set
# CFG_HI_TUNER_DEV_TYPE_RDA5815 is not set
CFG_HI_TUNER_DEV_ADDR=0xc0
# CFG_HI_DEMOD_DEV_TYPE_NONE is not set
CFG_HI_DEMOD_DEV_TYPE_3130I=y
# CFG_HI_DEMOD_DEV_TYPE_3130E is not set
# CFG_HI_DEMOD_DEV_TYPE_J83B is not set
# CFG_HI_DEMOD_DEV_TYPE_AVL6211 is not set
# CFG_HI_DEMOD_DEV_TYPE_MXL101 is not set
# CFG_HI_DEMOD_DEV_TYPE_MN88472 is not set
# CFG_HI_DEMOD_DEV_TYPE_IT9170 is not set
# CFG_HI_DEMOD_DEV_TYPE_IT9133 is not set
# CFG_HI_DEMOD_DEV_TYPE_3136 is not set
# CFG_HI_DEMOD_DEV_TYPE_3136I is not set
CFG_HI_DEMOD_DEV_ADDR=0xa0
# CFG_HI_DEMOD_TS_DEFAULT is not set
CFG_HI_DEMOD_TS_PARALLEL_MODE_A=y
# CFG_HI_DEMOD_TS_PARALLEL_MODE_B is not set
# CFG_HI_DEMOD_TS_SERIAL is not set
# CFG_HI_DEMOD_TS_SERIAL_50 is not set
# CFG_HI_DEMOD_TS_SERIAL_2BIT is not set
CFG_HI_DEMOD_I2C_CHANNEL=5
CFG_HI_DEMOD_RESET_GPIO=0x1
CFG_HI_DEMUX_PORT=0

#
# Second Tuner Config
#
CFG_HI_TUNER1_SIGNAL_TYPE=cable
CFG_HI_TUNER1_DEV_TYPE=tda18250b
CFG_HI_TUNER1_DEV_ADDR=0xc0
CFG_HI_DEMOD1_DEV_TYPE=3130e
CFG_HI_DEMOD1_DEV_ADDR=0xa0
CFG_HI_DEMOD1_TS_MODE=serial
CFG_HI_DEMOD1_I2C_CHANNEL=3
CFG_HI_DEMOD1_RESET_GPIO=0x1
CFG_HI_DEMUX1_PORT=5

#
# Keyled Config
#
# CFG_HI_KEYLED_74HC164_SELECT is not set
CFG_HI_KEYLED_CT1642_SELECT=y
# CFG_HI_KEYLED_PT6961_SELECT is not set
# CFG_HI_KEYLED_PT6964_SELECT is not set
# CFG_HI_KEYLED_FD650_SELECT is not set

#
# PowerManagement Config
#
# CFG_HI_PMU_DEVICE_SELECT is not set
# CFG_HI_SND_MUTECTL_SUPPORT is not set

#
# Video DAC Config
#
CFG_HI_DAC_CVBS=3
CFG_HI_DAC_YPBPR_Y=1
CFG_HI_DAC_YPBPR_PB=2
CFG_HI_DAC_YPBPR_PR=0

#
# Boot Regfile Config
#
CFG_HI_BOOT_REG_NAME=hi3716cdmo2b_hi3716cv200_ddr3_2gbyte_8bitx4_4layers_emmc.reg

#
# Uboot
#
# CFG_HI_FORCE_ENV_TO_MEDIA is not set
CFG_HI_BOOT_ENV_STARTADDR=0x80000
CFG_HI_BOOT_ENV_SIZE=0x10000
CFG_HI_BOOT_ENV_RANGE=0x10000
# CFG_HI_BOOT_ENV_BAK_SUPPORT is not set
CFG_HI_BOOT_COMPRESSED=y
# CFG_HI_BENCH_SUPPORT is not set

#
# Build Product Code in Fastboot
#
CFG_HI_BUILD_WITH_PRODUCT=y
CFG_HI_BUILD_WITH_FRONTEND=y
# CFG_HI_BOOT_DISEQC_SUPPORT is not set

#
# Tuner Used in Fastboot
#
CFG_HI_BOOT_TUNER_TYPE_ALPS_TDAE=y
CFG_HI_BOOT_TUNER_TYPE_TDCC=y
CFG_HI_BOOT_TUNER_TYPE_TDA18250=y
CFG_HI_BOOT_TUNER_TYPE_TMX7070X=y
CFG_HI_BOOT_TUNER_TYPE_R820C=y
CFG_HI_BOOT_TUNER_TYPE_MXL203=y
# CFG_HI_BOOT_TUNER_TYPE_AV2011 is not set
# CFG_HI_BOOT_TUNER_TYPE_SHARP7903 is not set
CFG_HI_BOOT_TUNER_TYPE_MXL603=y

#
# Demod Used in Fastboot
#
CFG_HI_BOOT_DEMOD_TYPE_X5HDV2QAM=y
# CFG_HI_BOOT_DEMOD_TYPE_HI3136 is not set

#
# LNB Chip Used in Fastboot
#
CFG_HI_BOOT_LNB_CTRL_ISL9492=y
CFG_HI_BOOT_LNB_CTRL_MPS8125=y
# CFG_HI_BUILD_WITH_DEMUX is not set
# CFG_HI_BUILD_WITH_ANDROID is not set
CFG_HI_BUILD_WITH_KEYLED=y

#
# Kernel
#
CFG_LINUX-3.4.y=y
CFG_HI_KERNEL_VERSION=linux-3.4.y
CFG_HI_KERNEL_CFG=hi3716cv200_defconfig
# CFG_HI_FS_BUILDIN is not set
# CFG_HI_MSP_BUILDIN is not set

#
# Rootfs
#

#
# Board Tools Config
#
CFG_HI_TOOL_UDEV_SUPPORT=y
CFG_HI_TOOL_DOSFS_SUPPORT=y
CFG_HI_TOOL_E2FSPROGS_SUPPORT=y
CFG_HI_TOOL_FILECAP_SUPPORT=y
CFG_HI_TOOL_GDB_SUPPORT=y
CFG_HI_TOOL_IPTABLES_SUPPORT=y
CFG_HI_TOOL_MTDUTILS_SUPPORT=y
CFG_HI_TOOL_REG_SUPPORT=y
# CFG_HI_TOOL_REG_UART_SUPPORT is not set
# CFG_HI_TOOL_SANDBOX_SUPPORT is not set
CFG_HI_TOOL_TOP_SUPPORT=y
CFG_HI_TOOL_BLKID_SUPPORT=y
CFG_HI_TOOL_MSP_DEBUG_SUPPORT=y
CFG_HI_TOOL_PQ_DEBUG_SUPPORT=y
# CFG_HI_TOOL_SOC_SERVER is not set

#
# Busybox Config
#
CFG_BUSYBOX_1.16.1=y
CFG_HI_BUSYBOX_CFG_NAME=arm-hisiv200-linux.config
CFG_HI_LIBCPP_SUPPORT=y

#
# File System Config
#
CFG_HI_ROOTFS_STRIP=y
CFG_HI_ROOTFS_INSTALL_SHARED_LIBS=y
CFG_HI_ROOTFS_CRAMFS=y
CFG_HI_ROOTFS_SQUASHFS=y
CFG_HI_ROOTFS_EXT2_EXT3=y
CFG_HI_EMMC_ROOTFS_SIZE=98304-96M

#
# Common
#
CFG_HI_LOG_SUPPORT=y
CFG_HI_LOG_LEVEL=4
CFG_HI_LOG_NETWORK_SUPPORT=y
CFG_HI_LOG_UDISK_SUPPORT=y
# CFG_HI_MMZ_V2_SUPPORT is not set
# CFG_HI_MEMMGR_SUPPORT is not set
CFG_HI_PROC_SUPPORT=y

#
# Component
#
# CFG_HI_ADVCA_SUPPORT is not set
CFG_HI_ZLIB_SUPPORT=y
# CFG_HI_WIFI_SUPPORT is not set
CFG_HI_FAT_SUPPORT=y
CFG_HI_NTFS_SUPPORT=y
CFG_HI_NTFS_MODULE_SUPPORT=y
CFG_HI_NTFS_TOOLS_SUPPORT=y
CFG_HI_ALSA_SUPPORT=y
CFG_HI_VOIP_SUPPORT=y

#
# HACODEC Config
#
CFG_HI_HACODEC_MP3DECODE_SUPPORT=y
CFG_HI_HACODEC_AACDECODE_SUPPORT=y
CFG_HI_HACODEC_AACENCODE_SUPPORT=y
CFG_HI_HACODEC_AC3PASSTHROUGH_SUPPORT=y
CFG_HI_HACODEC_AMRNBCODEC_SUPPORT=y
CFG_HI_HACODEC_AMRWBCODEC_SUPPORT=y
CFG_HI_HACODEC_BLURAYLPCMDECODE_SUPPORT=y
CFG_HI_HACODEC_COOKDECODE_SUPPORT=y
CFG_HI_HACODEC_DRADECODE_SUPPORT=y
CFG_HI_HACODEC_DTSPASSTHROUGH_SUPPORT=y
CFG_HI_HACODEC_G711CODEC_SUPPORT=y
CFG_HI_HACODEC_G722CODEC_SUPPORT=y
CFG_HI_HACODEC_MP2DECODE_SUPPORT=y
CFG_HI_HACODEC_PCMDECODE_SUPPORT=y
CFG_HI_HACODEC_TRUEHDPASSTHROUGH_SUPPORT=y
CFG_HI_HACODEC_WMADECODE_SUPPORT=y
CFG_HI_PES_SUPPORT=y

#
# Caption Config
#
CFG_HI_CAPTION_SUBT_SUPPORT=y
CFG_HI_CAPTION_TTX_SUPPORT=y
CFG_HI_CAPTION_SO_SUPPORT=y
CFG_HI_CAPTION_CC_SUPPORT=y
CFG_HI_PLAYER_SUPPORT=y
# CFG_HI_PLAYER_NORMAL_SUPPORT is not set
CFG_HI_PLAYER_FULL_SUPPORT=y
# CFG_HI_CURL_SUPPORT is not set

#
# Msp
#

#
# Frontend Config
#
# CFG_HI_DISEQC_SUPPORT is not set

#
# Tuner Config
#
# CFG_HI_TUNER_TYPE_XG_3BL is not set
# CFG_HI_TUNER_TYPE_CD1616 is not set
# CFG_HI_TUNER_TYPE_ALPS_TDAE is not set
# CFG_HI_TUNER_TYPE_TDCC is not set
# CFG_HI_TUNER_TYPE_TDA18250 is not set
# CFG_HI_TUNER_TYPE_CD1616_LF_GIH_4 is not set
# CFG_HI_TUNER_TYPE_MT2081 is not set
# CFG_HI_TUNER_TYPE_TMX7070X is not set
# CFG_HI_TUNER_TYPE_R820C is not set
# CFG_HI_TUNER_TYPE_MXL203 is not set
# CFG_HI_TUNER_TYPE_AV2011 is not set
# CFG_HI_TUNER_TYPE_SHARP7903 is not set
# CFG_HI_TUNER_TYPE_MXL603 is not set
# CFG_HI_TUNER_TYPE_TDA6651 is not set
# CFG_HI_TUNER_TYPE_TDA18250B is not set

#
# Demod Config
#
# CFG_HI_DEMOD_TYPE_X5HDQAM is not set
# CFG_HI_DEMOD_TYPE_X5HDV2QAM is not set
# CFG_HI_DEMOD_TYPE_HI3130 is not set
# CFG_HI_DEMOD_TYPE_J83B is not set
# CFG_HI_DEMOD_TYPE_AVL6211 is not set
# CFG_HI_DEMOD_TYPE_MXL101 is not set
# CFG_HI_DEMOD_TYPE_MN88472 is not set
# CFG_HI_DEMOD_TYPE_IT9133 is not set
# CFG_HI_DEMOD_TYPE_IT9170 is not set
# CFG_HI_DEMOD_TYPE_HI3136 is not set

#
# LNB Chip Config
#
# CFG_HI_LNB_CTRL_ISL9492 is not set
# CFG_HI_LNB_CTRL_MPS8125 is not set

#
# DEMUX Config
#
CFG_HI_DEMUX_POOLBUF_SIZE=0x200000

#
# Audio Config
#
CFG_HI_SND_ALSA_AO_SUPPORT=y
# CFG_HI_SND_ALSA_I2S_ONLY_SUPPORT is not set
# CFG_HI_AI_SUPPORT is not set
CFG_HI_SND_CAST_SUPPORT=y
CFG_HI_ADEC_MAX_INSTANCE=8
CFG_HI_ADEC_AUDSPECTRUM_SUPPORT=y
# CFG_HI_SND_SMARTVOLUME_SUPPORT is not set
# CFG_HI_SND_VIRTUALCHN_SUPPORT is not set
CFG_HI_SND_AOE_HW_SUPPORT=y
# CFG_HI_RESAMPLER_QUALITY_LINEAR is not set
# CFG_HI_ADAC_SLIC_SUPPORT is not set
# CFG_HI_ADAC_TVL320AIC31_SUPPORT is not set
# CFG_HI_ALSA_TVL320_KERNEL_SUPPORT is not set
# CFG_HI_AENC_SUPPORT is not set
# CFG_HI_I2S0_SUPPORT is not set
# CFG_HI_I2S1_SUPPORT is not set

#
# Video Decoder Config
#
# CFG_SD_ONLY is not set
# CFG_HD_SIMPLE is not set
CFG_HD_FULL=y
CFG_HI_VFMW_DECODE_CAPABILITY=HD_FULL
CFG_2160P=y
# CFG_MVC is not set
# CFG_2_1080P is not set
# CFG_1080P is not set
# CFG_not_set is not set
CFG_HI_VDEC_PRE_FRAMEBUFFER=113
CFG_HI_VDEC_MAX_INSTANCE=16
CFG_HI_VDEC_MAX_REF_FRAME=7
CFG_HI_VDEC_MAX_DISP_FRAME=4
CFG_HI_VDEC_SCD_BUFFER_SIZE=0x200000
CFG_HI_VDEC_DEINTERLACE_SUPPORT=y
# CFG_HI_VDEC_SVDEC_SUPPORT is not set
# CFG_HI_VDEC_REG_CODEC_SUPPORT is not set
CFG_HI_VDEC_MJPEG_SUPPORT=y
CFG_HI_VDEC_USERDATA_CC_SUPPORT=y
CFG_HI_VDEC_USERDATA_CC_BUFSIZE=0xC000

#
# VO Config
#
CFG_HI_DISP_TTX_INBUFFERSIZE=0x4000
CFG_HI_DISP_CC_INBUFFERSIZE=0x4000

#
# VPSS Config
#
CFG_HI_VPSS_MAX_BUFFER_NUMB=6

#
# HDMI Config
#
CFG_HI_HDMI_SUPPORT_HDCP=y
CFG_HI_HDMI_SUPPORT_CEC=y

#
# Graphic Config
#
CFG_HIFB_STEREO3D_SUPPORT=y
# CFG_HIFB_COMPRESSION_SUPPORT is not set
# CFG_HIFB_SCROLLTEXT_SUPPORT is not set
CFG_HI_PNG_DECODER_SUPPORT=y
CFG_HI_FREETYPE_FONT_SUPPORT=y
CFG_HI_TDE_CSCTMPBUFFER_SIZE=0x0
CFG_HI_JPEG6B_STREAMBUFFER_SIZE=0x100000
CFG_HI_HD0_FB_VRAM_SIZE=7200
CFG_HI_HD1_FB_VRAM_SIZE=0
CFG_HI_HD2_FB_VRAM_SIZE=0
CFG_HI_SD0_FB_VRAM_SIZE=3240

#
# GPU Config
#
CFG_HI_GPU=y
# CFG_HI_GPU_DEBUG is not set
CFG_HI_GPU_PROFILING=y
# CFG_HI_GPU_INTERNAL_PROFILING is not set
CFG_HI_GPU_MAX_SHARE_MEM_SIZE=0x10000000
# CFG_EGL_HIGO is not set
CFG_EGL_FB=y
# CFG_EGL_DFB is not set
CFG_HI_EGL_TYPE=fb

#
# IR Config
#
CFG_HI_IR_TYPE_S2=y
# CFG_HI_IR_TYPE_STD is not set
CFG_HI_IR_NEC_SUPPORT=y
CFG_HI_IR_RC6_SUPPORT=y
CFG_HI_IR_RC5_SUPPORT=y
CFG_HI_IR_SONY_SUPPORT=y
CFG_HI_IR_TC9012_SUPPORT=y
# CFG_HI_IR_CREDIT_SUPPORT is not set

#
# Keyled Config
#
CFG_HI_KEYLED_SUPPORT=y
CFG_HI_KEYLED_74HC164_SUPPORT=y
CFG_HI_KEYLED_CT1642_SUPPORT=y
CFG_HI_KEYLED_CT1642_CLOCK_GPIO=0x2a
CFG_HI_KEYLED_CT1642_DAT_GPIO=0x2c
CFG_HI_KEYLED_CT1642_KEY_GPIO=0x2f
CFG_HI_KEYLED_PT6961_SUPPORT=y
CFG_HI_KEYLED_PT6961_CLOCK_GPIO=0x2a
CFG_HI_KEYLED_PT6961_STB_GPIO=0x2b
CFG_HI_KEYLED_PT6961_DIN_GPIO=0x2c
CFG_HI_KEYLED_PT6961_DOUT_GPIO=0x2d
CFG_HI_KEYLED_PT6964_SUPPORT=y
CFG_HI_KEYLED_PT6964_CLOCK_GPIO=0x2a
CFG_HI_KEYLED_PT6964_STB_GPIO=0x2b
CFG_HI_KEYLED_PT6964_DINOUT_GPIO=0x2c
CFG_HI_KEYLED_FD650_SUPPORT=y
CFG_HI_KEYLED_FD650_CLOCK_GPIO=0x2b
CFG_HI_KEYLED_FD650_DINOUT_GPIO=0x2d

#
# PowerManagement Config
#
# CFG_HI_DVFS_CPU_SUPPORT is not set
# CFG_HI_DVFS_CORE_SUPPORT is not set
CFG_HI_DVFS_GPU_SUPPORT=y
# CFG_HI_AVS_SUPPORT is not set

#
# SCI Config
#
# CFG_HI_SCI_SUPPORT is not set
# CFG_HI_GPIOI2C_SUPPORT is not set
# CFG_HI_VI_SUPPORT is not set
# CFG_HI_VENC_SUPPORT is not set
