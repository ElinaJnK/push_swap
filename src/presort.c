#include "../include/push_swap.h"

/* 
	On suppose que dans la stack on a un tableau de t_elem avec leurs valeurs (val)
	et positions voulues (pos) dans l'ordre trie descendent
*/

/*
	1. Prendre n medianes dans int *tab trie : Cb de medianes??
	2. Creer un tableau des medianes trie dans l'ordre decroissant
	2. Boucle ou on commencer a partir de la mediane la plus grande et push elements dans la Stack b
		- Si impaire, juste push elem dans b
		- Si stack->curr_size paire alors push elem dans b et faire un rr pour le mettre en bas
*/

//copy into stack the tab 
int	*copy_tab(t_stack *stack)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		failure();
	while (i < stack->size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	return (tab);
}

void    add_med(double *med, double size, int n)
{
	double step;

	if (n == 1)
		med[0] = size / 2;
	else
	{
		step = size / (n - 1);
		for (int i = 0; i < n - 1; i++)
			med[i] = step * i;
		//med[0] = step / 2;
		med[n - 1] = size - (step / 2);
	}
}

// return the index of the median
double	*create_medianes(int size, int n)
{
	double	*med;

	med = (double *)malloc(sizeof(double) * n);
	if (!med)
		failure();
	// get the n medianes
	add_med(med, (double)(size - 1), n);
	return med;
}

t_stack	*put_stack_b(t_stack *a, double *med, int n)
{
	t_stack	*b;
	int	i;
	int j;

	i = n - 1;
	b = init_stack(a->size, 0);
	// sup >= 0 so that we get the first index
	while (i >= 0)
	{
		// we modify the curr_size in the push fuction
		j = a->curr_size;
		while (j > 0 && a->curr_size > 3)
		{
			if (a->tab[a->size - a->curr_size] >= med[i])
			{
				do_move(a, b, "pb");
				if (b->curr_size % 2 == 0)
					do_move(a, b, "rr");
				j = a->curr_size;
			}
			else
				do_move(a, b, "ra");
			--j;
		}
		--i;
	}
	return (b);
}

t_stack	*presort(t_stack *stack)
{
	int		*sorted_tab;
	double		*med;
	int		n;
	t_stack	*b;

	if (!stack)
		failure();
	sorted_tab = copy_tab(stack);

	// get the sorted stack
	quicksort(sorted_tab, 0, stack->size - 1);
	check_dup(sorted_tab, stack->size);
	printf("Print : \n");
	print_array(sorted_tab, stack->size);


	// put positions in stack
	update_stack(sorted_tab, stack);
	printf("Print the sorted stack : \n");
	print_array(stack->tab, stack->size);

	// find the medianes, n is always odd the number of medianes
	n = 2;
	med = create_medianes(stack->size, n);
	printf("Print the array of medians : \n");
	print_array_double(med, stack->size);

	b = put_stack_b(stack, med, n);
	printf("Print the stack a after pushing everything to it : \n");
	print_array(stack->tab, stack->size);
	printf("Print the stack b after pushing everything to it : \n");
	free(med);
	free(sorted_tab);
	return (b);
}