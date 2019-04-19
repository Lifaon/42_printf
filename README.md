# ft_printf
Reproduction of libc function **printf** and variants.<br />
- Conversions:
  - Originals: **%c %s %p %d %i %o %u %x %X %f**
  - New: **%b** (print a number in binary)
- Special size flags: **hh h l ll** for integers and **L** for floating point numbers
- Flags: **# - 0 + '_space_'**
- Width and precision, along with their **\*** flag

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
$ gcc -I path/to/lib/includes -L path/to/lib -lft_printf
```
You will be able to use **`ft_printf`** and 7 of its already existing variants (fprintf & vfprintf are missing due to function restrictions), in addition to a personnalized variant: **`ft_smprintf`**<br />
```C
int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *fmt, ...);
int	ft_sprintf(char *str, const char *fmt, ...);
int	ft_snprintf(char *str, size_t size, const char *fmt, ...);

int	ft_vprintf(const char *fmt, va_list ap);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);
int	ft_vsprintf(char *str, const char *fmt, va_list ap);
int	ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap);

/* ft_smprintf works like sprintf but takes (char **) instead of (char *), and
** determines the needed memory to malloc the pointed string, which is is then
** filled like sprintf would.*/
int	ft_smprintf(char **ptr, const char *fmt, ...);
```
