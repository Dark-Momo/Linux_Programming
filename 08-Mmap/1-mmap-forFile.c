// Linux memory-mapping function mmap() will map the content of a file to some section of virtual memory, 
// providing a more efficient way of R/W access to this file.

// void *mmap(  void *addr, 
//              size_t length, 
//              int prot, 
//              int flags, 
//              int fd, 
//              off_t offsize);

// return value : Starting address from the mapping on success, or MAP_FAILED(-1) on failure, and 
//                errno is set to indicate the error.
// (1) addr     : Pre-set starting address of mapping. Usually set as NULL to let system decide;
// (2) length   : The length of file that will be mapped into memory;
// (3) prot     : Protection method of the mapped area:
//                - PROT_EXEC: mapped area executable;
//                - PROT_READ: mapped area readable;
//                - PROT_WRITE: mapped area writeable;
//                - PROT_NONE: mapped area can't be accessed;
// (4) flags    : Characteristics of the mapped area;
//                - MAP_SHARED: 对映射区域的写入数据会复制回文件, 且允许其他映射该文件的进程共享.
//                - MAP_PRIVATE: 对映射区域的写入操作会产生一个映射的复制(copy-on-write), 对此区域所做的修改不会写回原文件.
 
// (5) fd       : The file that will be mapped;
// (6) offset   : The offset in the file that the mapping will start from.
//                Must be integer times of page size. 0 means start from the file begining.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<error.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    int fd,len;
    char *ptr;

    if(argc < 2)
    {
        printf("please enter a filename that will be mapped\n");
        return 0;
    }

    if((fd = open(argv[1],O_RDWR))<0)
    {
        perror("open file error");  // Use perror() to read errno;
        return -1;
    }
    
    len = lseek(fd,0,SEEK_END);     // Get file length by locating to its end; 
    
    // Here, PROT_READ|PROT_WRITE should be consistent to O_RDWR when open the file;
    ptr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(ptr == MAP_FAILED)
    {
        perror("mmap error");       // Use perror() to read errno;
        close(fd);
        return -1;
    }
    close(fd);      // We can close the file when mapping is done;

    // We used %d here to print the result from strlen(), but strlen()
    // itself returns size_t {aka long unsigned int}.
    // We did a cast here;
    printf("length is %d\n",(int)strlen(ptr));

    printf("the %s content is:\n%s\n", argv[1], ptr);
    ptr[0] = 'M';   // Only modify the 1st char as example;
    printf("the %s content is:\n%s\n", argv[1], ptr);
    munmap(ptr, len);   // Write the modified content in memory to file;
    return 0;
}
