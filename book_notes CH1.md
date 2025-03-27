# chapter1
 ## intro
* links to download 
Eclipse Neon IDE for C/C++ developers has been used to write, compile and deploy the drivers.
You can download the Eclipse environment at https://www.eclipse.org/downloads/packages/eclipseide-
cc-developers/neonr.

* U-Boot wiki at http://www.denx.de/wiki/U-Boot/SourceCode
* linux kernel https://www.kernel.org
* glibc manual https://www.gnu.org/software/libc/manual/
---

## chapter 1 - building the system.

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


The minimal requirements are: 

* Configuration of the memory system.
* Loading of the kernel image and the device tree at the correct addresses.
* Optional loading of an initial RAM disk at the correct memory address.
* Setting of the kernel command-line and other parameters (e.g, device tree, machine type).

It is also usually expected that the bootloader initializes a serial console for the kernel in addition
to these basic tasks.

---
## kernel 

**Some of the subsystems the kernel is comprised of are listed below:**
* /arch/<arch>: Architecture specific code
* /arch/<arch>/<mach>: Machine/board specific code
* /Documentation: Kernel documentation. Do not miss it!
* /ipc: Inter process communication
* /mm: Memory management
* /fs: File systems
* /include: Kernel headers
*  /include/asm-<arch>: Architecture and machine dependent headers
* /include/linux: Linux kernel core headers
* /init: Linux initialization (including main.c)
* /block: Kernel block layer code
* /net: Networking functionality
* /lib: Common kernel helper functions
* /kernel: Common Kernel structures
* /arch: Architecture specific code
* /crypto: Cryptography code
* /security: Security components
* /drivers: Built-in drivers (does not include loadable modules)
* Makefile: Top Linux makefile (sets arch and version)
* /scripts: Scripts for internal or external use

## C runtime library
The C runtime library (C-standard library) defines macros, type definitions and functions for
string handling, mathematical functions, input/output processing, memory allocation and several
other functions that rely on OS services. The runtime library provides applications with access to
OS resources and functions by abstracting the OS System call interface.

---

 ## C-Runtime library 
  The runtime library provides applications with access to
  OS resources and functions by abstracting the OS System call interface.

## System shared libraries 
static libraries that come with the kernel.
.so naming convention:  soname
prefix - lib
suffix - .so ,with the version afterwords
**libfoo.so.1**
* /lib: Libraries required for startup
* /usr/lib: Most system libraries
* /usr/local/lib: Non-system libraries


---

## root filesystem

The root filesystem is where all the files contained in the file hierarchy (including device nodes) are
stored. The root filesystem is mounted as /, containing all the libraries, applications and data.

---
