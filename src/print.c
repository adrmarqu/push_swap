/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:39:12 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/21 15:40:05 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nodes(t_stack *a)
{
	if (!a)
		return ;
	while (a)
	{
		ft_printf("\n\nNODE: %p\nNEXT: %p\nPREV: %p\n", a, a->next, a->prev);
		a = a->next;
	}
	ft_printf("\n--------------------------------------------");
	ft_printf("--------------------------------------------\n");
}

void	print_stack(t_stack *a, t_stack *b, const char *message)
{
	ft_printf("--------------------------------------------");
	ft_printf("--------------------------------------------\n");
	ft_printf("%s\n", message);
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d", a->num);
			a = a->next;
		}
		if (b)
		{
			ft_printf("\t%d", b->num);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_\t_\na\tb\n");
	ft_printf("--------------------------------------------");
	ft_printf("--------------------------------------------\n");
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	*a = top(*a);
	current = *a;
	while (current)
	{
		tmp = current->next;
		current->num = 0;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
