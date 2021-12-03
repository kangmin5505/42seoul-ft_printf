#include <stdio.h>
#include <stdarg.h>

void	test(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	printf("result : %llx\n", va_arg(ap, unsigned long long));
	va_end(ap);
}
int	main(void)
{
	printf("str : %.0s|\n", "abc");
	printf("str : %-5s|\n", "abc");
	printf("str : %5.2s|\n", "abc");
	printf("str : %5s|\n", "abc");
	printf("str : %6x|\n", 11);
	printf("working\n");
	printf("test : %.5s\n", "ab");
	printf("test : %.5s\n", "abcdef");
	printf("test : %.5d\n", 1234567);
	printf("test : %-3s|\n", "qwer");

}
