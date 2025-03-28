obj-m += my_char_driver.o 

# Specify the compiler (e.g., GCC)
CC = /usr/bin/aarch64-linux-gnu-gcc
CFLAGS = -Wall


KDIR =/lib/modules/$(shell uname -r)/build
all:
	rm -rf build
	make -C $(KDIR)  M=$(shell pwd) CC=$(CC) modules
	mkdir build
	mv *.o *.mod.c *.ko .* *.mod *.order *.symvers build/ 
ioctl_test: ioctl_test.c
	rm -rf test
	mkdir test
	$(CC) $(CFLAGS) $^ -o $@
	mv ioctl_test test
clean:
	make -C $(KDIR)  M=$(shell pwd) clean







