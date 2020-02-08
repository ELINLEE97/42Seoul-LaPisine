#include <stdio.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int is_valid(char *base, int len);
int get_length(char *str);

int main(int argc, char **argv)
{
	int t = argc;
	t++;

	char base_from[] = "0123456789";
//	char base_to[] = "01";
	char base_to[] = "0123456789abcdef";
	printf("from=%s\nto=%s\n", base_from, base_to);

	printf("%s\n%s\n", argv[1], ft_convert_base(argv[1], base_from, base_to));
/*
//	char nbr[] = "      -+---++-2147483647";
	char nbr[] = "   -++--+2147483648";
	printf("%s\n%s\n--------\n", nbr, ft_convert_base(nbr, base_from, base_to));

	char nbr1[] = "      ++--+10";
	printf("%s\n%s\n--------\n", nbr1, ft_convert_base(nbr1, base_from, base_to));
*/

	return 0;
}
