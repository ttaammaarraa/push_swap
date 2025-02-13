#include "push_swap.h"
void    swap(t_node **a, char *str)
{
    t_node *A;
    t_node *B;
    
    A = *a;
    B = (*a)->next;
    A->next = B->next;
    B->next = A;
    *a = B;
    ft_putstr_fd(str, 1);
}

void    rotate(t_node **a, char *str)
{
    t_node  *A;
    t_node  *B;

    B = *a;
    A = *a;
    while (B->next)
    {
        B = B->next;
    }
    *a = A->next;
    B->next = A;
    A->next = NULL;
    ft_putstr_fd(str, 1);
}

void    reverse_rotate(t_node **a, char *str)
{
    t_node  *B;
    t_node  *C;

    B = *a;
    C = *a;

    while(B->next)
    {
        B = B->next;
    }
    while(C->next != B)
        C = C->next;
    B->next = *a;
    C->next = NULL;
    *a = B;
    ft_putstr_fd(str, 1);
}

void    push(t_node **a, t_node **b, char *str)
{
    t_node *A;
    t_node *B;

    A = *a;
    B = *b;
    *a = A->next;
    A->next = B;
    *b = A;
    ft_putstr_fd(str, 1);
}
