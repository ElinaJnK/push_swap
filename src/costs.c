#include "../include/push_swap.h"

int	find_tot_cost(int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		return (ft_max(cost_a, cost_b));
	else if (cost_a < 0 && cost_b < 0)
		return (-ft_min(cost_a, cost_b));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

int	best_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	b_it;
	int	index;
	int	cost;
	int	min_cost;

	b_it = b->size - b->curr_size;
	min_cost = ft_abs(cost_a[get_papa_a(a, b->tab[b_it])]);
	cost = 0;
	index = b_it;
	while (b_it < b->size)
	{
		cost = ft_abs(find_tot_cost(cost_a[get_papa_a(a, b->tab[b_it])],
					cost_b[b_it]));
		if (cost < min_cost)
		{
			index = b_it;
			min_cost = cost;
		}
		++b_it;
	}
	return (index);
}

void	cost_push(t_stack *s, int *res)
{
	int	start;
	int	end;
	int	j;

	start = s->size - s->curr_size;
	j = 0;
	end = s->size - s->curr_size + s->curr_size / 2;
	while (start < end)
	{
		res[start++] = j++;
		res[s->size - j] = -j;
	}
	if (s->curr_size % 2 != 0)
		res[start] = j;
	j = 0;
	while (j < s->size - s->curr_size)
		res[j++] = -1;
}

void	put_to_a(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	pos;
	int	ca;
	int	cb;

	pos = best_cost(a, b, cost_a, cost_b);
	ca = cost_a[get_papa_a(a, b->tab[pos])];
	cb = cost_b[pos];
	do_while_both(a, b, &ca, &cb);
	do_while_a(a, b, &ca);
	do_while_b(a, b, &cb);
	do_move(a, b, "pa");
}

void	sort(t_stack *a, t_stack *b)
{
	int	*cost_a_rica;
	int	*cost_b_aroc;

	cost_a_rica = (int *)malloc(sizeof(int) * a->size);
	cost_b_aroc = (int *)malloc(sizeof(int) * b->size);
	while (b->curr_size > 0)
	{
		if (!cost_a_rica || !cost_b_aroc)
			failure();
		cost_push(a, cost_a_rica);
		cost_push(b, cost_b_aroc);
		put_to_a(a, b, cost_a_rica, cost_b_aroc);
	}
	till_not_sorted(a, b);
	free(cost_a_rica);
	free(cost_b_aroc);
}
