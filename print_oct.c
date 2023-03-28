#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
  *print_oct - prints in octadecimal
  *@i: integer
  *)
  *Return: length of characters
  */
int print_oct(va_list ap, flag_t *f, int i)
{
	unsigned int a = va_arg(ap, unsigned int);

	return (convert(8, a, 0, f, 1, i));
}
