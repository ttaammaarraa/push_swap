/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:50 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/16 15:22:34 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **stack_a)
{
	t_node	*aa;

	aa = *stack_a;
	while (*stack_a)
	{
		*stack_a = (*stack_a)->next;
		free(aa);
		aa = *stack_a;
	}
}

void	sort_num(int argc, t_node **a, t_node **b)
{
	if (argc == 3)
		swap(a, "sa\n");
	else if (argc == 4)
		sort_three(a);
	else if (argc == 5)
		sort_four(a, b);
	else if (argc == 6)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	checks(argv);
	init_stack(argc, argv, &a);
	if (is_sorted(a))
	{
		free_list(&a);
		return (0);
	}
	sort_num(argc, &a, &b);
	free_list(&a);
	return (0);
}
