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
void	copy_tab(int *tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		tab[i] = stack->tab[i].val;
		i++;
	}
}

// return the index of the median
int	*create_medianes(int *tab, int n)
{
	int	*med;

	med = (int *)malloc(sizeof(int) * n);
	return med;
}

void	sort_and_mediane(t_stack *stack)
{
	int	*sorted_tab;

	sorted_tab = malloc(sizeof(int) * stack->size);
	copy_tab(sorted_tab, stack);
	if (!stack)
		failure();
	// get the sorted stack
	quicksort(sorted_tab, 0, stack->size - 1);
	// find the mediane index
	create_medianes(sorted_tab, stack->size);
	// update positions in stac
}