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
void    push(t_node **a, t_node **b, char *str);
void    init_stack(int argc, char **argv, t_node **a);
void            check_range(char **str);
void            check_double(char **str);
void            checks(char **str);
#endif