/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:32:50 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:43:43 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_node **stack)
{
	int		cheapest_value;
	t_node	*cheapest_node;

	cheapest_value = INT_MAX;
	while (*stack)
	{
		if ((*stack)->push_cost < cheapest_value)
		{
			cheapest_value = (*stack)->push_cost;
			cheapest_node = (*stack);
		}
		(*stack) = (*stack)->next;
	}
	cheapest_node->cheapest = 1;
}

void	cost_analysis(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stacksize(&a);
	len_b = stacksize(&b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nb < a->nb && current_b->nb > best_match_index)
			{
				best_match_index = current_b->nb;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stacksize(&stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	init_node_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(&a);
}
