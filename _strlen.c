#include "main.h"
/**
  *_strlen - returns the lenth of a string
  *@s: expects a string
  *Return: The lenght of string
  */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
