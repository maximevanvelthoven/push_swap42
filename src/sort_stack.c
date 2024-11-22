/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:23:06 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:37:58 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_node **a)
{
	while ((*a)->nb != find_min(*a)->nb)
	{
		if (find_min(*a)->above_median)
		{
			ra(a, 0);
		}
		else
		{
			rra(a, 0);
		}
	}
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheap_node;

	cheap_node = get_cheapest(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		rotate_both(a, b, cheap_node);
	else if (!(cheap_node->above_median)
		&& !(cheap_node->target_node->above_median))
		rev_rotate_both(a, b, cheap_node);
	prep_for_push(a, cheap_node, 'a');
	prep_for_push(b, cheap_node->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stacksize(a);
	if (len_a-- > 3 && !sorted(a))
		pb(a, b);
	if (len_a-- > 3 && !sorted(a))
		pb(a, b);
	while (len_a-- > 3 && !sorted(a))
	{
		init_node_a(*a, *b);
		move_a_to_b(a, b);
	}
	if (stacksize(a) == 3)
		sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
