/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:48:29 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/26 13:01:39 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order(t_stack **a)
{
	t_stack	*smallest;

	smallest = get_smallest(*a);
	while (smallest->prev)
	{
		if (smallest->above_m)
			rotate(a, "ra");
		else
			reverse(a, "rra");
	}
}

void	sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3)
		push(a, b, "pb");
	if (ft_lstsize(*a) > 3 && !check_order(*a))
		push(a, b, "pb");
	while (ft_lstsize(*a) > 3 && !check_order(*a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b_to_a(a, b);
	}
	update(*a);
	order(a);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = get_biggest(*a);
	if (biggest == *a)
		rotate(a, "ra");
	else if (biggest == (*a)->next)
		reverse(a, "rra");
	if ((*a)->num > (*a)->next->num)
		swap(a, "sa");
}
