#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include "sys/types.h"
#include "sys/shm.h"
#include "signal.h"

int main(int argc, char *argv[])
{
    // key created using IPC_PRIVATE is always 0;
    // This key method is only for communication between parent/child process from fork();
    int shmid = shmget(IPC_PRIVATE, 128, IPC_CREAT | 0777); // IPC_CREAT is not a MUST here;
    if (shmid < 0) {
        perror("create shared memory fail:\n");
        return -1;
    }

    printf("create shared memory sucess, shmid = %d\n", shmid);
    system("ipcs -m");              // Check IPC from user space;
    // system("ipcrm -m shmid");    // Doesn't work since shmid should a int number here;
    return 0;
}

/* 执行结果:
momo@Ubuntu-Linux-22-04:~/Linux_Programming/09-IPC-SharedMemory$ ./a.out 
create shared memory sucess, shmid = 65552

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 65549      parallels  600        524288     2          dest         
0x00000000 65552      parallels  777        128        0                       
0x00000000 32817      parallels  600        524288     2          dest         

momo@Ubuntu-Linux-22-04:~/Linux_Programming/09-IPC-SharedMemory$ ./a.out 
create shared memory sucess, shmid = 65553

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 65549      parallels  600        524288     2          dest         
0x00000000 65552      parallels  777        128        0                       
0x00000000 65553      parallels  777        128        0                       
0x00000000 32817      parallels  600        524288     2          dest         

momo@Ubuntu-Linux-22-04:~/Linux_Programming/09-IPC-SharedMemory$ ./a.out 
create shared memory sucess, shmid = 65554

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 65549      parallels  600        524288     2          dest         
0x00000000 65552      parallels  777        128        0                       
0x00000000 65553      parallels  777        128        0                       
0x00000000 65554      parallels  777        128        0                       
0x00000000 32817      parallels  600        524288     2          dest         
*/