/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:00:26 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/02/09 20:51:54 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdir(void *p)
{
	unsigned long long	num;
	int					len;
	int					len2;

	len = ft_putstr("0x");
	num = (unsigned long long)p;
	len2 = ft_putnbr(num, 16, 'x');
	if (len == -1 || len2 == -1)
		return (-1);
	return (len + len2);
}
