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
		return (NULL);
	add_med(med, (double)(size - 1), n);
	return (med);
}

static t_stack	*put_stack_b(t_stack *a, t_stack *b, double *med, int n)
{
	int		i;
	int		j;

	i = n - 1;
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

t_stack	*presort(t_stack *a, t_stack *b)
{
	double	*med;
	int		n;

	n = 2;
	med = create_medianes(a->size, n);
	if (!med)
		return (failure_free(a, b, "Error\n"), NULL);
	put_stack_b(a, b, med, n);
	sort_3(a, b);
	free(med);
	return (b);
}
