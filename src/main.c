#include "../include/push_swap.h"

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_array_double(double *arr, int size){
    for(int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
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
	sort(a, b);
	return (0);
}