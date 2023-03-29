#include "../include/push_swap.h"

/*
	Calcul de coups
	- Ecrire une fonction qui prend un element dans b et qui trouve le parent dans a
	- Faire une fonction qui donne une liste d'index de prix [0, 1, 2, 3, -2, -1]
	- Une boucle qui trouve l'element le moins cher a rotate
	- Une fonction qui fait les movements (rotation) de l'element donne
*/

// check if elem is not already in a (might make it an int function later on)
void	check_valid_elem(t_stack *a, int elem)
{
	int	i;

	i = a->size - a->curr_size;
	while (i < a->size)
		if (a->tab[i++] == elem)
		{
			printf("Hello Karimo, if u are seeing this, it means that you are looking at an element in a that is already in a\n, we need to rectify this function lol love you\n");
			failure();
		}
}

// PAS FINIIII
// get the position of the papa in the stack
// we must send elem + 1 to get the position
// val(parent) = val(elem) + 1 || elem == stack->size -1 => return 0
int		get_papa_a(t_stack *a, int elem)
{
	int	i;
	int	j;

	i = a->size - a->curr_size;
	j = 0;
	//printf("arr:\n");
	//print_array(a->tab, a->size);
	check_valid_elem(a, elem);
	while (j < a->size)
	{
		while (i < a->size)
		{
			if (a->tab[i] == elem + 1)
				return (i);
			i++;
		}
		i = a->size - a->curr_size;
		++elem;
		elem = elem % (a->size);
		//printf("elem : %d\n", elem);
		++j;
	}
	return (-1);
}

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}
// steps : 
/*
- we get the position of the papa of the element in b
- we look at how much we need to get it to the top -> in res_a (cost_a)
- we look at how much we need to get b to the top
- remember : we do not count push_b
- we put the result in an or a min idk lol
- if res_a[] == res_b[] cost = res_[a] (since we're just getting to do rr and rrr)
- 0 is probably a special case
- take the absolute value of both numbers and add it and that will be your cost
- we count in ra and rb, rra, rrb for now (next we'll implement rrr and rr)*/
// returns the index of the least exepensive cost (index in b)
int	best_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	b_it;
	int	index;
	int	cost;
	int	min_cost;

	b_it = b->size - b->curr_size;
	min_cost = cost_b[b->tab[b_it]] + cost_a[a->tab[a->size - a->curr_size]];
	cost = 0;
	index = b_it;
	while (b_it < b->size)
	{
		// on check combien ca coute de le mettre en haut dans a, puis de le mettre en haut dans b
		if (cost_a[get_papa_a(a, b->tab[b_it])] == cost_b[b->tab[b_it]])
			cost = ft_abs(cost_a[get_papa_a(a, b->tab[b_it])]);
		else
			cost = ft_abs(cost_a[get_papa_a(a, b->tab[b_it])]) + ft_abs(cost_b[b->tab[b_it]]);
		if (cost < min_cost)
		{
			index = b_it;
			min_cost = cost;
		}
		++b_it;
	}
	return (index);
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

/* A function to rotate the stack so that we have everything in the right pos
- find the best cost
- rotate accordingly (be careful, if both of the elements are the same, it's rr or rrr)
- push to the stack a after rotating both the stacks according to the cost (might make additionnal function for that)
- keep going until the stack is sorted
- implement checker function */
/*void	push_to_a(t_stack *a, t_stack *b)
{

}*/

// on abandonne pas ici hrf3iuh
/*void	checker(t_stack *a, t_stack *b)
{

}*/

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
	int cost = best_cost(a, b, cost_a_rica, cost_b_aroc);
	printf("this is the best cost (?) : %d\n", cost);
}