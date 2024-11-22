/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:23:21 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/24 15:43:34 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_digit(char *str, int i)
{
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(int nb, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (nb == ft_atol(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_av(char **av)
{
	int		i;
	long	tmp_nb;

	i = 0;
	while (av[i])
	{
		tmp_nb = ft_atol(av[i]);
		if (!only_digit(av[i], 0))
			return (0);
		if (!check_duplicate(tmp_nb, av, i))
			return (0);
		if (tmp_nb > 2147483647 || tmp_nb < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
