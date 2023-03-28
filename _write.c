#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _write - use a local buffer of 1024 chars in order to call write
 * @c: char
 * Return: 1
*/
int _write(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1 || (i == 1024))
	{
		write(1, &buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}
	return (1);
}

/**
  *_writes - writes string
  *@s: string
  *)
  *Return: length of string
  */
int _writes(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i += _write(s[i]);
	return (i);
}
