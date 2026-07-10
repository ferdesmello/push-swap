#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	int returned = 0;
	int returned_ft = 0;

	int number = 1000;
	char character1 = 'A';
	char character2 = ' ';
	char *string = "Hello, World!";
	void *pointer1 = &number;
	void *pointer2 = 0;
	void *pointer3 = (void *)-1;
	unsigned int unsigned_number = 4294967295;
	int hex_number1 = 305441741;
	unsigned int hex_number2 = 305481741;

	returned = printf("0 %c 1 %s 2 %p A %d B %i C %u D %x E %X F %%.\n", character1, string, pointer1, number, number, unsigned_number, hex_number1, hex_number2);
	printf("returned: %d\n", returned);
	returned_ft = ft_printf("0 %c 1 %s 2 %p A %d B %i C %u D %x E %X F %%.\n", character1, string, pointer1, number, number, unsigned_number, hex_number1, hex_number2);
	printf("returned_ft: %d\n", returned_ft);

	returned = printf("0 %c 1 %s 2 %p A %d B %i C %u D %x E %X F %%.\n", character2, string, pointer2, -500000, -500000, -1, -50, -50);
	printf("returned: %d\n", returned);
	returned_ft = ft_printf("0 %c 1 %s 2 %p A %d B %i C %u D %x E %X F %%.\n", character2, string, pointer2, -500000, -500000, -1, -50, -50);
	printf("returned_ft: %d\n", returned_ft);

	returned = printf("0 %c 1 %s 2 %p A %d B %i C %u D %x E %X F %%.\n", character2, string, pointer3, -500000, -500000, -1, -50, -50);
	printf("returned: %d\n", returned);
	returned_ft = ft_printf("0 %c 1 %s 2 %p A %d B %i C %u D %x E %X F %%.\n", character2, string, pointer3, -500000, -500000, -1, -50, -50);
	printf("returned_ft: %d\n", returned_ft);

	return (0);
}
