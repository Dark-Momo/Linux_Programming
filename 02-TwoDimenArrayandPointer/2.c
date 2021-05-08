#include <stdio.h>
#include <string.h>

int main(void)
{
    char Array_1[3][4] = {
                             {'A', 'B', 'C', 'D'},
			     {'E', 'F', 'G'},
			     {'H', 'I', 'J', 'K'}
    			 };

    printf("sizeof of Array_1 is:%zu\n", sizeof Array_1);    // 12
    
    // printf("strlen of Array_1 is:%zu\n", strlen(Array_1));   
    
    /* Above strlen() line has error like:
     * /usr/include/string.h:384:15: note: expected ‘const char *’ but argument is of type ‘char (*)[4]’
     * extern size_t strlen (const char *__s)
     */

    printf("Array_1, also the address of Array_1 is:%p\n", Array_1);
    printf("&Array_1, also an address, is:%p\n", &Array_1);

    printf("Array_1[0], also an address, is:%p\n", Array_1[0]);
    printf("&Array_1[0], also an address, is:%p\n", &Array_1[0]);








    return 0;
}
