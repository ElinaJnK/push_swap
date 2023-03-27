#include "../include/push_swap.h"

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack	*b;

	a = check_params(av + 1, ac - 1);
	print_array(a->tab, a->size);
	b = presort(a);
	print_array(b->tab, b->size);
	//sort(a, b);
	return (0);
}

/*
int	main(int ac, char *av[])
{
	t_stack *stack_a;
	t_stack	*stack_b;
	
	stack_a = check_params(av + 1, ac - 1);
	if (!stack_a)
		failure();
	stack_b = init_stack(stack_a->size, 0);
	//quicksort(stack_a->tab, 0, stack_a->size - 1);
	printf("stack a:");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);
	do_move(stack_a, stack_b, "sa");
	printf("move : %s,\nstack a:", "sa");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "sb");
	printf("move : %s,\nstack a:", "sb");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "pa");
	printf("move : %s,\nstack a:", "pa");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "pb");
	printf("move : %s,\nstack a:", "pb");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "pb");
	printf("move : %s,\nstack a:", "pb");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "rb");
	printf("move : %s,\nstack a:", "rb");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "rr");
	printf("move : %s,\nstack a:", "rr");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "rra");
	printf("move : %s,\nstack a:", "rra");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "rrb");
	printf("move : %s,\nstack a:", "rrb");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);

	do_move(stack_a, stack_b, "rrr");
	printf("move : %s,\nstack a:", "rrr");
	print_array(stack_a->tab, stack_a->size);
	printf("stack b:");
	print_array(stack_b->tab, stack_b->size);
	return (0);
}
*/