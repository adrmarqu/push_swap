/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:18:25 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/16 13:48:53 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

s1: 			Primer string
s2: 			String a anadir al string s1

return:			Nueva string o NULL

descripcion:	Reserva con malloc y devuelve una nueva string 
				formada por la union de s1 y s2

*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s_size;
	char	*r;

	s_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = (char *)ft_calloc(s_size, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}
