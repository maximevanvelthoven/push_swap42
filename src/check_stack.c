/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:04:11 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:43:41 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stacksize(t_node **stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_node	*find_last(t_node *sta)
{
	t_node	*last_node;

	last_node = sta;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	int		max_nb;

	max_nb = INT_MIN;
	max_node = stack;
	while (stack)
	{
		if (stack->nb > max_nb)
		{
			max_nb = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*get_cheapest(t_node *stack)
{
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
