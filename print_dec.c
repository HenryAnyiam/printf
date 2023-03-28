#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  *print_dec: prints out integer to standard output
  *@i: integer to print
  *)
  *Return: length of integer printed
  */
int print_dec(va_list ap, flag_t *f, int i)
{
	int c;
	int a = va_arg(ap, int);

	c = 1;
	if (a < 0)
	{
		c = 0;
		a *= -(1);
	}
	return (convert(10, a, 0, f, c, i));
}
