#include "../include/push_swap.h"

int	*copy_tab(t_stack *stack)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		return (NULL);
	while (i < stack->size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	return (tab);
}

void	add_med(double *med, double size, int n)
{
	double	step;
	int		i;

	i = 0;
	if (n == 1)
		med[0] = size / 2;
	else
	{
		step = size / (n - 1);
		while (i < n - 1)
		{
			med[i] = step * i;
			++i;
		}
		med[n - 1] = size - (step / 2);
	}
}

double	*create_medianes(int size, int n)
{
	double	*med;

	med = (double *)malloc(sizeof(double) * n);
	if (!med)
		failure();
	add_med(med, (double)(size - 1), n);
	return (med);
}

t_stack	*put_stack_b(t_stack *a, double *med, int n)
{
	t_stack	*b;
	int		i;
	int		j;

	i = n - 1;
	b = init_stack(a->size, 0);
	while (i >= 0)
	{
		j = a->size;
		while (j > 0 && a->curr_size > 3)
		{
			if (a->tab[a->size - a->curr_size] >= med[i])
			{
				do_move(a, b, "pb");
				if (b->curr_size % 2 == 0)
					do_move(a, b, "rb");
			}
			else
				do_move(a, b, "ra");
			--j;
		}
		--i;
	}
	return (b);
}

void	sort_3(t_stack *a, t_stack *b)
{
	// 0 1
	if (a->tab[a->size - a->curr_size] > a->tab[a->size - a->curr_size + 1])
		do_move(a, b, "sa");
	// 0 2
	if (a->tab[a->size - a->curr_size] > a->tab[a->size - a->curr_size + 2])
	{
		do_move(a, b, "ra");
		if (a->tab[a->size - a->curr_size] > a->tab[a->size - a->curr_size + 1])
			do_move(a, b, "sa");
	}
	// 1 2
	if (a->tab[a->size - a->curr_size + 1] > a->tab[a->size - a->curr_size + 2])
	{
		do_move(a, b, "rra");
		if (a->tab[a->size - a->curr_size] > a->tab[a->size - a->curr_size + 1])
			do_move(a, b, "sa");
	}
}

t_stack	*presort(t_stack *stack)
{
	int		*sorted_tab;
	double	*med;
	int		n;
	t_stack	*b;

	if (!stack)
		failure();
	sorted_tab = copy_tab(stack);
	if (!sorted_tab)
		return (free_stack(stack), NULL);
	quicksort(sorted_tab, 0, stack->size - 1);
	check_dup(sorted_tab, stack->size);
	update_stack(sorted_tab, stack);
	n = 2;
	med = create_medianes(stack->size, n);
	b = put_stack_b(stack, med, n);
	sort_3(stack, b);
	free(med);
	free(sorted_tab);
	return (b);
}
