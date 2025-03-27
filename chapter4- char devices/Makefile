obj-m += my_char_driver.o ioctl_test.o
KERNEL_DIR ?= $(HOME)/my-linux-imx
all:
make -C $(KERNEL_DIR) \
ARCH=arm CROSS_COMPILE=arm-poky-linux-gnueabi- \
SUBDIRS=$(PWD) modules
clean:
make -C $(KERNEL_DIR) \
ARCH=arm CROSS_COMPILE=arm-poky-linux-gnueabi- \
SUBDIRS=$(PWD) clean
deploy:
scp *.ko root@10.0.0.10: