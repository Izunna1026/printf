#include "main.h"
/**
 * _printf - to print to standard output
 * @format: the variable
 * Return: to return 0
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
		else if (format[i] == '%' && format[i+1] !=' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(data, int));
					break;
				case 's':
					count += printstring(va_arg(data, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
			}
			i += 2;
		}
	}
	return (count);
}
