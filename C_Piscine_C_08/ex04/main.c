#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void				print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void				recursive_print_int(int n)
{
	char temp;

	temp = n % 10 + '0';
	if (n >= 10)
		recursive_print_int(n / 10);
	write(1, &temp, 1);
}

void				print_int(int n)
{
	recursive_print_int(n);
	write(1, "\n", 1);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		print_str(par[i].str);
		print_int(par[i].size);
		print_str(par[i].copy);
		i++;
	}
}

int	main(void)
{
	int ac = 3;
	char **av = (char **)malloc(sizeof(char *) * ac);
	av[0] = "123456789";
	av[1] = "abcdefghij";
	av[2] = "a1s2d3f4";
	ft_show_tab(ft_strs_to_tab(ac, av));
	return (0);
}
