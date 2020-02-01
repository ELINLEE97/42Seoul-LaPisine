#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

int main(void)
{
	char str[500] = "12aa34aa56a78aa90";
	char charset[500] = "aa";
	char **result = ft_split(str, charset);
	printf("%s\n%s\n--------------\n", str, charset);
	for(int i = 0; result[i]; i++)
		printf("%s\n", result[i]);

	return 0;
}
