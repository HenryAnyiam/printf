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
	fmt ft[] = {
		{'b', print_bin},
		{'u', print_ui},
		{'o', print_oct},
		{'x', print_hex},
		{'X', _print_hex},
		{'\0', NULL}
	};
	unsigned int len, i, j;
	va_list arg;

	if (format == NULL)
		return (0);
	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == '%')
				len += _write(format[i]);
			else if (format[i] == 'c')
				len += _write(va_arg(arg, int));
			else if (format[i] == 's')
				len += print_string(va_arg(arg, char *));
			else if ((format[i] == 'd') || (format[i] == 'i'))
				len += print_dec(va_arg(arg, int));
			else if ((format[i] == 'b') || (format[i] == 'u') || (format[i] == 'o')
					|| (format[i] == 'x') || (format[i] == 'X'))
			{
				j = 0;
				while (j < 5)
				{
					if (format[i] == ft[j].c)
					{
						len += ft[j].f(va_arg(arg, unsigned int));
						break;
					}
					++j;
				}
			}
			else
			{
				len += _write(format[i - 1]);
				len += _write(format[i]);
			}
		}
		else
			len += _write(format[i]);
		++i;
	}
	va_end(arg);
	_write(-1);
	return (len);
}
