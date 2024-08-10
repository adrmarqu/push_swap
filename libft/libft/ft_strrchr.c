/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:41:55 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 13:19:54 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (*s == '\0' && *s == (char)c)
		last = s;
	return ((char *)last);
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char	str2[] = "teste";

	printf("_%s_\n", strrchr(str2, 'e'));
	printf("_%s_\n", ft_strrchr(str2, 'e'));
	printf("_%s_\n", strrchr(str2, '\0'));
	printf("_%s_\n", ft_strrchr(str2, '\0'));
}*/
