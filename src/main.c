#include "../include/push_swap.h"

void print_s(t_stack *a);

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = check_params(av + 1, ac - 1);
	b = presort(a);
	sort(a, b);
	//print_s(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
