#include <stdlib.h>
#include "main.h"

/**
  *add_flag - adds flag characters
  *@s: string
  *@f: flags
  *@len: length of string
  *@c: positive or negative
  *@i: flag precision
  *)
  *Return: new length
  */
char *add_flag(char *s, flag_t *f, int len, int c, int i)
{
	char *t;
	char fill = ' ';
	int a, temp;

	if (f->zero == 1)
		fill = '0';
	if (c == 0)
	{
		++len;
		s[len] = '-';
	}
	if ((c == 1) && (f->plus == 1))
	{
		++len;
		s[len] = '+';
	}
	else if ((c == 1) && (f->space == 1))
	{
		++len;
		s[len] = ' ';
	}
	if ((f->minus == 0) && (i > (len + 1)))
	{
		t = malloc(sizeof(char) * (len + (i - len) + 1));
		for (a = 0; i > (len + 1); i--, a++)
			t[a] = fill;
		for (; len >= 0; len--, a++)
			t[a] = s[len];
	}
	else if ((f->minus == 1) && (i > (len + 1)))
	{
		t = malloc(sizeof(char) * (len + (i - len) + 1));
		temp = len;
		for (a = 0; len >= 0; len--, a++)
			t[a] = s[len];
		for (; i > (temp + 1); i--, a++)
			t[a] = fill;
	}
	else if (i <= len)
	{
		t = malloc(sizeof(char) * (len + 1));
		for (a = 0; len >= 0; len--, a++)
			t[a] = s[len];
	}
	t[a + 1] = '\0';
	return (t);
}
