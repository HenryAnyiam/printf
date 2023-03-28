#include "main.h"

/**
  *reset - reset flag
  *@f: flag pointer
  */
void reset(flag_t *f)
{
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->zero = 0;
	f->minus = 0;
	f->star = 0;
	f->period = 0;
	f->l = 0;
	f->h = 0;
}
