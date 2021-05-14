#include <stdio.h>
#include <stdarg.h>

int fun(va_list ap)
{
	int i;
	int ret;

	ret = 0;
	for(i=0; i<10; i++)
    	ret += va_arg(ap, int);
	return (ret);
}

int sum(const char *str, ...)
{
    int res = 0;
    va_list ap;

    va_start(ap, str);
	res = fun(ap);
    va_end(ap);

    return res;
}

int main()
{
	const char *str = "abcd";

    printf("%d\n", sum(str, 1,2,3,4,5,6,7,8,9,10));

    return 0;
}
