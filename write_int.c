#include "main.h"

/**
 * write_int - a function that writes an integer to a file
 * descriptor using the write function
 * @fd: file descriptor
 * @a: the integer
 *
 * Return: It returns the number of bytes written or an error
 */
ssize_t write_int(int fd, int a)
{
	char buffer[20], temp;
	size_t length = 0, i, j;
	
	if (a == 0)
	{
		buffer[length++] = '0';
	}
	else
	{
		while (a != 0 && length < sizeof(buffer))
		{
			buffer[length++] = '0' + a % 10;
			a /= 10;
		}
		for (i = 0, j = length - 1; i < j; ++i, --j)
		{
			temp = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp;
		}
	}
	return write(fd, buffer, length);
}
