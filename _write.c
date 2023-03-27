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
	static char buffer(1024);
	static int i;

	if (c == -1 || (i == 1024))
	{
		write(i, &buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}
	return (i);
}
