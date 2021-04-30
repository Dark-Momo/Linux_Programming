#include <stdio.h>
#include <string.h>

int main (void)
{
    int  i;

    char * buf1 = "Hello";
    printf("%s\n", buf1);

    char buf2[] = "Hello";
    printf("%s\n", buf1);

    char buf3[] = {'H','e','l','l','o'};
    printf("%s\n", buf3);


    // -----------------------------------------------------------------------------
    /*
    printf("\n");

    printf("sizeof Array_3[] is : %zu\n", sizeof Array_3); // Result : sizeof Array_3[] is : 4

    printf("Array_3[] is:");    // Array_3[] is:malu
    for (i = 0; Array_3[i] != '\0'; i++)
    {
        printf("%c", Array_3[i]);
    }
    printf("\n");

    printf("The last valid index for Array_3[] is %d.\n", i - 1);
    // Conclusion :
    // 1. Array defined as global variable will have an automatic '\0' at its end, and makes everything correct as normal.

    // -----------------------------------------------------------------------------
    printf("\n");

    char * Str_1 = "Hello";
    printf("sizeof Str_1 is : %zu\n", sizeof Str_1);    // Result : sizeof Str_1 is : 8
    printf("strlen(Str_1) is : %zu\n", strlen(Str_1));  // Result : strlen(Str_1) is : 5

    // -----------------------------------------------------------------------------
    
    printf("\n");

    char Array_4[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    printf("Array_4[] is:");    // Array_3[] is:malu
    for (i = 0; Array_4[i] != '\0'; i++)
    {
        printf("%c", Array_4[i]);
    }
    printf("\n");

    printf("sizeof Array_4[] is : %zu\n", sizeof Array_4);
    printf("strlen(Array_4) is : %zu\n", strlen(Array_4));
    */

    return 0;
}

