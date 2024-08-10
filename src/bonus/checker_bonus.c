/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:53:33 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/04 14:46:38 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv);
	get_commands(&a, &b);
	if (check_order(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (argc == 2)
		ft_free(argv);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
