/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:45:47 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/04 17:43:31 by adrmarqu         ###   ########.fr       */
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
	if (!check_order(a))
	{
		if (ft_lstsize(a) == 2)
			swap(&a, "sa");
		else
			sort(&a, &b);
	}
	if (argc == 2)
		ft_free(argv);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
