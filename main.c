#include "ft_printf.h"

int	main(void)
{
	int	cnt;

	cnt = ft_printf("%.5s\n", "ab");
	printf("cnt : %d\n", cnt);
	cnt = ft_printf("%.s\n", "abcdef");
	printf("cnt : %d\n", cnt);
	cnt = ft_printf("%7s\n", "qwer");
	printf("cnt : %d\n", cnt);
}
