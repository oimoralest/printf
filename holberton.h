#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
typedef struct id_function
{
	char id;
	int (*f)();
}function_t;
int _printf(const char *format, ...);

#endif