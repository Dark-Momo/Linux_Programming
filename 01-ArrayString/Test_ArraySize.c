#include <stdio.h>

char Array_2[] = {'m', 'o', 'k', 'u'};

int main (void)
{
    int  i;

    char Array_1[20] = {'A', 'B'};
    printf("sizeof Array_1 is : %zu\n", sizeof Array_1); // sizeof(Array_1) is the same

    for (i = 0; Array_1[i] != '\0'; i++){}
    printf("i = %d for Array_1.\n", i);

    // ------------------------------------------------------------------------------
    // char Array_2[] = {'m', 'o', 'k', 'u'};
    printf("sizeof Array_2 is : %zu\n", sizeof Array_2);

    for (i = 0; Array_2[i] != '\0'; i++)
    {
	printf("%c", Array_2[i]);
    }
    printf("\ni = %d for Array_2.\n", i);

    return 0;
}
