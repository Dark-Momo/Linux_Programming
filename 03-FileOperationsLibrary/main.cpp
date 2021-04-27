// #define _GNU_SOURCE
// #include <stdio.h>
// #include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream setup_file("./in.txt");
    std::string out;
    // std::string environment;
    std::getline(setup_file, out);
    // std::getline(setup_file, environment);

    std::cout << out << std::endl;
    std::cout << out.size() << std::endl;
    std::cout << out.compare("0x01") << std::endl;
    std::cout << out.compare("0x02") << std::endl;
    std::cout << out.compare("0x03") << std::endl;
    std::cout << out.compare("0x04") << std::endl;
    return 0;



    /*
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    char * str1 = "0x01";

    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1], "r");
    if (stream == NULL) 
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    nread = getline(&line, &len, stream);
    printf("len is %zd:\n", len);
    printf("Retrieved line of length %zd:\n", nread);
    printf("Contents are:%s\n", line);
    */
    


    // int ret = strcmp(line, str1);
    // printf("ret == %d\n", ret);

    /*
    while ((nread = getline(&line, &len, stream)) != -1) 
    {
        printf("Retrieved line of length %zd:\n", nread);
	fwrite(line, nread, 1, stdout);
    }
    */

    // free(line);
    // fclose(stream);
    // exit(EXIT_SUCCESS);
}
