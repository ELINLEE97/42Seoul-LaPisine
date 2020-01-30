#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
	char nbr[] = "      +-++-21a47483647";
	char base_from[] = "0123456789";
	char base_to[] = "0123456789abcdef";
	printf("%s\n%s\n%s\n%s\n", nbr, base_from, base_to, ft_convert_base(nbr, base_from, base_to));

	return 0;
}
