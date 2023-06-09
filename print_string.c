#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
  *print_string - prints the string format
  *@ap: string argument
  *@f: flag characters
  *@i: precision
  *)
  *Return: length
  */
int print_string(va_list ap, flag_t *f, int i)
{
	int a, j, len;
	char fill = ' ';
	char *s = va_arg(ap, char *);

	if (!s)
		return (_writes("(null)"));
	a = 0;
	if (f->zero == 1)
		fill = '0';
	len = 0;
	while (s[a] != '\0')
		a++;
	j = a - 1;
	if (f->period == 1)
		j = i - 1;
	if ((i > j) && (f->minus == 0))
		for (; i > (j + 1); --i)
			len += _write(fill);
	a = 0;
	while (a <= j)
	{
		len += 	_write(s[a]);
		a++;
	}
	if  ((i > j) && (f->minus == 1))
		for (; i > (j + 1); --i)
			len += _write(fill);
	return (len);
}

/**
  *print_char - prints character format
  *@ap: string argument
  *@f: flag chracters
  *@i: precision
  *)
  *Return: length
  */
int print_char(va_list ap, flag_t *f, int i)
{
	int len;
	char s = va_arg(ap, int);
	char fill = ' ';

	if (!s)
		return (_writes("(null)"));
	len = 0;
	if (f->zero == 1)
		fill = '0';
	if ((i > 1) && (f->minus == 0))
		for (; i > 1; --i)
			len += _write(fill);
	len += _write(s);
	if ((i > 1) && (f->minus == 1))
		for (; i > 1; --i)
			len += _write(fill);
	return (len);
}
