/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:28:03 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/13 12:33:00 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

s: 		string
fd: 	fichero

desc:	escribir un string en un fichero

*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
