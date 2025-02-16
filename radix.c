/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:12:42 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/16 15:24:44 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_node **stack_a)
{
	t_node	*aa;
	t_node	*bb;
	int		value;

	value = (*stack_a)->info;
	aa = (*stack_a);
	while (aa)
	{
		bb = *stack_a;
		value = aa->info;
		while (bb)
		{
			if (bb->info < value)
				aa->index++;
			bb = bb->next;
		}
		aa = aa->next;
	}
}

int	max_number(t_node *stack_a)
{
	int	value_of_index;

	value_of_index = 0;
	while (stack_a)
	{
		if (stack_a->index > value_of_index)
			value_of_index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (value_of_index);
}

int	max_bit(t_node *stack_a)
{
	int	max_num;
	int	maxx_bit;

	max_num = max_number(stack_a);
	maxx_bit = 0;
	while ((max_num >> maxx_bit) != 0)
		maxx_bit++;
	return (maxx_bit);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	maxx_bit;
	int	i;
	int	j;
	int	size;
	int	stack;

	size = listsize(*stack_a);
	indexing(stack_a);
	maxx_bit = max_bit(*stack_a);
	i = 0;
	while (i < maxx_bit)
	{
		j = 0;
		while (j++ < size)
		{
			stack = (*stack_a)->index;
			if (((stack >> i) & 1) == 1)
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
		}
		while (*stack_b)
			push(stack_b, stack_a, "pa\n");
		i++;
	}
}
