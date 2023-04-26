#include<unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written to stdout.
 *
 * Return: On success, returns the character written to stdout.
 *         On failure, returns EOF and sets errno.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
