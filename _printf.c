#include "main.h"

/**
 * _printf - Write a function that produces output according to a format
 * @format: is a character string.
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int cont = 0;

	va_list(list);

	va_start(list, format);
	
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			cont++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				char fav = va_arg(list, int);

				write(1, &fav, 1);
				cont++;
			}
			else if (*format == 's')
			{
				char *z = va_arg(list, char *);

				cont += write(1, z, strlen(z));
			}
			else if (*format == '%')
			{
				char cen = '%';

				write(1, &cen, 1);
				cont++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list, int);

				write_int(1, num);
				cont++;
			}
		}
		format++;
	}
	va_end(list);
	return (cont);
}
