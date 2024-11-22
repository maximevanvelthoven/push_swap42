/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:08:39 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 16:49:55 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, int flag)
{
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	last = find_last(*a);
	last->previous->next = NULL;
	last->next = *a;
	last->previous = NULL;
	*a = last;
	last->next->previous = last;
	if (!flag)
		ft_printf("rra\n");
}

void	rrb(t_node **b, int flag)
{
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	last = find_last(*b);
	last->previous->next = NULL;
	last->next = *b;
	last->previous = NULL;
	*b = last;
	last->next->previous = last;
	if (!flag)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 1);
	rrb(b, 1);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
	{
		rrr(a, b);
	}
	current_index(*a);
	current_index(*b);
}
