#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
 
#define BUF_SIZE 32
 
int main(int argc, char* argv[]) {
 
    int input_fd;
    int trialCount = 0;
    ssize_t ret = 0, ret_total = 0;
    char buffer[BUF_SIZE];
 
    /* Are src file name arguments missing */
    if(argc != 2)
    {
        printf ("Usage: ./a.out file\n");
        return 1;
    }
 
    /* Create input file descriptor */
    input_fd = open (argv[1], O_RDONLY);			// chmod 222 to input file and see error output.
    if (input_fd == -1) 
    {
        perror ("Open file error");
        return 2;
    }

    while ((ret = read(input_fd, &buffer, BUF_SIZE)) > 0)	// Here, () is needed for read assignment. Otherwise ret = 1.
    {								// Read prototype?
        trialCount++;
	printf("\n[Read Trial %d:]\n", trialCount);
	
	ret_total += ret;
        printf("Read %zu bytes from file this time, and %zu in total.\n", ret, ret_total);
    
        printf("Contents from read in char format is:");
	printf("\n--------------------------------\n");
        for (int i = 0; i < ret; i++)
            printf("%c", buffer[i]);
	printf("\n--------------------------------\n");

        // printf("Contents from read in int format is:");
        // for (int i = 0; i < ret; i++)
	//    printf("%d ", buffer[i]);
        //printf("\n");
    }
 
    /* Close file descriptors */
    close (input_fd);
    return (EXIT_SUCCESS);
}
