#include <stdlib.h>
#include "main.h"

/**
  *print_rev - prints reverse of string
  *@ap: string
  *@f: flag characters
  *@i: precision
  *)
  *Return: returns length
  */
int print_rev(va_list ap, flag_t __attribute__ ((unused)) *f, int i)
{
	int len;
	char *a = va_arg(ap, char *);

	if (a == NULL)
		return (_printf("%%%c", 'r'));
	for (i = 0; a[i] != '\0'; i++)
		;
	len = 0;
	i--;
	for (; i >= 0; i--)
		len += _write(a[i]);
	return (len);
}

/**
  *print_rot - prints string wit rot13
  *@ap: string
  *@f: flag charcters
  *@i: precision
  *)
  *Return: legth
  */
int print_rot(va_list ap, flag_t __attribute__ ((unused)) *f, int i)
{
	int len, j;
	char *a = va_arg(ap, char *);
	char *s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *r = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *new;

	if (a == NULL)
		return (_printf("%%%c", 'R'));
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
