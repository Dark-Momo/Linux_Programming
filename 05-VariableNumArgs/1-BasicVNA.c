#include <stdio.h>
#include <stdarg.h>

double average(int arg1, int arg2, ...);

int main(void)
{
    int a1 = 1, a2 = 2;

    printf("Average is:%.2lf\n", average(a1, a2, 3, 0));
    printf("Average is:%.2lf\n", average(a1, 3, a2, 0));
    // Form printf(), 'lf' is type for double.
    // Actually, 'l' means long, 'f' means float, so 'lf' means double.
    // float itself will be promoted to double when using printf().
    
    // For scanf(), 'f' and 'lf' has difference.

    return 0;
}

double average(int arg1, int arg2, ...)
{
    int sum = arg1 + arg2;
    int input;
    int count = 2;

    va_list pArgs;
    // Define a va_list that will hold the parameters from argument list.
    // pArgs is actually a pointer.

    va_start(pArgs, arg2);
    // Tell va system that arg2 (its position, not its name), will be the last fixed parameters input

    // We need to tell va system that what is the type of argument list '...' .
    while((input = va_arg(pArgs, int)) != 0)
    {
        sum = sum + input;
	count++;
    }

    va_end(pArgs); // End.

    return (double)(sum / count);
}
