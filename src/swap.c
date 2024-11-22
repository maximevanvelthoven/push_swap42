/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:02:37 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 16:45:22 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head, int flag)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	if (!flag)
		ft_printf("sa\n");
}

void	sb(t_node **head, int flag)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	if (!flag)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_printf("ss\n");
}
