LOCAL_PATH := $(call my-dir)

########## shared lib
include $(CLEAR_VARS)

include $(SDK_DIR)/Android.def

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := libhi_pmoc
ALL_DEFAULT_INSTALLED_MODULES += $(LOCAL_MODULE)

LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS := $(CFG_HI_CFLAGS)
LOCAL_CFLAGS += -DLOG_TAG=\"$(LOCAL_MODULE)\"

ifeq ($(CFG_HI_KEYLED_SUPPORT),y)
LOCAL_CFLAGS += -DHI_KEYLED_SUPPORT
endif

#LOCAL_SRC_FILES := $(sort $(call all-c-files-under, ./))
LOCAL_SRC_FILES := unf_pmoc.c pmoc_usb_wakeup.c

LOCAL_C_INCLUDES := $(COMMON_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_API_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_API_INCLUDE)

LOCAL_SHARED_LIBRARIES := libhi_common libcutils libutils libdl

include $(BUILD_SHARED_LIBRARY)

########## static lib
include $(CLEAR_VARS)

include $(SDK_DIR)/Android.def

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := libhi_pmoc
ALL_DEFAULT_INSTALLED_MODULES += $(LOCAL_MODULE)

LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS := $(CFG_HI_CFLAGS)
LOCAL_CFLAGS += -DLOG_TAG=\"$(LOCAL_MODULE)\"

ifeq ($(CFG_HI_KEYLED_SUPPORT),y)
LOCAL_CFLAGS += -DHI_KEYLED_SUPPORT
endif

#LOCAL_SRC_FILES := $(sort $(call all-c-files-under, ./))
LOCAL_SRC_FILES := unf_pmoc.c pmoc_usb_wakeup.c

LOCAL_C_INCLUDES := $(COMMON_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_API_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_API_INCLUDE)

LOCAL_SHARED_LIBRARIES := libhi_common libcutils libutils libdl

include $(BUILD_STATIC_LIBRARY)
