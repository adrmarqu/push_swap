/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:14:06 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:18:29 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update(t_stack *node)
{
	int	i;
	int	m;

	i = 0;
	if (!node)
		return ;
	m = ft_lstsize(top(node)) / 2;
	while (node)
	{
		node->pos = i;
		if (i <= m)
			node->above_m = 1;
		else
			node->above_m = 0;
		node = node->next;
		i++;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*node_b;
	t_stack	*target;
	long	best_cost;

	while (a)
	{
		best_cost = LONG_MIN;
		node_b = b;
		while (node_b)
		{
			if (node_b->num < a->num && node_b->num > best_cost)
			{
				best_cost = node_b->num;
				target = node_b;
			}
			node_b = node_b->next;
		}
		if (best_cost == LONG_MIN)
			a->target = get_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	init_a(t_stack *a, t_stack *b)
{
	update(a);
	update(b);
	set_target_a(a, b);
	cost(a, b);
	set_cheapest(a);
}

static void	add_data(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!a || !node)
		return ;
	node->next = NULL;
	node->num = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = bottom(*a);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack_a(t_stack **a, char *argv[])
{
	long long	nbr;
	int			i;

	i = 0;
	if (!argv || !argv[0])
		print_error();
	while (argv[i])
	{
		if (!check_num(argv[i]))
			print_error();
		if (ft_strlen(argv[i]) > 12)
			print_error();
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || check_dup(top(*a), (int)nbr))
			print_error();
		add_data(a, nbr);
		i++;
	}
}
