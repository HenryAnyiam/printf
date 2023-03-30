#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
  *print_addr - prints the string format
  *@ap: string argument
  *@f: flag characters
  *@i: precision
  *)
  *Return: length
  */
int print_addr(va_list ap, flag_t *f, int i)
{
	unsigned long int a = va_arg(ap, unsigned long int);

	if (!a)
		return (_writes("(nil)"));
	f->hash = 1;
	return (convert(16, a, 0, f, 1, i));
}
