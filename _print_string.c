#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int _print_string(va_list ap, flag_t __attribute__ ((unused)) *f, int __attribute__ ((unused)) a)
{
	int len, i;
	char *s = va_arg(ap, char *);

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if(((s[i] > 0) && (s[i] < 32)) || (s[i] >= 127))
		{
			len += _write('\\');
			len += _write('x');
			len += _write('0');
			len += _write((s[i] % 16) + 87);
		}
		else
			len += _write(s[i]);
		i++;
	}
	return (len);
}
