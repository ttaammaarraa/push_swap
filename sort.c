#include"push_swap.h"

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
		rrotate(stack_a, "rra\n");
	}
	else if (a->info > b->info && b->info < c->info && a->info > c->info)
		rotate(stack_a, "ra\n");
	else if (a->info < b->info && b->info > c->info && a->info < c->info)
	{
		swap(stack_a, "sa\n");
		rotate(stack_a, "ra\n");
	}
	else if (a->info < b->info && b->info > c->info && a->info > c->info)
		rrotate(stack_a, "rra\n");
}

//void sort_five