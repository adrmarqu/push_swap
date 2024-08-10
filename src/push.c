/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:22:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/20 17:22:02 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, const char *message)
{
	t_stack	*push;

	if (!*a)
		return ;
	push = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	push->prev = NULL;
	if (*b)
	{
		push->next = *b;
		push->next->prev = push;
		*b = push;
	}
	else
	{
		*b = push;
		push->next = NULL;
	}
	if (message)
		ft_printf("%s\n", message);
}
