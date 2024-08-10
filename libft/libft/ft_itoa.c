/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:36:25 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/20 18:40:03 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

n:			entero a convertir

return:		string que representa el numero o NULL

desc:		Utilizando malloc genera un string que represente el valor 
			entero recibido como argumento. Los numeros negativos tienen
			que gestionarse.

int:		2.147.483.647  <  -2.147.483.648

*/
#include "libft.h"

static size_t	ft_length_num(long int n)
{
	long int	l;

	l = 1;
	while (n >= 10)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static char	*ft_make_str(char *r, int l, long int n, int o)
{
	int	i;

	i = l - 1;
	while (i >= 0)
	{
		r[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (o < 0)
		r[0] = '-';
	r[l] = '\0';
	return (r);
}

char	*ft_itoa(int n)
{
	long int	n2;
	int			len;
	char		*r;
	int			m;

	n2 = n;
	m = 0;
	if (n2 < 0)
	{
		n2 = -n2;
		m = 1;
	}
	len = ft_length_num(n2) + m;
	r = (char *)ft_calloc(len + 1, sizeof(char));
	if (!r)
		return (0);
	return (ft_make_str(r, len, n2, n));
}
