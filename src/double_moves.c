#include "../include/push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
