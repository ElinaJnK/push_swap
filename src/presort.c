#include "../include/push_swap.h"

//copy into stack the tab 
void	copy_tab(t_stack *stack, int *tab)
{
	int	i;

	i = 0;
	while (i < stack->size)
		stack->tab[i] = tab[i++];
}

// return the index of the median
int find_mediane(t_stack *stack) {
    int mid = stack->size / 2;
    if (stack->size % 2 == 0) {
		// chosen arbitrarily
        return mid - 1;
    } else {
        return mid;
    }
}

void	sort_and_mediane(t_stack *stack)
{
	t_stack	*sorted_stk;

	sorted_stk = init_stack(stack->size);
	copy_tab(sorted_stk, stack->tab);
	if (!stack)
		failure();
	// get the sorted stack
	quicksort(sorted_stk->tab, 0, stack->size - 1);
	// find the mediane index
	find_mediane(sorted_stk);
	// now this is where idk what to do :D
}