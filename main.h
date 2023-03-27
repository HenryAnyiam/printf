#ifndef _main_h_
#define _main_h_

/**
  *struct fmt - struct fmt
  *
  *@c: character
  *@f: associated function
  */
typedef struct fmt
{
	char c;
	int (*f)(unsigned int i);
} fmt;

int _printf(const char *format, ...);
int print_string(char *s);
int print_dec(int i);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int print_bin(unsigned int i);
int print_ui(unsigned int i);
int print_oct(unsigned int i);
int print_hex(unsigned int i);
int _print_hex(unsigned int i);
int _write(char c);

#endif
