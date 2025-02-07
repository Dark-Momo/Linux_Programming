#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include "sys/types.h"
#include "sys/shm.h"
#include "string.h"

int main(int argc, char *argv[])
{
    int shmid;
    int key;
    char *p;
    
    // Attention here : If reuse ftok.txt as previous, we may get invalid error
    key = ftok("./ftok-4.txt", 'b');
    if (key < 0) {
        perror("create key fail");
        return -1;
    }
    printf("create key sucess key = 0x%X\n",key);
    
    shmid = shmget(key, 512, IPC_CREAT | 0777);
    if (shmid < 0) {
        perror("create shared memory fail");
        return -1;
    }
    printf("create shared memory sucess, shmid = %d\n", shmid);
    system("ipcs -m");
    
    p = (char *)shmat(shmid, NULL, 0);
    if (p == NULL) {
        perror("shmat() fail");
        return -1;
    }
    printf("shmat sucess\n");
    
    //write share memory
    fgets(p, 512, stdin);
    
    //start read share memory
    printf("share memory data:%s\n", p);
    
    //start read share memory again
    printf("share memory data:%s\n", p);

    // 在用户空间删除共享内存的地址
    shmdt(p);
    system("ipcs -m");
    
    // memcpy(p, "abcd", 4);  //执行这个语句会出现segment fault
    return 0;
}

/* Running Result:
momo@Ubuntu-Linux-22-04:~/Linux_Programming/09-IPC-SharedMemory$ ./a.out 
create key sucess key = 0x6202647F
create shared memory sucess, shmid = 98352

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 65552      parallels  777        128        0                                           
0x00000000 98345      parallels  600        524288     2          dest         
0x6202647f 98352      parallels  777        128        0    
0x00000000 98358      parallels  600        524288     2          dest                        

shmat sucess
laojian1982
share memory data:laojian1982

share memory data:laojian1982

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status                           
0x6102647f 65566      parallels  777        256        0                       
0x00000000 98345      parallels  600        524288     2          dest         
0x6202647f 98352      parallels  777        128        0                       
0x00000000 98358      parallels  600        524288     2          dest
*/