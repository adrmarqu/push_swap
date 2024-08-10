/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:55:43 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/15 18:01:57 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

c: 			El caracter que enviar
fd:			El file descriptor sobre el que escribir

desc:		Envia el caracter c al file descriptor especificado

*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	a[1];

	a[0] = c;
	write(fd, a, 1);
}
