#include "../include/push_swap.h"

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	check_valid_elem(t_stack *a, int elem)
{
	int	i;

	i = a->size - a->curr_size;
	while (i < a->size)
		if (a->tab[i++] == elem)
			failure();
}

int	get_papa_a(t_stack *a, int elem)
{
	int	i;
	int	j;

	i = a->size - a->curr_size;
	j = 0;
	check_valid_elem(a, elem);
	while (j < a->size)
	{
		while (i < a->size)
		{
			if (a->tab[i] == 0 && elem == a->size - 1)
				return (i);
			if (a->tab[i] == elem + 1)
				return (i);
			i++;
		}
		i = a->size - a->curr_size;
		++elem;
		elem = elem % (a->size);
		++j;
	}
	return (-1);
}
