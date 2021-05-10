#include <stdio.h>

void TestPrint(int argc, char** argv);

int main(void)
{
    /* Use below code to test the type of char [] and char [][] */
    // -----------------------------------------------------------------------------------------------------------------------------
    // char Array_1[10] = {'A','B','C'};
    // printf("%d", Array_1);
    
    /* Above 2 lines has warning below
     * 3-DoubleLayerPointer.c:7:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘char *’ [-Wformat=]
     *       printf("%d", Array_1);
     */
    // -----------------------------------------------------------------------------------------------------------------------------
    
    // char Array_2[3][10] = {"Hello", "ABCDEFG", "Kukumalu"};
    // printf("%s", Array_2);

    /* Above 2 lines has warning below
     * 3-DoubleLayerPointer.c:10:14: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
     *       printf("%s", Array_2);
     */
    // -----------------------------------------------------------------------------------------------------------------------------
    
    
    /* Start test char ** */
    
    // char Array[3][10] = {"Hello", "ABCDEFG", "Kukumalu"};

    /* Above lines passed to function will have arning and error below:
     * 3-DoubleLayerPointer.c:3:6: note: expected ‘char **’ but argument is of type ‘char (*)[10]’
     * void TestPrint(int argc, char** argv);
     * ^~~~~~~~~
     * parallels@parallels-Parallels-Virtual-Platform:~/Linux_Programming/02-TwoDimenArrayandPointer$ ./a.out
     * argc : 3
     * Segmentation fault (core dumped)
     */
    
    char *Array[3] = {"Hello", "ABCDEFG", "Kukumalu"};
    TestPrint(3, Array);

    return 0;
}

void TestPrint(int argc, char** argv)
{
    int i;
    printf("argc : %d\n", argc);

    for(i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
}

