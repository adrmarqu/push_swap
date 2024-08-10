/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:40:53 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 13:34:39 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

s : 			string desde la crear la substring
start: 			indice que indica el inicia en s donde empezar el substring
lem: 			longitud maxima del substring

return: 		substring resultante o NULL si falla reserva de memoria

Descripcio:		Reserva con malloc y devuelve una substring de s, la substring 
				empieza por start y su longitud maxima es len

*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*r;

	if (ft_strlen(s) == 0 || start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	r = ft_calloc(len + 1, sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s + start, len + 1);
	return (r);
}
