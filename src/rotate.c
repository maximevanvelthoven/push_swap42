/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:38:54 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:46:33 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, int flag)
{
	t_node	*last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = find_last(*a);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
	if (!flag)
		ft_printf("ra\n");
}

void	rb(t_node **b, int flag)
{
	t_node	*last_node;

	if (!*b || !(*b)->next)
		return ;
	last_node = find_last(*b);
	last_node->next = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
	if (!flag)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
}

void	rotate_both(t_node **a, t_node **b, t_node *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}
