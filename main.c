/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:50 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/02/14 17:53:24 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_list(t_node *a)
{
    while(a)
    {
        printf("%i\n" , a->info);
        a = a->next;

    }
}

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

    a = NULL;
    b = malloc(sizeof(t_node));
    b->info = 3;
    b->next = NULL;
    if(argc == 1)
        return (1);
    checks(argv);
    init_stack(argc, argv, &a);
    if(is_sorted(a))
        return (0);
    if (argc == 3)
        swap(&a, "sa\n");
    else
        sort_three(&a);
    print_list(a);
    return (0);
}
