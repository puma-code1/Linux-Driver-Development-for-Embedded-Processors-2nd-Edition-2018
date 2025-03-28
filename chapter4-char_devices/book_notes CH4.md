# chapter4
 ## intro - character drivers

Linux requires a mechanism to transfer data from the kernel to user space. This transfer of data
is handled via device nodes, which are also known as virtual files. Device nodes exist within the
root filesystem, though they are not true files. When a user reads from a device node, the kernel
copies the data stream captured by the underlying driver into the application memory space.
When a user writes to a device node, the kernel copies the data stream provided by the application
into the data buffers of the driver, which are eventually output via the underlying hardware. These
virtual files can be "opened" and "read from" or "written to" by the user application using standard
system calls.

---

From the point of view of an application, a character device is essentially a file. A process only
knows a /dev file path. The process opens the file using the open() system call and performs
standard file operations like read() and write().
In order to achieve this, a character driver must implement the operations described in the struct
file_operations structure defined in include/linux/fs.h and register them. In the struct file_operations
below only some of the most common operations for a character driver are shown:

struct file_operations {
struct module *owner;
loff_t (*llseek) (struct file *, loff_t, int);
ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
int (*mmap) (struct file *, struct vm_area_struct *);
int (*open) (struct inode *, struct file *);
int (*release) (struct inode *, struct file *);
};

The Linux filesystem layer will ensure that the driver's operations are called when an user space
application makes the corresponding system call (On the kernel side the driver implements and
registers callback operations).

---

## LAB 4.1: "helloworld character" Module

### Registration and Unregistration of Character Devices
The registration/unregistration of a character device is made by specifying the major and minor.
The dev_t type is used to keep the identifiers of a device (both major and minor) and can be
obtained using the MKDEV macro.
For the static assignment and unallocation of device identifiers, the 
- register_chrdev_region() - staticlly register char device
- unregister_chrdev_region() - staticlly unregister char device
functions are used. The first device identifier is obtained using the
MKDEV macro.
* int register_chrdev_region(dev_t first, unsigned int count, char *name);
* void unregister_chrdev_region(dev_t first, unsigned int count);
It is recommended that device identifiers be dynamically assigned using the alloc_chrdev_region()
function. This function allocates a range of char device numbers. The major number will be chosen
dynamically, and returned (along with the first minor number) in dev. This function returns zero
or a negative error code.
* int alloc_chrdev_region(dev_t* dev, unsigned baseminor, unsigned count, const char* name);


---
## Example:
register_chrdev_region(MKDEV(my_major, my_first_minor), my_minor_count,"my_device_driver");
After assigning the identifiers, the character device will have to be initialized using the cdev_init()
function and registered to the kernel using the cdev_add() function. The cdev_init() and cdev_add()
functions will be called as many times as assigned device identifiers.


## MKNODE
this command creates a device node(device file) in /dev directory
mknod /dev/mydev c major_num minor_num

---

## Add the Module to the Kernel Build

So far you have been building your driver as a loadable kernel module (LKM), which was loaded
during run-time. Now, make the driver a part of the kernel source tree and have the driver built
into the kernel binary image. This way the driver is already loaded when the new kernel is booted.
In the kernel root directory, you will find the drivers/char/ folder where all the character drivers
reside. First, copy your character driver to this folder:
~$ cp ~/linux_4.9_imx7_drivers/helloworld_imx_char_driver.c ~/my-linux-imx/drivers/
char/
Open the Kconfig file located in the ~/my-linux-imx/drivers/char/ folder using a text editor:
~$ gedit ~/my-linux-imx/drivers/char/Kconfig
Add the lines below at the end of the file, above endmenu:

config HELLOWORLD
tristate "My simple helloworld driver"
default n
help
The simplest driver.

Open the Makefile file:
~$ sudo gedit ~/my-linux-imx/drivers/char/Makefile
Add the following lines in the end of the Makefile:

obj-$(CONFIG_HELLOWORLD) += helloworld_imx_char_driver.o

Now that you have modified the Kconfig and Makefile to include the hello_imx_char_driver as a part
of the kernel instead of a loadable module, go ahead and build the new kernel image.
Open the menuconfig window. Navigate from the main menu -> Device Drivers -> Character
devices-> My simple helloworld driver. Hit <spacebar> once to see a <*> appear next to the
new configuration. Hit <Exit> until you exit the menuconfig GUI and remember to save the new
configuration.
~/my-linux-imx$ make menuconfig ARCH=arm
Opening the .config file in the kernel root directory will show that the CONFIG_HELLOWORLD
symbol has been added to it.
Compile the new image and copy it to the tftp folder:
~/my-linux-imx$ source /opt/fsl-imx-x11/4.9.11-1.0.0/environment-setup-cortexa7hf
-neon-poky-linux-gnueabi
~/my-linux-imx$ make zImage

---


## Creating Device Files with devtmpfs  -     i stoped here : page 105
