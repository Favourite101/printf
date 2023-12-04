#include "main.h"

/**
 * str_len - this get the length of the string
 *
 * @v: the string
 *
 * Return: the string length
 */

int str_len(char *v)
{
	int cont;
	int len = 0;

	if (v)
	{
	for (cont = 0; v[cont] != '\0'; cont++)
	{
		_putchar(v[len]);
	}
	}
	return (len);
}
