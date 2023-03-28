#include <unistd.h>
#include "main.h"

/**
  *flags - get flags
  *@a: char to check
  *@f: flag array
  *)
  *Return: 1 if flag, else 0
  */
int flags(char a, flag_t *f)
{
	int i = 0;

	switch (a)
	{
		case 'l':
			f->l = 1;
			i = 1;
			break;
		case 'h':
			f->h = 1;
			i = 1;
			break;
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
		case '0':
			f->zero = 1;
			i = 1;
			break;
		case '-':
			f->minus = 1;
			i = 1;
			break;
		case '*':
			f->star = 1;
			i = 1;
			break;
		case '.':
			f->period = 1;
			i = 1;
			break;
	}
	return (i);
}
