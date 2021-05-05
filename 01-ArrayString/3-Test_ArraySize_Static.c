#include <stdio.h>
#include <string.h>	// strlen()

char Array_1[] = {'A', 'B', 'C', 'D'};
char Array_2[4 * sizeof(char)] = {'E', 'F', 'G', 'H'};

int main (void)
{
    int  i;

    // --------------------------------------------------------------------------------
    printf("sizeof Array_1[] is : %zu\n", sizeof Array_1);
    printf("strlen(Array_1[]) is : %zu\n", strlen(Array_1));

    printf("Array_1[] is:");
    for (i = 0; Array_1[i] != '\0'; i++)
    {
        printf("%c", Array_1[i]);
    }
    printf("\n");
    printf("The last valid index for Array_1[] is %d.\n", i - 1);
    // ------------------------------------------------------------------------------
    printf("\n");

    printf("sizeof Array_2[4] is : %zu\n", sizeof Array_2);     // Result : 
    printf("strlen(Array_2[4]) is : %zu\n", strlen(Array_2));   // Result : 

    printf("Array_2[4] is:");   // Result : Array_2[] is:
    for (i = 0; Array_2[i] != '\0'; i++)
    {
        printf("%c", Array_2[i]);
    }
    printf("\n");
    printf("The last valid index for Array_2[4] is %d.\n", i - 1);      // Result : 
    // ------------------------------------------------------------------------------

    return 0;
}

