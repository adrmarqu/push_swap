/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:01:11 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/20 17:20:40 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_stack **stack, t_stack *top, int c)
{
	while (*stack != top)
	{
		if (!c)
		{
			if (top->above_m)
				rotate(stack, "ra");
			else
				reverse(stack, "rra");
		}
		else
		{
			if (top->above_m)
				rotate(stack, "rb");
			else
				reverse(stack, "rrb");
		}
	}
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap && *b != cheap->target)
	{
		rotate(a, "rr");
		rotate(b, NULL);
	}
	update(*a);
	update(*b);
}

static void	reverse_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap && *b != cheap->target)
	{
		reverse(a, "rrr");
		reverse(b, NULL);
	}
	update(*a);
	update(*b);
}

static t_stack	*get_cheap(t_stack *node)
{
	while (node)
	{
		if (node->cheapest == 1)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cn;

	cn = get_cheap(*a);
	if (cn->above_m && cn->target->above_m)
		rotate_both(a, b, cn);
	else if (!cn->above_m && !cn->target->above_m)
		reverse_both(a, b, cn);
	move_top(a, cn, 0);
	move_top(b, cn->target, 1);
	push(a, b, "pb");
}
