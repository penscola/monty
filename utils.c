#include <ctype.h>
#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(const char *string)
{
	if (string == NULL || *string == '\0')
		return 0;

	if (*string == '-')
		string++;

	while (*string != '\0')
	{
		if (!isdigit(*string))
			return 0;
		string++;
	}

	return 1;
}

/**
 * isnumber - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(const char *str)
{
	if (str == NULL || *str == '\0')
		return 0;

	int i = 0;

	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}

	return 1;
}
