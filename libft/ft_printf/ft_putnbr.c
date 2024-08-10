/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:01:07 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/02/09 20:49:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_num(unsigned long long nbr, unsigned long long base, char type)
{
	unsigned int	x;
	char			h;

	x = (nbr % base);
	h = HEX[x];
	if (x > 9 && type == 'x')
		h = ft_tolower(h);
	return (h);
}

static void	ft_reverse(char	*str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

static int	ft_sizenumber(unsigned long long n, unsigned long long base)
{
	int	len;

	len = 1;
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_putnbr(unsigned long long nbr, unsigned long long base, char type)
{
	char	*r;
	int		i;
	int		len;

	r = (char *)ft_calloc(ft_sizenumber(nbr, base) + 1, sizeof(char));
	if (!r)
		return (-1);
	i = 0;
	while (nbr >= base)
	{
		r[i] = ft_num(nbr, base, type);
		nbr = nbr / base;
		i++;
	}
	r[i] = ft_num(nbr, base, type);
	r[i + 1] = '\0';
	ft_reverse(r);
	len = ft_putstr(r);
	free(r);
	return (len);
}
