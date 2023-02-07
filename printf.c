#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *str)
{
    int i;

    i=0;
    if (!str)
        str = "(null)";
    while(str[i])
        i+=write(1,&str[i],1);
    return (i);
}

int ft_putchar(char c)
{
    int i= 0;
    return (i+write(1, &c,1));
}

ft_putnbr(unsigned int n, int base)
{
    int i = 0;
    char *a,

    a = "0123456789abcdef";
    if (n > base)
        i+=ft_putnbr(n/base, base);
    return(i+=write(1,&a[n%base],1));
}

ft_putint(int n)
{
    int  i =0;
    if(n<0)
    {
        i+=putchar('-');
        n *= -1;
    }
    i+=ft_putnbr((unsigned int)n, 10);
    return (i);
}

int ft_printf(char *str, ...)
{
    int count=0;
    int i=-1;
    va_list args;

    va_start(args, str);
    while(str[++i])
    {
        if(str[i] == '%')
        {
            i++;
            if(str[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else  if (str[i] == 'd')
                count += ft_putint(va_arg(args, int));
            else if (str == 'x')
                count += ft_putnbr(va_arg(args, unsigned int), 16);
        }
        else
            count += ft_putstr(str[i]);
    }
    va_end(args);
    return (count);
}
