/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:28:03 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/20 15:15:10 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack *stack)
{
	long	cv;
	t_stack	*cn;

	if (!stack)
		return ;
	cv = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cv)
		{
			cv = stack->cost;
			cn = stack;
		}
		stack = stack->next;
	}
	cn->cheapest = 1;
}

void	cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(top(a));
	len_b = ft_lstsize(top(b));
	while (a)
	{
		a->cost = a->pos;
		if (!a->above_m)
			a->cost = len_a - a->pos;
		if (a->target->above_m)
			a->cost += a->target->pos;
		else
			a->cost += len_b - a->target->pos;
		a = a->next;
	}
}
