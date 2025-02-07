#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include "sys/types.h"
#include "sys/shm.h"

int main(int argc, char *argv[])
{
    int shmid;
    int key;
    char *p;
    
    key = ftok("./ftok.txt", 'b');
    if (key < 0) {
        printf("create key fail\n");
        return -1;
    }
    printf("create key sucess key = 0x%X\n",key);
    
    shmid = shmget(key, 128, IPC_CREAT | 0777);
    if (shmid < 0) {
        printf("create shared memory fail\n");
        return -1;
    }
    printf("create shared memory sucess, shmid = %d\n", shmid);
    system("ipcs -m");
    
    // Map the shared memory to user space
    p = (char *)shmat(shmid, NULL, 0);
    if (p == NULL) {
        printf("shmat fail\n");
        return -1;
    }
    printf("shmat sucess\n");
    
    // Write share memory
    fgets(p, 128, stdin);
    // char *fgets(char *str, int n, FILE *stream);
    
    // Read share memory
    printf("share memory data:%s\n", p);
    
    // Read share memory, again.
    printf("share memory data:%s\n", p);
    // ---------------------------------------------------------------------------------------------
    // 验证了连续2次读取同一个共享内存, 发现内容都存在, 这是和之前管道的区别, 管道的内容读取完了之后, 内容就不存在了.
    // ---------------------------------------------------------------------------------------------

    return 0;
}