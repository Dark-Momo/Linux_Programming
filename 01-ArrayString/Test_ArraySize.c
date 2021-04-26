#include <stdio.h>
#include <string.h>

char Array_3[] = {'m', 'a', 'l', 'u'};

int main (void)
{
    int  i;

    char Array_1[20] = {'A', 'B'};
    printf("sizeof Array_1[20] is : %zu\n", sizeof Array_1); 	// sizeof(Array_1) is the same
    								// Result : sizeof Array_1[20] is : 20

    for (i = 0; Array_1[i] != '\0'; i++){}
    printf("The last valid index for Array_1[20] is %d.\n", i - 1);

    // ------------------------------------------------------------------------------
    printf("\n");

    char Array_2[] = {'m', 'o', 'k', 'u'};
    printf("sizeof Array_2[] is : %zu\n", sizeof Array_2); 		// Result : sizeof Array_2[] is : 4

    printf("Array_2[] is:"); 	// Result : Array_2[] is:mokuAB
    for (i = 0; Array_2[i] != '\0'; i++)
    {
	printf("%c", Array_2[i]);
    }
    printf("\n");

    printf("The last valid index for Array_2[] is %d.\n", i - 1);	// Result : The last valid index for Array_2[] is 5.
    // Conclusion : 
    // 1. Array defined on stack (local variable) may not have '\0' at its end.
    // 2. But sizeof can always return its correct size at user's point.
    // 3. Searching /0 may get different size from using sizeof. 
    // 4. If add '\0' at the end of Array_2, sizeof Array_2[] is : 5. And Array_2[] is:moku.

    // -----------------------------------------------------------------------------
    printf("\n");

    printf("sizeof Array_3[] is : %zu\n", sizeof Array_3); // Result : sizeof Array_3[] is : 4

    printf("Array_3[] is:");	// Array_3[] is:malu
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
    /*
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
