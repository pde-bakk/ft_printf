#include "ft_printf.h"

int	main(void)
{
	char		s1[] = "Lookie";
	char		s2[] = "Cancer";
	char		s3[] = "Tasty busy";
	char		s4[] = "Old man";

	char		c1 = '&';
	char		c2 = 'D';
	char		c3 = '7';
	char		c4 = 48;

	int			i1 = 8902;
	int			i2 = 97;
	int			i3 = 0;
	int			i4 = 7483648;

	unsigned	o1 = 11;
	unsigned	o2 = 67;
	unsigned	o3 = 88;
	unsigned	o4 = 111;

	unsigned	x1 = 15;
	unsigned	X1 = 15;
	unsigned	x2 = 23;
	unsigned	X2 = 23;
	unsigned	x3 = 64;
	unsigned	X3 = 64;
	unsigned	x4 = 128;
	unsigned	X4 = 128;

	int			H = 7;
	char		*str;

	ft_printf("\033[0;31m");
	ft_printf("%06i$ %5.8i\n", i1, i2);
	printf("%06i$ %5.8i\n", i1, i2);
	ft_printf("Strings: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("%-8s$ %07s$ %.8s$ %.*s$\n", s1, s2, s3, H, s4);
	printf("%-8s$ %07s$ %.8s$ %.*s$\n\n", s1, s2, s3, H, s4);
//	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Strings: -010Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("%-010s$ %+0s$ %-8.7s$ %#s$\n", s1, s2, s3, s4);
	printf("%-010s$ %+0s$ %-8.7s$ %#s$\n\n", s1, s2, s3, s4);
//	ft_printf("\033[0m");

	ft_printf("\033[0;32m");
	ft_printf("Chars: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("%7c$ %07c$ %.8c$ %.*c$\n", c1, c2, c3, 0, c4);
	printf("%7c$ %07c$ %.8c$ %.*c$\n\n", c1, c2, c3, 0, c4);
//	ft_printf("\033[0m");

	ft_printf("\033[1;32m");
	ft_printf("Chars: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("%-0c$ %+0c$ %-8.7c$ %#c$\n", c1, c2, c3, c4);
	printf("%-0c$ %+0c$ %-8.7c$ %#c$\n\n", c1, c2, c3, c4);
//	ft_printf("\033[0m");

	ft_printf("\033[0;33m");
	ft_printf("Integers: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("%-3i$ %7i$ %.8i$ %5.*i\n", i1, i2, i3, 8, i4);
	printf("%-3i$ %7i$ %.8i$ %5.*i\n\n", i1, i2, i3, 8, i4);
	ft_printf("\033[0m");

	ft_printf("\033[1;33m");
	ft_printf("Integers: -0Flag, +2Flag, -8.7Flag, #Flag:\n");
	ft_printf("%-0i$ %+2i$ %-8.7i$ %#i$\n", i1, i3, i3, i4);
	printf("%-0i$ %+2i$ %-8.7i$ %#i$\n\n", i1, i3, i3, i4);
	ft_printf("\033[0m");

	ft_printf("\033[0;34m");
	ft_printf("Octals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("%-3o$ %07o$ %.8o$ %.*o$\n", o1, o2, o3, 5, o4);
	printf("%-3o$ %07o$ %.8o$ %.*o$\n\n", o1, o2, o3, 5, o4);
	ft_printf("\033[0m");

	ft_printf("\033[1;34m");
	ft_printf("Octals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("%-3o$ %+0o$ %-8.7o$ %#o$\n", o1, o2, o3, o4);
	printf("%-3o$ %+0o$ %-8.7o$ %#o$\n\n", o1, o2, o3, o4);
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("hexadecimals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("%3x$ %07x$ %.8x$ %.*x$\n", x1, x2, x3, 11, x4);
	printf("%3x$ %07x$ %.8x$ %.*x$\n\n", x1, x2, x3, 11, x4);
	ft_printf("\033[0m");

	ft_printf("\033[1;35m");
	ft_printf("hexadecimals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("%-0x$ %+0x$ %-8.7x$ %x$\n", x1, x2, x3, x4);
	printf("%-0x$ %+0x$ %-8.7x$ %x$\n\n", x1, x2, x3, x4);
	ft_printf("\033[0m");

	ft_printf("\033[0;36m");
	ft_printf("HEXADECIMALS: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("%-3X$ %07X$ %.8X$ %.*X$\n", X1, X2, X3, 8, X4);
	printf("%-3X$ %07X$ %.8X$ %.*X$\n\n", X1, X2, X3, 8, X4);
	ft_printf("\033[0m");

	ft_printf("\033[1;36m");
	ft_printf("HEXADECIMALS: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("%-0X$ %+0X$ %-8.7X$ %#X$\n", X1, X2, X3, X4);
	printf("%-0X$ %+0X$ %-8.7X$ %#X$\n\n", X1, X2, X3, X4);
	ft_printf("\033[0m");

	ft_printf("\033[0;31m");
	ft_printf("Pointer addresses (discards all flags) :\n");
	ft_printf("%-8p$ %07p$ %.8p$ %.*p$\n", &s1, &s2, &s3, H, &s4);
	printf("%-8p$ %07p$ %.8p$ %.*p$\n\n", &s1, &s2, &s3, H, &s4);
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("\033[0;32m");
	ft_printf("\033[1;32m");
	ft_printf("\033[0;33m");
	ft_printf("\033[1;33m");
	ft_printf("\033[0;34m");
	ft_printf("\033[1;34m");
	return 0;
}
