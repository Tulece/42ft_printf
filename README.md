FT_PRINTF

DESCRIPTION

The Printf project is part of the 42 School curriculum, aimed at recreating a simplified version of the printf function from the C standard library. This project helps in understanding variadic functions in C, string formatting, and converting different data types into strings.

Features

Handles various format specifiers like %c, %s, %d, %i, %u, %x, %X, and %p.

Implements basic string and character printing.

Converts integers to strings in decimal and hexadecimal formats.

Supports unsigned integers and pointer address printing.

How to Compile

To compile the library, use the provided Makefile:

make

This will create a libftprintf.a static library file.

USAGE

Include ft_printf.h in your C projects and link against libftprintf.a during compilation:

gcc -Wall -Wextra -Werror -I. -c your_project.c

gcc -o your_project your_project.o -L. -lftprintf

Core Functions

ft_printf as the main function, replicating the behavior of the original printf.

Helper functions like ft_putchar, ft_putstr, ft_putnbr, and ft_putptr to handle different conversions.

DEPENDENCIES

Standard C libraries for I/O and variadic functions handling.

GCC compiler for building the library.

Author

Tulece "anporced"
