#include <stdio.h>

enum Week {Mon, Tue, Wed, Thur, Fri, Sat, Sun};

typedef enum {Pang1, Pang2, Pang3} Pang;

int main(void)
{
    enum Week Today = Wed;
    
    printf("enum Week is %ld bytes.\n", sizeof(enum Week));
    
    // printf("enum Week is %ld bytes.\n", sizeof(Week));
    // Above line has error below:
    /* error: ‘Week’ undeclared (first use in this function) */
    
    printf("Today is %zu bytes.\n", sizeof(Today));

    Pang Mouse = Pang1;
    printf("Pang is %zu bytes.\n", sizeof(Pang));
    printf("Mouse is %zu bytes.\n", sizeof(Mouse));

    return 0;
}
