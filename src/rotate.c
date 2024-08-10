/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:27:20 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/03/18 17:36:43 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a, const char *message)
{
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = bottom(*a);
	last->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	if (message)
		ft_printf("%s\n", message);
}
