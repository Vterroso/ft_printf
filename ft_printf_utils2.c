/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterroso <vterroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:20:56 by vterroso          #+#    #+#             */
/*   Updated: 2023/05/04 18:44:30 by vterroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb)
{
	int len;

	len = 0;
	while(nb)
		{
			nb /= 10;
			len++;
		}
	return (len);
}

int	ft_unsigned(unsigned int nb)
{
	int	len;

	len = ft_unsigned_len(nb);
	if (nb > 9)
	{
			ft_unsigned(nb / 10);
			ft_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}

