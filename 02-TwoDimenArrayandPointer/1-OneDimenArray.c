#include <stdio.h>

int main(void)
{
    char Array[5] = {'A', 'B', 'C', 'D', 'E'};
    printf("Array is    :%p\n", Array);
    printf("&Array is   :%p\n", &Array);
    printf("&Array[0] is:%p\n", &Array[0]);
    
    printf("*Array is   :%c\n", *Array);
    printf("*(&Array) is:%s\n", *(&Array));

    printf("Array + 1 = %p : (&Array) + 1 = %p.\n", Array + 1, (&Array) + 1);

    printf("Print Array using *(Array + i) form:");
    for (int i = 0; i < 5; i++)
        printf("%c", *(Array + i));

    printf("\n\n");

    char *pArray = Array;
    printf("pArray is   :%p\n", pArray);
    printf("&pArray is  :%p\n", &pArray);
    printf("*pArray is  :%c\n", *pArray);

    printf("\n");

    // Declare a pointer to an char array of 5 chars.
    // "char (*p)[5] = Array" also compiles with warning, but print OK as "char (*p)[5] = &Array"
    char (*p)[5] = &Array;
    printf("p is        :%p\n", p);
    printf("*p is       :%p\n", *p);

    printf("Print Array using char (*p)[5]:");
    for (int i = 0; i < 5; i++)
        printf("%c", *((*p) + i));
    printf("\n");

    printf("Print using '%%s' for p :%s\n", p);
    printf("Print using '%%s' for *p:%s\n", *p);

    return 0;
}
