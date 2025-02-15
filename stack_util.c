/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:28:00 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/15 14:21:10 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_node **a, int info)
{
	t_node	*new;
	t_node	*temp;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		free_list(a);
		error();
	}
	new->next = NULL;
	new->info = info;
	new->index = 0;
	temp = *a;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*a = new;
}

void	add_node_front(t_node **a, t_node *node_to_add)
{
	t_node	*aa;

	if (!node_to_add)
		return ;
	aa = *a;
	node_to_add->next = aa;
	*a = node_to_add;
}

void	init_stack(int argc, char **argv, t_node **a)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		add_node_back(a, ft_atoi_push(argv[i + 1]));
		i++;
	}
}
