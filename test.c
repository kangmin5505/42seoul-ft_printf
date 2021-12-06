#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	a, b;

	printf("%-1c|\n", '0');
	printf(" %-2c |\n", '0');
	printf(" %-3c|\n", '0' - 256);
	printf("%-4c |\n", '0' + 256);
	printf("%4c |\n", '0' + 256);
	printf(" %-1c %-2c %-3c |\n", '0', 0, '1');
	printf(" %-1c %-2c %-3c |\n", ' ', ' ', ' ');
	printf(" %-1c %-2c %-3c |\n", '1', '2', '3');
	printf(" %-1c %-2c %-3c |\n", '2', '1', 0);
	printf(" %-1c %-2c %-3c |\n", 0, '1', '2');
	printf("%1s|\n", "");
	printf("===================================|\n");
	ft_printf("%-1c|\n", '0');
	ft_printf(" %-2c |\n", '0');
	ft_printf(" %-3c|\n", '0' - 256);
	ft_printf("%-4c |\n", '0' + 256);
	ft_printf("%4c |\n", '0' + 256);
	ft_printf(" %-1c %-2c %-3c |\n", '0', 0, '1');
	ft_printf(" %-1c %-2c %-3c |\n", ' ', ' ', ' ');
	ft_printf(" %-1c %-2c %-3c |\n", '1', '2', '3');
	ft_printf(" %-1c %-2c %-3c |\n", '2', '1', 0);
	ft_printf(" %-1c %-2c %-3c |\n", 0, '1', '2');
	ft_printf("%1s|\n", "");
}
