#include "../include/push_swap.h"

void	choose_sort(t_stack	*a, t_stack	*b)
{
	if (a->size == 3)
		sort_3(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else if (a->size <= 100)
		sort_100(a, b);
	else
	{
		presort(a, b);
		sort(a, b);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_tab;

	if (ac < 2)
		return (EXIT_SUCCESS);
	a = check_params(av + 1, ac - 1);
	b = init_stack(a->size, 0);
	sorted_tab = copy_tab(a);
	if (!a || !b || !sorted_tab)
		return (free_stack(a), free_stack(b), EXIT_FAILURE);
	quicksort(sorted_tab, 0, a->size - 1);
	check_dup(sorted_tab, a->size);
	update_stack(sorted_tab, a);
	if (check_sorted(a) == EXIT_SUCCESS)
		return (free(sorted_tab), free_stack(a), free_stack(b), EXIT_SUCCESS);
	choose_sort(a, b);
	return (free(sorted_tab), free_stack(a), free_stack(b), EXIT_SUCCESS);
}
