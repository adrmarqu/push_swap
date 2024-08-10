/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:00:41 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:16:21 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int n)
{
	long int	aux;
	int			len;
	int			len2;

	aux = (long int)n;
	len = 0;
	len2 = 0;
	if (aux >= -2147483648 && aux <= 2147483647)
	{
		if (aux < 0)
		{
			len2 = ft_putchar('-');
			aux = -aux;
		}
		len = ft_putnbr((unsigned long long)aux, 10, 'a');
	}
	if (len2 == -1 || len == -1)
		return (-1);
	else
		len = len + len2;
	return (len);
}

int	ft_print_u(unsigned int n)
{
	unsigned long long	aux;
	int					len;

	aux = (unsigned long long)n;
	len = -1;
	if (aux <= 4294967295)
		len = ft_putnbr(aux, 10, 'a');
	return (len);
}

int	ft_print_xx(unsigned int n, char c)
{
	return (ft_putnbr(n, 16, c));
}
