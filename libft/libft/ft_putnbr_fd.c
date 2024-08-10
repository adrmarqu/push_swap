/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:47 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/22 19:00:38 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

n: 		numero que enviar
fd:		fichero

desc:	Envia el numero n al file

putchar(char, int)

*/

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;
	char			c;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	ft_putchar_fd(c, fd);
}
