#include "../include/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	place_pivot(int *tab, int min, int max)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[max];
	i = min - 1;
	j = min;
	while (j < max)
	{
		if (tab[j] < pivot)
		{
			++i;
			ft_swap(&tab[i], &tab[j]);
		}
		++j;
	}
	ft_swap(&tab[i + 1], &tab[max]);
	return (i + 1);
}

void	quicksort(int *tab, int min, int max)
{
	int	part;

	if (min < max)
	{
		part = place_pivot(tab, min, max);
		quicksort(tab, min, part - 1);
		quicksort(tab, part + 1, max);
	}
}
