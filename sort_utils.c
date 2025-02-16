/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:14:19 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/16 15:45:00 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	listsize(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_least_number(t_node *stack_to_search)
{
	int	value;

	value = stack_to_search->info;
	while (stack_to_search)
	{
		if (value > stack_to_search->info)
			value = stack_to_search->info;
		stack_to_search = stack_to_search->next;
	}
	return (value);
}

int	pos_least_number(t_node *stack_a, int value)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->info == value)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	sort_util(t_node **stack_a)
{
	int	pos;
	int	value;
	int	size;

	size = listsize(*stack_a);
	value = find_least_number(*stack_a);
	pos = pos_least_number(*stack_a, value);
	if (pos <= size / 2)
	{
		while ((*stack_a)->info != value)
			rotate(stack_a, "ra\n");
	}
	else
	{
		while ((*stack_a)->info != value)
			reverse_rotate(stack_a, "rra\n");
	}
}
