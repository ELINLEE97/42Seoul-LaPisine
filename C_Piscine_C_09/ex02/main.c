#include <stdio.h>

char **ft_split(char *str, char *charset);

int main()
{
	char str[500] = "11";
	char charset[100] = "1b";
	char **result = ft_split(str, charset);

	for (int i = 0; result[i]; i++)
		printf("i=%d, %s\n", i, result[i]);
	
	return 0;
}
