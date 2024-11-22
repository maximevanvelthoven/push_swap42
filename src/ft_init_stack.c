/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:24:37 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/25 16:01:08 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_node **sta, int nb)
{
	t_node	*node;
	t_node	*last_node;

	last_node = NULL;
	if (!sta)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = nb;
	if (!(*sta))
	{
		*sta = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last(*sta);
		last_node->next = node;
		node->previous = last_node;
	}
}

long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	final;

	i = 0;
	final = 0;
	result = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			result *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (final > INT_MAX || final < INT_MIN)
			return (LONG_MAX);
		final = final * 10 + (str[i] - 48);
		i++;
	}
	return (final * result);
}

void	split_to_stack(t_node **sta, char *str, int i, int j)
{
	char	**tmp;

	tmp = ft_split(str, 32);
	free(str);
	while (tmp[j])
		j++;
	if (j == 0)
	{
		ft_free(tmp);
		ft_quit("Error\n");
	}
	if (!check_av(tmp))
	{
		ft_free(tmp);
		ft_quit("Error\n");
	}
	while (i < j)
	{
		add_to_stack(sta, ft_atol(tmp[i]));
		i++;
	}
	ft_free(tmp);
}

void	ft_init_stack(t_node **sta, char **av, int ac)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = ft_strdup("");
	if (ac < 2)
		ft_quit("Error\n");
	while (av[i])
	{
		av[i] = ft_strdup(av[i]);
		tmp = ft_strjoin(av[i], " ");
		str = ft_strjoin(str, tmp);
		free(tmp);
		i++;
	}
	split_to_stack(sta, str, 0, 0);
}
