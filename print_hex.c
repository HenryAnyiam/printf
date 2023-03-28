#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  *print_hex - prints in hexadecimal
  *@i: integer
  *)
  *Return: length of characters printed
  */
int print_hex(va_list ap, flag_t *f, int i)
{
	unsigned int a = va_arg(ap, unsigned int);

	return (convert(16, a, 0, f, 1, i));
}
