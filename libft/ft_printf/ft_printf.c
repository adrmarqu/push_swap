/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:21:39 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/02/12 18:50:14 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_readstr(char c, va_list lst)
{
	int	len;

	len = 0;
	if (c == '%')
		len = ft_putchar('%');
	else if (c == 'c')
		len = ft_putchar(va_arg(lst, int));
	else if (c == 's')
		len = ft_putstr(va_arg(lst, char *));
	else if (c == 'p')
		len = ft_putdir(va_arg(lst, void *));
	else if (c == 'd' || c == 'i')
		len = ft_print_di(va_arg(lst, int));
	else if (c == 'u')
		len = ft_print_u(va_arg(lst, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_print_xx(va_arg(lst, unsigned int), c);
	else if (c == '\0')
		return (-2);
	return (len);
}

static int	ft_end(int tmp, int length)
{
	if (tmp == -1)
		length = -1;
	else if (tmp > 0 && length != -1)
		length += tmp;
	return (length);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	int		length;
	int		tmp;

	if (!s)
		return (-1);
	length = 0;
	tmp = 0;
	va_start(lst, s);
	while (*s && tmp != -2)
	{
		if (*s == '%')
		{
			s++;
			tmp = ft_readstr(*s, lst);
		}
		else
			tmp = ft_putchar(*s);
		length = ft_end(tmp, length);
		s++;
	}
	va_end(lst);
	return (length);
}
