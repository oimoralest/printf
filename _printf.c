#include "holberton.h"
int _printf(const char *format, ...)
{
	function_t identifier_f[] = {{'c', _printf_c}, {'s', _printf_s},
		{'i', print_number}, {'d', print_number}, {'\0', NULL}};
	va_list flist;
	unsigned int len_printf = 0, i = 0, k = 0, flag = 0;
	char j = '\0';

	if (!format[i])
		return (0);
	va_start(flist, format);
	while (format[i])
	{
		for (i = 0; format[i] != '%' && format[i] != '\0'; i++)
		{
			j = format[i];
			len_printf += _putchar(j);
		}
		flag = i + 1;
		if (format[flag] == '%' && format[i])
		{
			_putchar('%');
			len_printf++;
			i += 2;
		}
		else
			for (k = 0; identifier_f[k].id && format[i]; k++)
			{
				if (identifier_f[k].id == format[flag])
				{
					len_printf += identifier_f[k].f(flist);
					i += 2;
					break;
				}
			}
		if (identifier_f[k].id == '\0')
			exit(98);
	}
	format[--i] == '\n' ? --len_printf : len_printf;
	va_end(flist);
	return (len_printf);
}
