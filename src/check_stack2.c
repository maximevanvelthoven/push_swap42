/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:15:56 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:43:39 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	int		min_nb;

	min_nb = INT_MAX;
	min_node = stack;
	while (stack)
	{
		if (stack->nb < min_nb)
		{
			min_nb = stack->nb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
