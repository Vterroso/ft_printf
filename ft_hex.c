/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:41 by vterroso          #+#    #+#             */
/*   Updated: 2023/05/08 16:07:44 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_hex(unsigned int nb, char format)
{
	int	len;

	len = ft_hex_len(nb);
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb >= 16)
	{
		ft_hex(nb / 16, format);
		ft_hex(nb % 16, format);
	}
	else if (nb > 9)
	{
		if (format == 'x')
			ft_putchar((nb - 10) + 'a');
		else if (format == 'X')
			ft_putchar((nb - 10) + 'A');
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
