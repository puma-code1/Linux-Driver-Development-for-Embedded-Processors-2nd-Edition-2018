# chapter2
 ## intro - Linux device and driver model

* device: a physical or virtual object which attaches to a bus.
* driver: a software entity which may probe for and be bound to devices, and which can
  perform certain management functions.
*  bus: a device which serves as an attachment point for other devices.

The device model is organized around three main data structures:
1. The struct bus_type structure, which represent one type of bus (e.g.; USB, PCI, I2C).
2. The struct device_driver structure, which represents one driver capable of handling certain
devices on a certain bus.
3. The struct device structure, which represents one device connected to a bus.

---

## **Bus Core Drivers**

**main components of a Linux embedded system:**
- Bootloader - we will use U-BOOT 
- Kernel
- System
- call interface - system calls are the only connection between user spave & kernel space.
- C-Runtime library - The runtime library provides applications with access to
-  OS resources and functions by abstracting the OS System call interface.
- System shared libraries 
-  Root filesystem.

---

## Bootloader - machine specific code to initilize the system




---
## kernel 



## C runtime library

---
