#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int is_valid(char *base, int len);
int get_length(char *str);

int main(void)
{
	char nbr[] = "      -+---++-2147483647";
	char base_from[] = "0123456789";
	char base_to[] = "0123456789abcdef";
	printf("%s\n%s\n%s\n%s\n", nbr, base_from, base_to, ft_convert_base(nbr, base_from, base_to));

	printf("%d\n", is_valid(base_from, get_length(base_from)));

	return 0;
}
