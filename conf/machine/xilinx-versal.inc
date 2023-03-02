#@TYPE: Machine inc.
#@NAME: versal layer

DEFAULTTUNE = "cortexa72"
require conf/machine/include/arm/armv8a/tune-cortexa72.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE = "xilinx/versal-vck190-rev1.1.dtb xilinx/versal-vck190-rev1.1-x-ebm-01-revA.dtb"
KERNEL_EXTRA_ARGS:append = " DTC_FLAGS='-@'"

SERIAL_CONSOLE = "115200 ttyPS0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "5.15%"
PREFERRED_VERSION_linux-yocto-rt ?= "5.15%"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"

# wic support
WKS_FILE ?= "versal-sdimage.wks"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " Image versal-vck190-rev1.1.dtb versal-vck190-rev1.1-x-ebm-01-revA.dtb"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE:virtclass-multilib-lib32 ?= "armv7athf-neon"
