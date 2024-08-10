/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:01:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/20 17:20:25 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_stack **a, t_stack **b)
{
	move_top(a, (*b)->target, 0);
	push(b, a, "pa");
}

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*node_a;
	t_stack	*target;
	long	best_cost;

	while (b)
	{
		best_cost = LONG_MAX;
		node_a = a;
		while (node_a)
		{
			if (node_a->num > b->num && node_a->num < best_cost)
			{
				best_cost = node_a->num;
				target = node_a;
			}
			node_a = node_a->next;
		}
		if (best_cost == LONG_MAX)
			b->target = get_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	update(a);
	update(b);
	set_target_b(a, b);
}
