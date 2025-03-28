obj-m += hello_world.o hello_world_with_parameters.o
# Specify the compiler (e.g., GCC)
CC = /usr/bin/aarch64-linux-gnu-gcc



KDIR = /lib/modules/$(shell uname -r)/build
all:
	rm -rf build
	make -C $(KDIR)  M=$(shell pwd) CC=$(CC) modules
	mkdir build
	mv *.o *.mod.c *.ko .* *.mod *.order *.symvers build/ 
clean:
	make -C $(KDIR)  M=$(shell pwd) clean









 


