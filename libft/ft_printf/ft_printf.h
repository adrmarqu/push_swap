/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:32:17 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/13 19:36:28 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX "0123456789ABCDEF"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int			ft_printf(char const *s, ...);
int			ft_print_xx(unsigned int n, char c);
int			ft_print_u(unsigned int n);
int			ft_print_di(int n);
int			ft_putdir(void *p);
int			ft_putstr(const char *s);
int			ft_putchar(char c);
int			ft_putnbr(unsigned long long nbr, unsigned long long base,
				char type);

#endif
