/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:52:57 by vterroso          #+#    #+#             */
/*   Updated: 2023/05/08 13:42:53 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long nb)
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

static void	ft_ptr_print(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_ptr_print(nb / 16);
		ft_ptr_print(nb % 16);
	}
	else if (nb > 9)
		ft_putchar((nb - 10) + 'a');
	else
		ft_putchar(nb + '0');
}

int	ft_ptr(unsigned long long nb)
{
	ft_putstr("0x");
	if (nb == 0)
	{
		ft_putchar('0');
		return (3);
	}
	else
		ft_ptr_print(nb);
	return (ft_ptr_len(nb) + 2);
}