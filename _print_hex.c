#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
  *_print_hex - prints in capital hexadecimal
  *@i: integer
  *)
  *Return: length of character printed
  */
int _print_hex(va_list ap, flag_t *f, int i)
{
	unsigned int a = va_arg(ap, unsigned int);

	return (convert(16, a, 1, f, 1, i));
}
