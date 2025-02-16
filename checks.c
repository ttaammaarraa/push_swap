/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:45 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/16 15:25:01 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_double(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				error();
			j++;
		}
		i++;
	}
}

long long int	ft_atoi_push(const char *str)
{
	int				sign;
	long long int	result;
	int				i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		error();
	return (sign * result);
}

void	check_range(char **str)
{
	int				i;
	long long int	num;

	i = 1;
	while (str[i])
	{
		num = ft_atoi_push(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			error();
		i++;
	}
}

void	checks(char **str)
{
	check_range(str);
	check_double(str);
}
