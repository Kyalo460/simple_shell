#include "main.h"

char *rev(char *ptr, size_t n);

/**
  *array - converts integers to strings
  *@n: the integer to be converted
  *
  *Return: returns a pointer to the string
  */
char *array(size_t n)
{
	int num = 1, index = 0;
	size_t n_copy = n;
	char *ptr, *new;

	while (n_copy > 10)
	{
		n_copy /= 10;
		num++;
	}
	n_copy = n;

	ptr = malloc(1 * (num + 1));

	if (ptr == NULL)
		return (NULL);

	while (n_copy > 0)
	{
		ptr[index] = ((n_copy % 10) + '0');
		n_copy /= 10;
		index++;
	}
	ptr[index] = '\0';
	new = rev(ptr, num);
	free(ptr);
	return (new);
}

/**
  *rev - reverses a string
  *@ptr: string to be reversed
  *@n: number of characters in string
  *
  *Return: returns the reversed string
  */
char *rev(char *ptr, size_t n)
{
	char *array;
	size_t index = 0, idx = 0;

	array = malloc(1 * (n + 1));
	if (array == NULL)
		return (NULL);

	while (ptr[index])
		index++;

	index--;
	while (idx < n)
	{
		array[idx] = ptr[index];
		idx++;
		index--;
	}
	array[idx] = '\0';

	return (array);
}
