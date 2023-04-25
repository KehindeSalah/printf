#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: a string containing directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
