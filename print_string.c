#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_string - print a string
 * @a: string
 * Return: length of the string
*/
int print_string(va_list ap, flag_t *f, int i)
{
	int a, j, len;
	char *s = va_arg(ap, char *);

	if (s == NULL)
	{
		return (0);
	}
	a = 0;
	len = 0;
	while (s[a] != '\0')
		a++;
	j = a - 1;
	if (f->period == 1)
		j = i - 1;
	if ((i > j) && (f->minus == 0))
		for (; i > (j + 1); --i)
			len += _write(' ');
	a = 0;
	while (a <= j)
	{
		len += 	_write(s[a]);
		a++;
	}
	if  ((i > j) && (f->minus == 1))
		for (; i > (j + 1); --i)
			len += _write(' ');
	return (len);
}

int print_char(va_list ap, flag_t *f, int i)
{
	int len;
	char s = va_arg(ap, int);

	len = 0;
	if ((i > 1) && (f->minus == 0))
		for (; i > 0; --i)
			len += _write(' ');
	len += _write(s);
	if ((i > 1) && (f->minus == 1))
		for (; i > 0; --i)
			len += _write(' ');
	return (len);
}
