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
    //t_node *b;

    a = NULL;
    //b = NULL;
    if(argc == 1)
        return (1);
    checks(argv);
    init_stack(argc, argv, &a);
    print_list(a);
    return (0);
}