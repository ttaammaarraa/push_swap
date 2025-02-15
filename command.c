/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:35 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/15 14:28:23 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **a, char *str)
{
	t_node	*aa;
	t_node	*bb;

	if (!a || !(*a) || !((*a)->next))
		return ;
	aa = *a;
	bb = (*a)->next;
	aa->next = bb->next;
	bb->next = aa;
	*a = bb;
	ft_putstr_fd(str, 1);
}

void	rotate(t_node **a, char *str)
{
	t_node	*aa;
	t_node	*bb;

	if (!a || !(*a) || !((*a)->next))
		return ;
	bb = *a;
	aa = *a;
	while (bb->next)
		bb = bb->next;
	*a = aa->next;
	bb->next = aa;
	aa->next = NULL;
	ft_putstr_fd(str, 1);
}

void	reverse_rotate(t_node **a, char *str)
{
	t_node	*bb;
	t_node	*c;

	if (!a || !(*a) || !((*a)->next))
		return ;
	bb = *a;
	c = *a;
	while (bb->next)
	{
		bb = bb->next;
	}
	while (c->next != bb)
		c = c->next;
	bb->next = *a;
	c->next = NULL;
	*a = bb;
	ft_putstr_fd(str, 1);
}

void	push(t_node **a, t_node **b, char *str)
{
	t_node	*aa;

	if (!a || !(*a))
		return ;
	aa = *a;
	*a = aa->next;
	aa->next = NULL;
	add_node_front(b, aa);
	ft_putstr_fd(str, 1);
}
