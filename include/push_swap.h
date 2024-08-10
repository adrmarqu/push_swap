/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:40:53 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/16 13:32:54 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/ft_printf/ft_printf.h"

void		swap(t_stack **a, const char *message);
t_stack		*bottom(t_stack *a);
t_stack		*top(t_stack *a);
void		print_nodes(t_stack *a);
void		init_stack_a(t_stack **a, char *argv[]);
void		print_stack(t_stack *a, t_stack *b, const char *message);
void		sort_three(t_stack **a);
t_stack		*get_biggest(t_stack *a);
t_stack		*get_smallest(t_stack *a);
void		rotate(t_stack **a, const char *message);
void		reverse(t_stack **a, const char *message);
void		sort(t_stack **a, t_stack **b);
void		push(t_stack **a, t_stack **b, const char *message);
int			check_order(t_stack *a);
int			check_num(char *s);
int			check_dup(t_stack *a, int n);
void		print_error(void);
void		free_stack(t_stack **a);
void		get_target(t_stack **a, t_stack **b, int mode);
void		cost(t_stack *a, t_stack *b);
void		update(t_stack *a);
void		init_a(t_stack *a, t_stack *b);
void		init_b(t_stack *a, t_stack *b);
void		move_a_to_b(t_stack **a, t_stack **b);
void		move_b_to_a(t_stack **a, t_stack **b);
void		move_top(t_stack **stack, t_stack *top, int c);
void		mira(t_stack *a, t_stack *b);
void		set_cheapest(t_stack *node);

void		get_commands(t_stack **a, t_stack **b);

#endif
