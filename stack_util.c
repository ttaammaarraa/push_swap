#include "push_swap.h"

void    add_node(t_node **a, int info)
{
    t_node *new;
    t_node *temp;

    new = malloc(sizeof(t_node));
    if(!new)
        //free()
    new->next = NULL;
    new->info = info;
    temp = *a;
    if(temp)
    {
    while(temp->next)
        temp = temp->next;
    temp->next = new;
    }
    else
        *a = new;
}

void    init_stack(int argc, char **argv, t_node **a)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        add_node(a, ft_atoi_push(argv[i + 1]));
        i ++;
    }
}
