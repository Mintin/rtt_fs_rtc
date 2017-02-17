
#include <board.h>
#include <rtthread.h>
#include <dfs_posix.h>
#include "finsh.h"
#include <time.h>

static struct rt_timer timer1;


static void save_time_task(void* parameter)
{
	int fd=0;
	//time_t now;;
	rt_kprintf("periodic timer is timeout1\n");
	/*
	fd=open("/savetime.txt",DFS_O_CREAT|DFS_O_RDWR|DFS_O_APPEND,0);
	if(fd<0)
	{
	  rt_kprintf("open file myfile.txt failed \r\n");
		
	}
	*/
	rt_kprintf("periodic timer is timeout2\n");
	// time(&now);
	// rt_kprintf("%s\n", ctime(&now));
   // close(fd);
}



int rt_timer_task_init(void)
{

		rt_timer_init(&timer1, "save_time_task", /* 定时器名字是 timer1 */
		save_time_task, /* 超时时回调的处理函数 */
		RT_NULL, /* 超时函数的入口参数 */
		100*60, /* 定时长度，以OS Tick为单位，即10个OS Tick */
		RT_TIMER_FLAG_PERIODIC); /* 周期性定时器 */
	
		rt_timer_start(&timer1);

		return 0;

}






FINSH_FUNCTION_EXPORT(save_time_task, --save_time_task in system--);


/*


void list_date(void)
{
    time_t now;

    time(&now);
    rt_kprintf("%s\n", ctime(&now));
}

  int fd=0;
	
	fd=open("/myfile.txt",DFS_O_CREAT|DFS_O_RDWR,0);
	if(fd<0)
	{
	  rt_kprintf("open file myfile.txt failed \r\n");
		
	}
	else
	{
		int count =write(fd,"123456",7);
		char buf[10];
		close(fd);
		fd=0;
		rt_thread_delay(50);
		rt_memset(buf,0,10);
		fd=open("/myfile.txt",DFS_O_RDONLY,0);
		
		if(read(fd,buf,7))
		{
		rt_kprintf("read=%s\r\n",buf);
	  close(fd);	 
		
		}
		else
		{
		  rt_kprintf("read file err!/r/n");
		}
	}




*/