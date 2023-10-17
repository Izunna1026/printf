#include "main.h"
int print_str(char *string);
int _putchar(char c);
/**
 * _printf - print to standard output
 * @format: to format
 * Return: to return count
 */
int _printf(const char *format, ...)
{
	int count = 0, i;

	va_list data;

	va_start(data, format);

	for (i = 0; format[i] != '\0'; )
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(data, int));
					break;
				case 's':
					count += print_str(va_arg(data, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					break;
				}
			i += 2;
		}
	}
	return (count);
}
/**
 * print_str - to print str
 * @string: to print
 * Return: to return string
 */
int print_str(char *string)
{
	int count = 0;
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		count += _putchar(string[i]);
	}
	return (count);
}

#include <unistd.h>
/**
 * _putchar - function to return character to stdout
 * @c: the string
 * Return: to return c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
