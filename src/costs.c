#include "../include/push_swap.h"

/*
	Calcul de coups
	- Ecrire une fonction qui prend un element dans b et qui trouve le parent dans a
	- Faire une fonction qui donne une liste d'index de prix [0, 1, 2, 3, -2, -1]
	- Une boucle qui trouve l'element le moins cher a rotate
	- Une fonction qui fait les movements (rotation) de l'element donne
*/

// PAS FINIIII
// get the position of the papa in the stack
// we must send elem + 1 to get the position
int		get_papa_a(t_stack *a, int elem)
{
	int	i;

	i = a->size - a->curr_size;
	while (i < a->size)
	{
		if (a->tab[i] == elem)
			return (i);
		i++;
	}
	return (-1);
}

// get the cost of the stack in res
// need to allocate res beforehand (it's the size lol (i think it will be easier than doing a res
// of size curr_size although less optimal))
// size / 2 will be the place of the highest cost
// before size / 2 we store from 0 to size / 2
// after we store - (size / 2) + i
void	cost(t_stack *s, int *res)
{
	int	i;
	int	j;

	if (!res)
		failure();
	i = s->size - s->curr_size;
	j = 0;
	while (i < s->curr_size / 2)
		res[i++] = j++;
	j = 1;
	while (i < s->size)
		res[i++] = (s->curr_size / 2) + j++;
}

void	sort(t_stack *a, t_stack *b)
{
	cost(b);
}