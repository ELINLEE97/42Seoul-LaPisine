#include <stdio.h>

char **ft_split(char *str, char *charset);

int main()
{
	char str[500] = "XU07 LEg11AIG62obhz0 HPmB6PhMxGYGGPjiAbs";
//	char str[500] = "tmiosegjpsgisio43";
	char charset[100] = "bR6rDPUz";
//	char charset[100] = "seg";
	char **result = ft_split(str, charset);

	for (int i = 0; result[i]; i++)
		printf("i=%d, %s\n", i, result[i]);
	
	return 0;
}
