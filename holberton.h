#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
typedef struct id_function
{
	char id;
	int (*f)();
}function_t;
int _printf(const char *format, ...);
int _putchar(char c);
int _printf_c(va_list flist);
int _printf_s(va_list flist);
int _printf_i(va_list flist);
#endif
