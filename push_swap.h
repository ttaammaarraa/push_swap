/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:53 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/14 17:47:57 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <limits.h>

typedef struct s_node
{
    int info;
    struct s_node *next;
}   t_node;


long long int	ft_atoi_push(const char *str);
void            error(void);
void            swap(t_node **a, char *str);
void            rotate(t_node **a, char *str);
void            reverse_rotate(t_node **a, char *str);
void            push(t_node **a, t_node **b, char *str);
void            init_stack(int argc, char **argv, t_node **a);
void            add_node_front(t_node **a, t_node *node_to_add);
void            check_range(char **str);
void            check_double(char **str);
void            checks(char **str);
void            add_node_back(t_node **a, int info);
void	        sort_three(t_node **stack_a);
int             is_sorted(t_node *stack_a);

#endif