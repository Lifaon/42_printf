# ft_printf
Reproduction of libc function **printf** and variants.<br />
- Conversions implemented: **%c %s %p %d %i %o %u %x %X %f**<br/>
- Bonus conversion implemented: **%b** (print an unsigned long long with base 2)

## Installation

### Unix operating systems
Pull the repository and run `make` inside to compile the library `libft_printf.a`.<br />
```
$ make path/to/repo
```
### Windows and other operating systems
Not implemented.<br />

## Usage
Include the header in your files and compile with library flags.<br />
```C
#include "ft_printf.h"
```
```
$ gcc -L path/to/lib -lft_printf
```
You will be able to use `ft_printf` and its 9 variants:<br />
```C
int	ft_printf(const char *format, ...);
int	ft_fprintf(FILE *stream, const char *fmt, ...);
int	ft_dprintf(int fd, const char *fmt, ...);
int	ft_sprintf(char *str, const char *fmt, ...);
int	ft_snprintf(char *str, size_t size, const char *fmt, ...);

int	ft_vprintf(const char *fmt, va_list ap);
int	ft_vfprintf(FILE *stream, const char *fmt, va_list ap);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);
int	ft_vsprintf(char *str, const char *fmt, va_list ap);
int	ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap);
```
