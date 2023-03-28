#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int print_ui(va_list ap, flag_t *f, int i)
{
	unsigned int a = va_arg(ap, unsigned int);

	return (convert(10, a, 0, f, 1, i));
}
