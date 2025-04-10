#include <linux/module.h>
static int __init hello_init(void)
	{
	pr_info("Hello world init\n");
	return 0;
	}

static void __exit hello_exit(void)
	{
	pr_info("Hello world exit\n");
	}

module_init(hello_init);  //called in insmod 
module_exit(hello_exit);  //called in rmmod 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alberto Liberal <aliberal@arroweurope.com>");
MODULE_DESCRIPTION("This is a print out Hello World module");