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
	char *s = va_arg(ap, char *);

	if (s == NULL)
		return (_printf("%%%c", 's'));
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

	if (c == NULL)
		return (_printf("%%%c", 'c'));
	len = 0;
	if (f->zero == 1)
		fill = '0';
	if ((i > 1) && (f->minus == 0))
		for (; i > 1; --i)
			len += _write(' ');
	len += _write(s);
	if ((i > 1) && (f->minus == 1))
		for (; i > 1; --i)
			len += _write(' ');
	return (len);
}
