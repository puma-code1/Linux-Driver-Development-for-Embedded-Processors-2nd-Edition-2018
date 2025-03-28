# chapter3

 ## things i learned in short: 

 ---
1- every module has entry & exit functions that we define using a MACRO


2- printk(KERN_ERR "something went wrong, return code: %d\n",ret);  like printf- but prints in the kernel
Where KERN_ERR is one of the eight different log levels defined in include/linux/kern_levels.h and 
specifies the severity of the error message

 ---
 ## intro
A key concept in the design of the Linux embedded system is the separation of user applications 
from the underlying hardware. User space applications are not allowed to access peripheral 
registers, storage media or even RAM memory directly. Instead, the hardware is accessed via 
kernel drivers, and RAM memory is managed by the memory management unit (MMU), with 
applications operating on virtual addresses.
---

Device drivers can be kernel modules or statically built into the kernel image. The default kernel 
builds most drivers into the kernel statically, so they are started automatically. A kernel module is 
not necessarily a device driver; it is an extension of the kernel. The kernel modules are loaded into 
virtual memory of the kernel. Building a device driver as a module makes the development easier 
since it can be loaded, tested, and unloaded without rebooting the kernel. The kernel modules are 
usually located in /lib/modules/<kernel_version>/ on the root filesystem.




---

## LAB 3.1: "helloworld" Module

see in source files a simple module + a module with parameters. 
