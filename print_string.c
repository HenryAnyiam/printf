#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_string - print a string
 * @a: string
 * Return: length of the string
*/
int print_string(char *a)
{
	unsigned int i;

	if (s == NULL)
	{
		return (0);
	}
	i = 0;
	while (a[i] != '\0')
		i += _write(s[i]);
	return (i);
}

