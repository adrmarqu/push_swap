/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:29:43 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/20 14:43:22 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

s1: 		string que debe ser recortada
set: 		caracteres a eliminar de la string

return: 	string recortada o NULL

desc: 		Eliminar todos los caracteres set de la string s1 desde el 
			principio y el final hasta encontrar un caracter que no este 
			en set

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
*/

#include "libft.h"

static int	ft_found(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	size_t	i;
	size_t	first;
	size_t	last;

	first = 0;
	while (s1[first] && ft_found(s1[first], set))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_found(s1[last - 1], set))
		last--;
	r = (char *)ft_calloc((last - first + 1), sizeof(*s1));
	if (!r)
		return (NULL);
	i = 0;
	while (first < last)
		r[i++] = s1[first++];
	r[i] = 0;
	return (r);
}

/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	*strtrim;
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		if (!(strtrim = ft_strtrim(s1, " ")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 2)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "te")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 3)
	{
		char s1[] = " lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "l ")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 4)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "tel")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 5)
	{
		char s1[] = "          ";
		if (!(strtrim = ft_strtrim(s1, " ")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}*/
