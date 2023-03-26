#include "../include/push_swap.h"

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int	main(int ac, char *av[])
{
	t_stack *stack_a;
	
	stack_a = check_params(av + 1, ac - 1);
	if (!stack_a)
		failure();
	quicksort(stack_a->tab, 0, stack_a->size - 1);
	print_array(stack_a->tab, stack_a->size);
	return (0);
}