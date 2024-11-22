/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:27:59 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:43:23 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*push_node;

	if (!*b)
		return ;
	push_node = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;
	push_node->previous = NULL;
	if (!*a)
	{
		*a = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *a;
		push_node->next->previous = push_node;
		*a = push_node;
	}
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	t_node	*push_node;

	if (!*a)
		return ;
	push_node = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	push_node->previous = NULL;
	if (!*b)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->previous = push_node;
		*b = push_node;
	}
	ft_printf("pb\n");
}
