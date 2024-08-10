/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:26:44 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/11 15:12:36 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	s;
	void			*r;

	s = count * size;
	r = malloc(s);
	if (r == NULL)
		return (NULL);
	ft_memset(r, 0, s);
	return (r);
}
