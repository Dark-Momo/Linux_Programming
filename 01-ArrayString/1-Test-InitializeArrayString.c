#include <stdio.h>
#include <string.h>

int main(void)
{
    char * Array_1 = "Hello";
    printf("Array_1 is:%s\n", Array_1); 		// Hello
    printf("sizeof Array_1 is :%zu\n",sizeof Array_1);	// 8
    printf("Array_1 length is:%zu\n", strlen(Array_1)); // 5

    printf("\n");
    char * Array_2;
    Array_2 = "World";
    printf("Array_2 is:%s\n", Array_2);			// World
    printf("sizeof Array_2 is :%zu\n",sizeof Array_2);	// 8
    printf("Array_2 length is:%zu\n", strlen(Array_2));	// 5

    printf("\n");
    char Array_3[] = "World";				
    printf("Array_3 is:%s\n", Array_3);                 // World 
    printf("sizeof Array_3 is :%zu\n",sizeof Array_3);  // 6
    printf("Array_3 length is:%zu\n", strlen(Array_3)); // 5


    /* Below has compiling error, since char Array_4[10] has already initialized Array_4 with space
     * and its address to it.
     * The later Array_4 = "ABCD" attemps to assign again this address to another addree, which is invlid.
     * /
    
    /*
    printf("\n");
    char Array_4[10];
    Array_4 = "ABCD";
    printf("Array_4 is:%s\n", Array_4);                 // World
    printf("sizeof Array_4 is :%zu\n",sizeof Array_4);  // 6
    printf("Array_4 length is:%zu\n", strlen(Array_4)); // 5
    */
    return 0;
}
