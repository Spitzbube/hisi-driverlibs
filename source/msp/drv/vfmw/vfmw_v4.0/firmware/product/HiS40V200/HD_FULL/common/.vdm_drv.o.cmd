cmd_drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o := arm-hisiv200-linux-gcc -Wp,-MD,drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/.vdm_drv.o.d  -nostdinc -isystem /opt/hisi-linux/x86-arm/arm-hisiv200-linux/bin/../lib/gcc/arm-hisiv200-linux-gnueabi/4.4.1/include -I/home/yhfeng/sdk/HiSTBLinuxV100R002C00SPC011/source/kernel/linux-3.4.y/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /home/yhfeng/sdk/HiSTBLinuxV100R002C00SPC011/source/kernel/linux-3.4.y/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-s40/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float           -c -o drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.S

source_drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o := drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.S

deps_drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o := \
  /home/yhfeng/sdk/HiSTBLinuxV100R002C00SPC011/source/kernel/linux-3.4.y/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \

drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o: $(deps_drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o)

$(deps_drivers/msp/vfmw/vfmw_v4.0/firmware/product/HiS40V200/HD_FULL/common/vdm_drv.o):
