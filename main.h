#ifndef _main_h_
#define _main_h_

#include <stdarg.h>

/**
  *struct flag - flag characters
  *@plus: flags '+'
  *@space: flags ' '
  *@hash: flags '#'
  *@zero: flags '0'
  *@minus: flags '-'
  *@star: flags '*'
  *@period: flags '.'
  *@l: flags l
  *@h: flags h
  */
typedef struct flag
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
	int star;
	int period;
	int l;
	int h;
} flag_t;

/**
  *struct fmt - format
  *@c: format character
  *@f: format function
  */
typedef struct fmt
{
	char c;
	int (*f)(va_list, flag_t *, int i);
} func_t;

int _printf(const char *format, ...);
int print_string(va_list ap, flag_t *f, int i);
int print_dec(va_list ap, flag_t *f, int i);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int print_bin(va_list ap, flag_t *f, int i);
int print_ui(va_list ap, flag_t *f, int i);
int print_oct(va_list ap, flag_t *f, int i);
int print_hex(va_list ap, flag_t *f, int i);
int _print_hex(va_list ap, flag_t *f, int i);
int _write(char c);
int _print_string(va_list ap, flag_t *flags, int i);
int flags(char c, flag_t *f);
int (*funcs(char s))(va_list, flag_t *, int);
int print_char(va_list ap, flag_t *f, int i);
int print_per(va_list ap, flag_t *f, int i);
int print_addr(va_list ap, flag_t *f, int i);
int print_rev(va_list ap, flag_t *f, int i);
int print_rot(va_list ap, flag_t *f, int i);
int convert(int base, unsigned long int num, int cap, flag_t *f, int sign, int pre);
char *add_flag(char *s, flag_t *f, int len, int c, int i);
int _writes(char *s);
int print_char(va_list ap, flag_t *f, int i);
int print_rev(va_list ap, flag_t *f, int i);
int print_rot(va_list ap, flag_t *f, int i);
void reset(flag_t *f);

#endif
