/* For Kernel Functions */
#include<linux/kernel.h>
/* For Module Macro */
#include<linux/module.h>
/* For passing arguments to module from insmod */
#include<linux/moduleparam.h>
/* Declare an array to take parameter */
int arrayParam[5];
/* varriable to store how many argument passed */
static int count=0;
/* declare a array as a module  parameter */
module_param_array(arrayParam,int,&count,S_IWUSR|S_IRUSR);

/* Module init Function */
static int arrayParameter_init(void)
{
	int i,ele;
	printk(KERN_INFO"%s init",__func__);
	printk(KERN_INFO"Count :- %d ",count);
	ele = sizeof(arrayParam)/sizeof(arrayParam[0]);
	for(i=0;i<ele;i++)
	{
		printk(KERN_INFO"%d ",arrayParam[i]);		
	}
	return 0;
}
/* Module Exit Function */
static void arrayParameter_exit(void)
{
	
	printk(KERN_INFO"%s exit",__func__);
}

/* Register Init function */
module_init(arrayParameter_init);
/* Register Exit function */
module_exit(arrayParameter_exit);

/* module license declaration */
MODULE_LICENSE("GPL");

