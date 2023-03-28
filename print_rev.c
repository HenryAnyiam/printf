#include <stdlib.h>
#include "main.h"

int print_rev(va_list ap, flag_t __attribute__ ((unused)) *f, int i)
{
	int len;
	char *a;

	a = va_arg(ap, char *);
	if (a == NULL)
		return (_printf("%%%c", 'r'));
	for (i = 0; a[i] != '\0'; i++)
		;
	len = 0;
	for (; i >= 0; i--)
		len += _write(a[i]);
	return (len);
}

int print_rot(va_list ap, flag_t __attribute__ ((unused)) *f, int i)
{
	int len, j;
	char *a = va_arg(ap, char *);
	char *s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *r = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *new;

	new = malloc(sizeof(char) * 2);
	for (i = 0; a[i] != '\0'; i++)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			if (a[i] == s[j])
			{
				new[i] = r[j];
				break;
			}
			else
				new[i] = a[i];
		}
		new = (char *) _realloc(new, (i + 2), (i + 3));
	}
	new[i] = '\0';
	len = 0;
	for (i = 0; new[i] != '\0'; i++)
		len += _write(new[i]);
	return (len);
}
