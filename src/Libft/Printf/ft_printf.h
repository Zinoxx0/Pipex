#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	fnum(int number, int *length);
void	fhexadecimal(unsigned int x, int *length, char x_or_x);
void	funsigned_int(unsigned int u, int *length);
void	fpointer(size_t pointer, int *length);

void	fputchar(char chr, int *len);
void	fputstr(char *args, int *len);

int		ft_printf(const char *string, ...);

#endif