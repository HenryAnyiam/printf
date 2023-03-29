#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  *print_bin - print int in binary
  *@ap: integer to be printed out
  *@f: flag
  *@i: precision
  *)
  *Return: length of printed characters
  */
int print_bin(va_list ap, flag_t *f, int i)
{
	unsigned int a = va_arg(ap, unsigned int);

	if (!a)
		return (_printf("%%%c", 'b'));
	return (convert(2, a, 0, f, 1, i));
}
