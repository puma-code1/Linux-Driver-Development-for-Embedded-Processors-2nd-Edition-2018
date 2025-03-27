#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#define MY_MAJOR 42
#define MY_MAX_MINORS 5

struct my_device_data {
struct cdev cdev;
/* my data starts here */

};

struct my_device_data devs[MY_MAX_MINORS];


/* Create a struct file_operations named my_dev_fops. This structure defines function pointers
   for "opening" the device, "reading from" and "writing to" the device, etc.
*/
const struct file_operations my_fops = {
.owner = THIS_MODULE,
.open = my_dev_open,
//.read = my_read,
//.write = my_write,
.release = my_dev_close,
.unlocked_ioctl = my_dev_ioctl
};


static int my_dev_open(struct inode *inode, struct file *file)
{
pr_info("my_dev_open() is called.\n");
return 0;
}
static int my_dev_close(struct inode *inode, struct file *file)
{
pr_info("my_dev_close() is called.\n");
return 0;
}
static long my_dev_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
pr_info("my_dev_ioctl() is called. cmd = %d, arg = %ld\n", cmd, arg);
return 0;
}


int init_module(void)
	{
	int i, err;
	
	
	register_chrdev_region(MKDEV(MY_MAJOR, 0), MY_MAX_MINORS, "my_device_driver");

	for(i = 0; i < MY_MAX_MINORS; i++) 
		{
		/* initialize devs[i] fields and register character devices */
		cdev_init(&devs[i].cdev, &my_fops);
		cdev_add(&devs[i].cdev, MKDEV(MY_MAJOR, i), 1);
		}
	return 0;
	}
/* The following sequence deletes and unregisters the character devices*/
void cleanup_module(void)
	{
	int i;
	for(i = 0; i < MY_MAX_MINORS; i++) 
		{
		/* release devs[i] fields */
		cdev_del(&devs[i].cdev);
		}
	unregister_chrdev_region(MKDEV(MY_MAJOR, 0), MY_MAX_MINORS);
	}

module_init(hello_init);  //called in insmod 
module_exit(hello_exit);  //called in rmmod 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alberto Liberal <aliberal@arroweurope.com>");
MODULE_DESCRIPTION("This is a print out Hello World module");


/*

Create a struct file_operations named my_dev_fops. This structure defines function pointers
for "opening" the device, "reading from" and "writing to" the device, etc.

static const struct file_operations my_dev_fops = {
.owner = THIS_MODULE,
.open = my_dev_open,
.release = my_dev_close,
.unlocked_ioctl = my_dev_ioctl,
};


6. Implement each of the callback functions that are defined in the struct file_operations
structure:
static int my_dev_open(struct inode *inode, struct file *file)
{
pr_info("my_dev_open() is called.\n");
return 0;
}
static int my_dev_close(struct inode *inode, struct file *file)
{
pr_info("my_dev_close() is called.\n");
return 0;
}
static long my_dev_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
pr_info("my_dev_ioctl() is called. cmd = %d, arg = %ld\n", cmd, arg);
return 0;
}
7. Add these file operation functionalities to your character device. The kernel uses a
structure called struct cdev to represent character devices internally. Therefore, you create
a struct cdev variable named my_dev and initialize it using the cdev_init() function call
,which takes the my_dev variable and the struct file_operations structure named my_dev_fops


as parameters. Once the struct cdev structure is set up, you tell the kernel about it using
the cdev_add() function call. You will call these two functions as many times as allocated
character device identifiers (only once in this driver).

static struct cdev my_dev;
cdev_init(&my_dev, &my_dev_fops);
ret= cdev_add(&my_dev, dev, 1);

8. Add the line of code below to the hello_exit() function to delete the struct cdev structure.
cdev_del(&my_dev);

9. Once the kernel module has been dynamically loaded, the user needs to create a device
node to reference the driver. Linux provides the **mknod utility** for this purpose. The mknod
command has four parameters. The first parameter is the name of the device node that will
be created. The second parameter indicates whether the driver to which the device node
interfaces is a block driver or character driver. The final two parameters to mknod are the
major and minor numbers. Assigned major numbers are listed in the **/proc/devices** file and
can be viewed using the cat command. The created device node should be placed in the
/dev directory.




*/