#include <board.h>
#include <rtthread.h>
#include <dfs_posix.h>
#include "finsh.h"


void my_fs_test(void)
{
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
}




FINSH_FUNCTION_EXPORT(my_fs_test,--file system test in system);