#include "main.h"

int _printf(const char *format, ...)
{
	int cont = 0;

	va_list(list);

	va_start(list, format);

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
		}
		format++;
	}
	va_end(list);
	return (cont);
}
