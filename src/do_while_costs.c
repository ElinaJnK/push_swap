#include "../include/push_swap.h"

void	do_while_both(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		do_move(a, b, "rr");
		*ca -= 1;
		*cb -= 1;
	}
	while (*ca < 0 && *cb < 0)
	{
		do_move(a, b, "rrr");
		*ca += 1;
		*cb += 1;
	}
}

void	do_while_a(t_stack *a, t_stack *b, int *ca)
{
	while (*ca > 0)
	{
		do_move(a, b, "ra");
		*ca -= 1;
	}
	while (*ca < 0)
	{
		do_move(a, b, "rra");
		*ca += 1;
	}
}

void	do_while_b(t_stack *a, t_stack *b, int *cb)
{
	while (*cb > 0)
	{
		do_move(a, b, "rb");
		*cb -= 1;
	}
	while (*cb < 0)
	{
		do_move(a, b, "rrb");
		*cb += 1;
	}
}
