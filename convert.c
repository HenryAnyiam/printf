#include <stdlib.h>
#include "main.h"

/**
  *convert - converts integer
  *@base: base
  *@i: integer
  *@c: sign
  *@f: flag characters
  *@sign: sign
  *@pre: precision
  *)
  *Return: length
  */
int convert(int base, unsigned long int i, int c, flag_t *f, int sign, int pre)
{
	unsigned int j, rem;
	char *s;

	j = 0;
	s = malloc(sizeof(char) * 2);
	if (i == 0)
	{
		s[0] = '0';
		return (_writes(add_flag(s, f, j, sign, pre)));
	}
	while (i > 0)
	{
		rem = i % base;
		if (rem < 10)
			s[j] = rem + '0';
		else
		{
			if (c == 0)
				s[j] = rem + 87;
			else if (c == 1)
				s[j] = rem + 55;
		}
		i /= base;
		s = (char *) _realloc(s, (j + 2), (j + 3));
		++j;
	}
	--j;
	if (f->hash == 1)
	{
		if ((base == 16) && (c == 0))
		{
			s[j] = 'x';
			s[j + 1] = '0';
			j++;
		}
		else if ((base == 16) && (c == 1))
		{
			s[j] = 'X';
			s[j + 1] = '0';
			j++;
		}
		else if (base == 8)
		{
			s[j] = '0';
			j++;
		}
	}
	return (_writes(add_flag(s, f, (j - 1), sign, pre)));
}
