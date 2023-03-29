#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  *_print_string - prints string and non printable characters
  *@ap: string
  *@f: flag characters
  *@a: precision
  *)
  *Return: length
  */
int _print_string(va_list ap, flag_t __attribute__ ((unused)) *f, int __attribute__ ((unused)) a)
{
	int len, i;
	int c;
	char *s = va_arg(ap, char *);

	if (s == NULL)
		return (_printf("%%%c", 'S'));
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if(((s[i] > 0) && (s[i] < 32)) || (s[i] >= 127))
		{
			len += _write('\\');
			len += _write('x');
			c = s[i];
			if ((c / 16) > 9)
				len += _write((c / 16) + 55);
			else
				len += _write((c / 16) + '0');
			c %= 16;
			if (c > 9)
				len += _write(c + 55);
			else
				len += _write(c + '0');
		}
		else
			len += _write(s[i]);
		i++;
	}
	return (len);
}
