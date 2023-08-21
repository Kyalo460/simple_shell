#include "main.h"

int _strncmp(char *str1, char *str2, int num)
{
	char *string1 = str1;
	char *string2 = str2;
	int i = 0, diff;

	while (i < num )
	{
		if (*string1 == '\0' && *string2 == '\0')
			break;

		diff = *string1++ - *string2++;
	
		if (diff != 0)
			return (diff);
		i++;
	}

	return (diff);
}
