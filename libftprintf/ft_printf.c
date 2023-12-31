/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:03:55 by aabashee          #+#    #+#             */
/*   Updated: 2023/11/19 13:37:37 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conditions(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, const char *)));
	else if (format == 'p')
		return (ft_printptr(args));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsignbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned long), 0));
	else if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned long), 1));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_conditions(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	printf("%d\n", ft_printf("%s\n", "aaaa"));
	printf("%d\n", printf("%s\n", "aaaa"));
}
