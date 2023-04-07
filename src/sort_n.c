#include "../include/push_swap.h"

int	check_sorted(t_stack *a)
{
	int	i;
	int	j;

	j = 0;
	i = a->size - a->curr_size;
	while (i < a->size - 1)
	{
		if (a->tab[i] != j)
			return (EXIT_FAILURE);
		++i;
		++j;
	}
	return (EXIT_SUCCESS);
}

void	sort_3(t_stack *a, t_stack *b)
{
	int	top;
	int	mid;
	int	bot;

	top = a->tab[a->size - a->curr_size];
	mid = a->tab[a->size - a->curr_size + 1];
	bot = a->tab[a->size - a->curr_size + 2];
	if (top > mid && top < bot && mid < bot)
		do_move(a, b, "sa");
	else if (mid < top && mid > bot && top > bot)
	{
		do_move(a, b, "sa");
		do_move(a, b, "rra");
	}
	else if (bot > mid && bot < top && top > mid)
		do_move(a, b, "ra");
	else if (bot < mid && bot > top && top < bot)
	{
		do_move(a, b, "sa");
		do_move(a, b, "ra");
	}
	else
		do_move(a, b, "rra");
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	i1;
	int	i2;

	do_move(a, b, "pb");
	do_move(a, b, "pb");
	sort_3(a, b);
	i1 = get_papa_a(a, b->tab[b->size - b->curr_size]);
	if (i1 == a->size - a->curr_size + 1)
		do_move(a, b, "ra");
	else if (i1 == a->size - a->curr_size + 2)
		do_move(a, b, "rra");
	do_move(a, b, "pa");
	i2 = get_papa_a(a, b->tab[b->size - b->curr_size]);
	if (i2 == a->size - a->curr_size + 1)
		do_move(a, b, "ra");
	else if (i2 >= a->size - a->curr_size + 2)
	{
		do_move(a, b, "rra");
		if (i2 == a->size - a->curr_size + 2)
			do_move(a, b, "rra");
	}
	do_move(a, b, "pa");
	till_not_sorted(a, b);
}

void	sort_100(t_stack *a, t_stack *b)
{
	while (a->curr_size > 3)
		do_move(a, b, "pb");
	sort_3(a, b);
	sort(a, b);
}