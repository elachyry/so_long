/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:59:27 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 10:32:35 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putchar(const unsigned char c)
{
	if (write(1, &c, 1) == 1)
		return (1);
	else
		return (-1);
}

int	ft_putstr(const char *str)
{
	int	printedlen;
	int	i;
	int	result;

	printedlen = 0;
	i = 0;
	result = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		result = ft_putchar(str[i]);
		if (result == -1)
			return (-1);
		printedlen += result;
		i++;
	}
	return (printedlen);
}

static int	ft_conversion(va_list args, const char fs)
{
	int	i;
	int	printedlen;

	i = 0;
	printedlen = 0;
	if (fs == 'c')
		printedlen = ft_putchar(va_arg(args, unsigned int));
	else if (fs == 's')
		printedlen = ft_putstr(va_arg(args, char *));
	else if (fs == 'p')
		printedlen = ft_printf_ptr(va_arg(args, size_t));
	else if (fs == 'i' || fs == 'd')
		printedlen = ft_printf_int(va_arg(args, int));
	else if (fs == 'u')
		printedlen = ft_printf_unsigned(va_arg(args, unsigned int));
	else if (fs == 'x' || fs == 'X')
		printedlen = ft_printf_hex(va_arg(args, unsigned int), fs);
	else if (fs == '%')
		printedlen = ft_putchar('%');
	return (printedlen);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printedlen;
	int		result;

	printedlen = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			result = ft_conversion(args, *((format++) + 1));
			if (result == -1)
				return (-1);
			printedlen += result;
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			printedlen++;
		}
		format++;
	}
	va_end(args);
	return (printedlen);
}
