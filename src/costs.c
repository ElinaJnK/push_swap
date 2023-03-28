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
// val(parent) = val(elem) + 1 || elem == stack->size -1 => return 0
int		get_papa_a(t_stack *a, int elem)
{
	int	i;

	i = a->size - a->curr_size;
	if (elem == a->size - 1)
		return (0);
	while (i < a->size)
	{
		if (a->tab[i] == elem + 1)
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

void	cost_push(t_stack *s, int *res)
{
	int	start;
	int end;
	int	j;

	start = s->size - s->curr_size;
	j = 0;
	end = s->size - s->curr_size + s->curr_size / 2;
	while (start < end)
	{
		res[start++] = j++;
		res[s->size - j] = -j;
	}
	if (s->curr_size % 2 != 0)
		res[start] = j;
}

void	sort(t_stack *a, t_stack *b)
{
	int	*cost_a_rica;
	int	*cost_b_aroc;

	cost_a_rica = (int *)malloc(sizeof(int) * a->size);
	cost_b_aroc = (int *)malloc(sizeof(int) * b->size);
	if (!cost_a_rica || !cost_b_aroc)
		failure();
	cost_push(a, cost_a_rica);
	cost_push(b, cost_b_aroc);
	printf("cost a: \n");
	print_array(cost_a_rica, a->size);
	printf("cost b: \n");
	print_array(cost_b_aroc, b->size);
}