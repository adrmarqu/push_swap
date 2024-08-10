/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:48:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/22 13:31:52 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*

s:			string que iterar
f:			funcion a aplicar sobre cada caracter

return:		string creada tras el correcto uso de f sobre cada caracter o NULL

desc:		A cada caracter de la string s aplica la funcion f dando como
			parametro el indice de cada caracter dentro de s y el propio
			caracter. Genera una nueva string con el resultado del uso
			sucesivo de f.

*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*r;

	if (!s || !f)
		return (NULL);
	r = ft_strdup(s);
	if (!r)
		return (NULL);
	i = 0;
	while (i < ft_strlen(r))
	{
		r[i] = f(i, r[i]);
		i++;
	}
	return (r);
}
