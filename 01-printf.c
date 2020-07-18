#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int _strlen(const char *format)
{
	int i = 0;
	while (format[i])
		i++;
	return (--i);
}
int _putchar(char c)
{
	return (write(1, &c, 1));
}
int _printf(const char *format, ...)
{
	int i = 0;
	char j = '0';
	va_list flist;
	char *ptr = NULL;
	char *_null = "(null)";

	va_start(flist, format);
	while (format[i])
	{
		while (format[i] != '%')
		{
			j = format[i];
			_putchar(j);
			i++;
		}
		switch (format[++i])
		{
		case 's':
			ptr = va_arg(flist, char *);
			if (ptr == NULL)
			{
				while (*_null)
				{
					_putchar(*_null);
					_null++;
				}
			}
			while (*ptr)
			{
				_putchar(*ptr);
				ptr++;
			}
			break;
		case 'c':
			_putchar(va_arg(flist, int));
			break;
		case '%':
			_putchar('%');
			break;
		case 'i':
			print_number(va_list(flist, int));
			break;
		case 'd':
			break;
		default:
			break;
		}
		i++;
	}
	va_end(flist);
	return (0);
}

int main()
{
	char *str = "Well done!";
	char cr __attribute__((unused)) = '2';
	char *str2 __attribute__((unused)) = "hello";
	char *str3 = NULL;
	char cr2 __attribute__((unused)) = 'f';

	_printf("This is a test %s Hello", str);
	printf("%s %s", str3);
	putchar('n');
	return (0);
}