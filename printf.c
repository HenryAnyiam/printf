#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
  *_printf - prints to standard output
  *@format: string including format specifiers
  *)
  *Return: Number of characters printed
  */
int _printf(const char *format, ...)
{
	flag_t flag = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int len, i, c;
	int (*func)(va_list, flag_t *, int);
	va_list arg;

	if ((format == NULL) || ((format[0] == '%') && (!format[1])))
		return (-1);
	if ((format[0] == '%') && (format[1] == ' ') && (!format[2]))
		return (-1);
	va_start(arg, format);
	i = c = len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			while (flags(format[i], &flag))
				i++;
			while ((format[i] >= '0') && (format[i] <= '9'))
			{
				c *= 10;
				c += format[i] - '0';
				++i;
			}
			if (flag.star == 1)
				c = va_arg(arg, int);
			func = funcs(format[i]);
			if (format[i] == '%')
				len += _write('%');
			else if (func != NULL)
				len += func(arg, &flag, c);
			else
				len += _printf("%%%c", format[i]);
		}
		else
			len += _write(format[i]);
		reset(&flag);
		c = 0;
		i++;
	}
	va_end(arg);
	_write(-1);
	return (len);
}
