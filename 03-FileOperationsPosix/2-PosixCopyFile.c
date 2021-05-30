#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
 
#define BUF_SIZE 64
 
int main(int argc, char* argv[]) {
 
    int input_fd, output_fd;
    
    int trial = 0;
    
    ssize_t ByteRead = 0, ByteRead_Total = 0;
    ssize_t ByteWrite = 0, ByteWrite_Total = 0;
    
    char buffer[BUF_SIZE];
 
    /* Are src file name arguments missing */
    if(argc != 3)
    {
        printf ("Usage: ./a.out input_file output_file\n");
        return 1;
    }
 
    /* Create input file descriptor */
    input_fd = open (argv[1], O_RDONLY);
    if (input_fd == -1) 
    {
        perror ("Open input file error");
        return 2;
    }

    /* Create output file descriptor */
    output_fd = open (argv[2], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (output_fd == -1)
    {
    	perror ("Open output file error");
	return 3;
    }

    while ( (ByteRead = read(input_fd, buffer, BUF_SIZE)) > 0 )	// Here, () is needed for read assignment. Otherwise ret = 1.
    {
        trial++; 
	
	ByteRead_Total += ByteRead;
        // printf("Read %zu bytes from file this time, and %zu in total.\n", ret, ret_total);
       
	if ( (ByteWrite = write (output_fd, buffer, ByteRead)) == ByteRead )
	{
	    ByteWrite_Total += ByteWrite;
	}
	else
	{
	    perror ("Write error");
	    close (input_fd);
            close (output_fd);

	    return 4;
	}
    }

    if (ByteRead_Total != ByteWrite_Total)
    {
        printf("Bytes from read() and write() doesn't match!\n");
    }
    else
    {
        printf("Read / Write : %zd / %zd Bytes.\n", ByteRead_Total, ByteWrite_Total);
    }

    /* Close file descriptors */
    close (input_fd);
    close (output_fd);
    return (EXIT_SUCCESS);
}
