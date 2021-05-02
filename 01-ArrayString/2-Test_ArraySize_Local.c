#include <stdio.h>
#include <string.h>

int main (void)
{
    int  i;

    char Array_1[] = {'A', 'B', 'C', 'D'};

    printf("sizeof Array_1[] is : %zu\n", sizeof Array_1); 	// sizeof(Array_1) is the same. Result : 
    printf("strlen(Array_1[]) is : %zu\n", strlen(Array_1));  	// Result :

    printf("Array_1[] is:");   // Result :
    for (i = 0; Array_1[i] != '\0'; i++)
    {
        printf("%c", Array_1[i]);
    }
    printf("\n");
    printf("The last valid index for Array_1[] is %d.\n", i - 1);  
    // ------------------------------------------------------------------------------
    printf("\n");

    char Array_2[4] = {'E', 'F', 'G', 'H'};

    printf("sizeof Array_2[4] is : %zu\n", sizeof Array_2); 	// Result : 
    printf("strlen(Array_2[4]) is : %zu\n", strlen(Array_2));	// Result : 

    printf("Array_2[4] is:"); 	// Result : Array_2[] is:
    for (i = 0; Array_2[i] != '\0'; i++)
    {
	printf("%c", Array_2[i]);
    }
    printf("\n");
    printf("The last valid index for Array_2[4] is %d.\n", i - 1);	// Result : 
    // ------------------------------------------------------------------------------
    printf("\n");

    char Array_3[8] = {'I', 'J', 'K', 'L'};

    printf("sizeof Array_3[8] is : %zu\n", sizeof Array_3);     // Result :
    printf("strlen(Array_3[8]) is : %zu\n", strlen(Array_3));   // Result :

    printf("Array_3[8] is:");   // Result : Array_2[] is:
    for (i = 0; Array_3[i] != '\0'; i++)
    {
        printf("%c", Array_3[i]);
    }
    printf("\n");
    printf("The last valid index for Array_3[8] is %d.\n", i - 1);      // Result :

    return 0;
}
