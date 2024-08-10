/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:55:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/22 13:31:39 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

s:		string a iterar
f:		funcion a aplicar a cada caracter

desc:	A cada caracter de s se le aplica la funcion f que tiene como
		parametros el indice del caracter s y la direccion del caracter
		que podra modificarse si es necesario

*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}
