#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  *print_dec: prints out integer to standard output
  *@i: integer to print
  *)
  *Return: length of integer printed
  */
int print_dec(int i)
{
	int len, temp;
	char *s;

	len = 0;
	if (i < 0)
	{
		len += _write('-');
		i *= -(1);
	}
	if (i == 0)
	{
		len += _write('0');
		return (len);
	}
	temp = 0;
	s = malloc(sizeof(char) * 2);
	while (i > 0)
	{
		s[temp] = ((i % 10) + '0');
		i /= 10;
		s = (char *) _realloc(s, (temp + 2), (temp + 3));
		++temp;
	}
	--temp;
	while (temp >= 0)
	{
		len += _write(s[temp]);
		--temp;
	}
	free(s);
	return (len);
}
