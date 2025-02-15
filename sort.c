/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:57 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/15 14:15:12 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->info > stack_a->next->info)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_three(t_node **stack_a)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *stack_a;
	b = a->next;
	c = b->next;
	if (a->info > b->info && b->info < c->info && a->info < c->info)
		swap(stack_a, "sa\n");
	else if (a->info > b->info && b->info > c->info && a->info > c->info)
	{
		swap(stack_a, "sa\n");
		reverse_rotate(stack_a, "rra\n");
	}
	else if (a->info > b->info && b->info < c->info && a->info > c->info)
		rotate(stack_a, "ra\n");
	else if (a->info < b->info && b->info > c->info && a->info < c->info)
	{
		swap(stack_a, "sa\n");
		rotate(stack_a, "ra\n");
	}
	else if (a->info < b->info && b->info > c->info && a->info > c->info)
		reverse_rotate(stack_a, "rra\n");
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

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	sort_util(stack_a);
	push(stack_a, stack_b, "pb\n");
	sort_three(stack_a);
	push(stack_b, stack_a, "pa\n");
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	sort_util(stack_a);
	push(stack_a, stack_b, "pb\n");
	sort_util(stack_a);
	push(stack_a, stack_b, "pb\n");
	sort_three(stack_a);
	push(stack_b, stack_a, "pa\n");
	push(stack_b, stack_a, "pa\n");
}
