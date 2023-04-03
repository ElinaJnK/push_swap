#include "../include/push_swap.h"

void print_s(t_stack *a);

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_tab;

	a = check_params(av + 1, ac - 1);
	b = init_stack(a->size, 0);
	if (!a || !b)
		failure();
	sorted_tab = copy_tab(a);
	if (!sorted_tab)
		return (free_stack(a), free_stack(b), 0);
	quicksort(sorted_tab, 0, a->size - 1);
	check_dup(sorted_tab, a->size);
	update_stack(sorted_tab, a);
	if (a->size == 3)
		sort_3(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
	{
		presort(a, b);
		sort(a, b);
	}
	return (free(sorted_tab), free_stack(a), free_stack(b), 0);
}
