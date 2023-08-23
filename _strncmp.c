#include "main.h"

/**
  *_strncmp - checks if two strings are the same
  *@str1: first string
  *@str2: second string
  *@num: number of bytes to compare
  *
  *Return: returns 0 if strings are the same
  */
int _strncmp(char *str1, char *str2, int num)
{
	char *string1 = str1;
	char *string2 = str2;
	int i = 0, diff;

	while (i < num)
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
