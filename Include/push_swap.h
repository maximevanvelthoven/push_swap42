/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:30:01 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 18:43:27 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*previous;
	struct s_node	*target_node;

	int				nb;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;

}					t_node;

// errors handlings
void				ft_quit(char *str);
void				ft_free(char **tab);

// initialisation de stack a + check valide
void				ft_init_stack(t_node **sta, char **av, int ac);
int					check_av(char **av);
long				ft_atol(const char *str);

// sort functions
void				sort_three(t_node **a);
void				sort_stack(t_node **a, t_node **b);

// initialisation des nodes stack a && b
void				init_node_a(t_node *a, t_node *b);
void				init_node_b(t_node *a, t_node *b);

// initialisation target + algo
void				current_index(t_node *stack);
void				prep_for_push(t_node **stack, t_node *top_node,
						char stack_name);

// utils stack check
t_node				*find_last(t_node *sta);
int					stacksize(t_node **stack);
int					sorted(t_node **stack);
t_node				*find_max(t_node *stack);
t_node				*get_cheapest(t_node *stack);
t_node				*find_min(t_node *stack);

// swap function
void				sa(t_node **head, int flag);
void				sb(t_node **head, int flag);
void				ss(t_node **stack_a, t_node **stack_b);

// push function
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

// rotate function
void				ra(t_node **a, int flag);
void				rb(t_node **b, int flag);
void				rr(t_node **a, t_node **b);
void				rotate_both(t_node **a, t_node **b, t_node *cheap_node);

// reverse rotate function
void				rra(t_node **a, int flag);
void				rrb(t_node **b, int flag);
void				rrr(t_node **a, t_node **b);
void				rev_rotate_both(t_node **a, t_node **b, t_node *cheap_node);

#endif