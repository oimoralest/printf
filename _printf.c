#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "holberton.h"
int _putchar(char c)
{
	int i = 0;

	i = write(1, &c, 1);
	return (i);
}
int _printf_c(va_list flist)
{
	char c;

	c = va_arg(flist, int);
	return (write(1, &c, 1));
}
int _printf_s(va_list flist)
{
	char *ptr = NULL, *_null = "(null)";
	unsigned int len = 0;

	ptr = va_arg(flist, char *);
	if (ptr == NULL)
	{
		while (*_null)
		{
			_putchar(*_null);
			_null++;
			len++;
		}
	}
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
		len++;
	}
	return (len);
}
int _printf(const char *format, ...)
{
	function_t identifier_f[] = {
		{'c', _printf_c},
		{'s', _printf_s},
		{'\0', NULL}
	};
	va_list flist;
	unsigned len_printf = 0, i = 0, k = 0, flag = 0;
	char j = '\0';

	if (!format[i])
		return (0);
	va_start(flist, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			j = format[i];
			len_printf += _putchar(j);
			i++;
		}
		flag = i + 1;
		while (identifier_f[k].id && format[i])
		{	
			if (identifier_f[k].id == format[flag])
			{
				len_printf += identifier_f[k].f(flist);
				i += 2;
				break;
			}
			k++;
		}
	}
	va_end(flist);
	return (len_printf);
			
}
int main()
{
	int len = 0;
	
	len = _printf("Hola: %c Well %s done!", 'f', "Test");
	printf("\n%i\n", len);
	return (0);
}
