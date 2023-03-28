#include "main.h"
#include <stddef.h>

/**
  *funcs - selects particular function
  *@s: character
  *)
  *Return: function
  */
int (*funcs(char s))(va_list, flag_t *, int i)
{
	func_t func[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_dec},
		{'i', print_dec},
		{'b', print_bin},
		{'u', print_ui},
		{'o', print_oct},
		{'x', print_hex},
		{'X', _print_hex},
		{'S', _print_string},
/*		{'p', print_addr},*/
		{'r', print_rev},
		{'R', print_rot}
	};
	int i;
	
	for (i = 0; i < 12; i++)
	{
		if (s == func[i].c)
			return (func[i].f);
	}
	return (NULL);
}
