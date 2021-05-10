#include <stdio.h>
#include <string.h>

int main(void)
{
    char Array[3][4] = {
                             {'A', 'B', 'C', 'D'},
			     {'E', 'F', 'G'},
			     {'H', 'I', 'J', 'K'}
    			 };

    printf("sizeof of Array is                   :%zu\n", sizeof Array);        	// 12    
    printf("strlen of Array is                   :%zu\n", strlen(Array));   		// 7
    /* Above strlen() line has warning like:
     * /usr/include/string.h:384:15: note: expected ‘const char *’ but argument is of type ‘char (*)[4]’
     * extern size_t strlen (const char *__s)
     */
    printf("\n");

    printf("Array, also the address of Array is  :%p\n", Array);
    printf("&Array, also an address, is          :%p\n", &Array);
    printf("\n");
    
    printf("Array[0], also an address, is        :%p\n", Array[0]);
    printf("&Array[0], also an address, is       :%p\n", &Array[0]);
    printf("\n");

    printf("&Array[0][0], also an address, is    :%p\n", &Array[0][0]);
    printf("\n");

    printf("&Array + 1 = %p\n", &Array + 1);
    printf("Array + 1  = %p\n", Array + 1);
    printf("*Array + 1 = %p\n", *Array + 1);
    printf("\n");

    // Display Array[0][0], *Array[0] and **Array
    printf("Array[0][0] is:%c\n", Array[0][0]);
    printf("*Array[0]   is:%c\n", *Array[0]);
    printf("**Array     is:%c\n", **Array);
    printf("\n");

    printf("Print Array using %%c and %%d while scaning using *((*Array) + i):\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%c", *((*Array) + i));
    }
    printf("\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", *((*Array) + i));
    }
    printf("\n");
    /*
     * Array相当于Array[0], 是个char *型; 然后*Array + i每次add的是一个char的长度, 这样才算实现对Array进行一个byte为单位的遍历. 
     * 好比有个数组, char Arr[10]，你用Arr + 1获得的是Arr[1]的地址, 这里的增加量是Arr的成员的占用空间尺寸;
     */

    return 0;
}
