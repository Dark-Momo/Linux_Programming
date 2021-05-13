/* Example from:
 * https://stackoverflow.com/questions/46547321/passing-variable-number-of-arguments-of-different-types-in-c
 */

#include <stdio.h>
#include <stdarg.h>

int customPrint(const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);

    count = 0;
    while (*format != '\0') 
    {
        switch (*format++) 
	{
            case 's':
                fprintf(stdout, "arg[%d]: %s\n", count, va_arg(args, const char *));
                break;
            case 'd':
                fprintf(stdout, "arg[%d]: %d\n", count, va_arg(args, int));
                break;
            case 'f':
                fprintf(stdout, "arg[%d]: %.4f\n", count, va_arg(args, double));
                break;
        }
        count += 1;
    }
    
    va_end(args);
    
    return 0;
}

int main(void)
{
    customPrint("sdf", "Example", 3, 3.1416);
    
    return 0;
}
