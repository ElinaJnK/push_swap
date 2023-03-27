#include "../include/push_swap.h"

/*
	Calcul de coups
	- Ecrire une fonction qui prend un element dans b et qui trouve le parent dans a
	- Faire une fonction qui donne une liste d'index de prix [0, 1, 2, 3, -2, -1]
	- Une boucle qui trouve l'element le moins cher a rotate
	- Une fonction qui fait les movements (rotation) de l'element donne
*/

// PAS FINIIII
int		get_parent_a(t_stack *a, int elem)
{
	int	i;

	i = 0;
	while (i < a->curr_size)
	{
		if (a->tab[i] == elem)
			return (i);
		i++;
	}
	return (-1);
}

void	sort(t_stack *a, t_stack *b)
{

	cost(b);
}