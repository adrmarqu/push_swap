/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:55:56 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/04 14:46:16 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_command2(t_stack **a, t_stack **b, const char *cmd)
{
	if (ft_strcmp(cmd, "ra\n") == 0)
		rotate(a, NULL);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rotate(b, NULL);
	else if (ft_strcmp(cmd, "rr\n") == 0)
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (ft_strcmp(cmd, "rra\n") == 0)
		reverse(a, NULL);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		reverse(b, NULL);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
	{
		reverse(a, NULL);
		reverse(b, NULL);
	}
	else
		print_error();
}

static void	make_command(t_stack **a, t_stack **b, const char *cmd)
{
	if (ft_strcmp(cmd, "pa\n") == 0)
		push(b, a, NULL);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		push(a, b, NULL);
	else if (ft_strcmp(cmd, "sa\n") == 0)
		swap(a, NULL);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		swap(b, NULL);
	else if (ft_strcmp(cmd, "ss\n") == 0)
	{
		swap(a, NULL);
		swap(b, NULL);
	}
	else
		make_command2(a, b, cmd);
}

void	get_commands(t_stack **a, t_stack **b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			return ;
		make_command(a, b, cmd);
		free(cmd);
	}
}
