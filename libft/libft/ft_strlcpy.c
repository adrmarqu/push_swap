/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:15:16 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 15:08:05 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*

#include <stdio.h>
#include <string.h>

int main()
{
	//char const src[20] = "Hola mundo";
	char dest[20] = "Hello world";
	//size_t size;

	//scanf("%ld", &size);
	strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	printf("\nOrignal: %s\n", dest);
	ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	printf("\nFT: %s\n", dest);
} 
*/
