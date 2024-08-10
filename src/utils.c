/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:55:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/18 18:57:54 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*bottom(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*top(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->prev)
		a = a->prev;
	return (a);
}

t_stack	*get_cheapest(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
		{
			node->cheapest = 0;
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

t_stack	*get_biggest(t_stack *a)
{
	t_stack	*biggest;
	int		max;

	if (!a)
		return (NULL);
	max = INT_MIN;
	while (a)
	{
		if (a->num >= max)
		{
			max = a->num;
			biggest = a;
		}
		a = a->next;
	}
	return (biggest);
}

t_stack	*get_smallest(t_stack *a)
{
	t_stack	*smallest;
	int		min;

	if (!a)
		return (NULL);
	min = INT_MAX;
	while (a)
	{
		if (a->num <= min)
		{
			min = a->num;
			smallest = a;
		}
		a = a->next;
	}
	return (smallest);
}
