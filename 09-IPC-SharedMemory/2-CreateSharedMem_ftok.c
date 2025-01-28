/* 
key_t ftok(const char *pathname, int proj_id)

Convert a pathname (an existing, accessible fil) and a project identifier to a System V IPC key;
On success : the generated key_t value is returned;
On failure : -1 is returned, with errno set;
*/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include "sys/types.h"
#include "sys/shm.h"
#include "signal.h"

int main(int argc, char *argv[])
{
    int shmid;
    int key;
    
    key = ftok("./ftok.txt", 'a');
    if (key < 0) 
    {
        perror("create key fail");
        return -1;
    }

    printf("create key sucess key = 0x%X\n",key);
    
    shmid = shmget(key, 256, IPC_CREAT | 0777);
    if (shmid < 0) {
        perror("create shared memory fail");
        return -1;
    }
    printf("create shared memory sucess, shmid = %d\n", shmid);
    system("ipcs -m");
    return 0;
}

/* Result of run:
momo@Ubuntu-Linux-22-04:~/Linux_Programming/09-IPC-SharedMemory$ ./a.out 
create key sucess key = 0x6102647F
create shared memory sucess, shmid = 65566

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 65552      parallels  777        128        0                       
...                 
0x00000000 65561      parallels  600        524288     2          dest         
0x6102647f 65566      parallels  777        256        0                       
0x00000000 32817      parallels  600        524288     2          dest         

momo@Ubuntu-Linux-22-04:~/Linux_Programming/09-IPC-SharedMemory$ 

*/