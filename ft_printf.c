/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:14:00 by vterroso          #+#    #+#             */
/*   Updated: 2023/05/08 13:41:43 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		len += ft_ptr(va_arg(args, unsigned long long));
	if (format == 'i' || format == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (format == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len += (ft_hex(va_arg(args, unsigned int), format));
	if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_formats(args, str[i]);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>


int	main(void)
{
	char c;
	char *s;
	int nb;
	unsigned int un;
	//unsigned int hex;

	c = 'f';
	s = "blablabla";
	nb = -351356;
	un = 9454999;
	
	printf("frase: %s letra:%c\n", s, c);
	ft_printf("frase: %s letra:%c\n", s, c);
	printf("puntero:%p\n", &s);
	ft_printf("puntero:%p\n", &s);
	printf("nb = %d  o %i\n", nb, nb);
	ft_printf("nb = %d  o %i\n", nb, nb);
	printf("Sin signo: %u\n", un);
	ft_printf("Sin signo: %u\n", un);
	return (0);
}*/