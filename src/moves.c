#include "../include/push_swap.h"

void	swap(t_stack *s)
{
	int	temp;

	if (s->curr_size > 1)
	{
		temp = s->tab[s->size - s->curr_size];
		s->tab[s->size - s->curr_size] = s->tab[s->size - s->curr_size + 1];
		s->tab[s->size - s->curr_size + 1] = temp;
	}
	else
		failure();
}

void	push(t_stack *a, t_stack *b)
{
	if (b->curr_size > 0)
	{
		a->tab[a->size - a->curr_size - 1] = b->tab[b->size - b->curr_size];
		b->tab[b->size - b->curr_size] = 0;
		b->curr_size -= 1;
		a->curr_size += 1;
	}
	else
		failure();
}

void	rotate(t_stack *s)
{
	int		i;
	int		prev;
	int		tmp;

	if (s->curr_size > 1)
	{
		i = s->size - 1;
		prev = s->tab[s->size - s->curr_size];
		while (i > s->size - s->curr_size - 1)
		{
			tmp = s->tab[i];
			s->tab[i] = prev;
			prev = tmp;
			--i;
		}
	}
	else
		failure();
}

void	reverse_rotate(t_stack *s)
{
	int		i;
	int		prev;
	int		tmp;

	if (s->curr_size > 1)
	{
		i = s->size - s->curr_size;
		prev = s->tab[s->size - 1];
		while (i < s->size)
		{
			tmp = s->tab[i];
			s->tab[i] = prev;
			prev = tmp;
			++i;
		}
	}
	else
		failure();
}

void print_array(int *arr1, int *arr2, int size) {
    for(int i = 0; i < size; i++) {
        printf("|  %d  |\t\t|  %d  |\n", arr1[i], arr2[i]);
    }
    printf("\n");
}

void print_stacks(t_stack *a, t_stack *b) {
	int i = a->size - 1, j = b->size - 1; 
	while (i >= a->size - a->curr_size || j >= b->size - b->curr_size)
   {
		if (j >= b->size - b->curr_size && i >= a->size - a->curr_size)
       		printf("|  %d  |\t|  %d  |\n", a->tab[i], b->tab[j]);
		else if (j >= b->size - b->curr_size)
			printf("|     |\t|  %d  |\n", b->tab[j]);
		else if (i >= a->size - a->curr_size)
			printf("|  %d  |\t|     |\n", a->tab[i]);
		--i;
		--j;
    }
    printf("\n");
}

void print_s(t_stack *a){
    for(int i = 0; i < a->size; i++) {
		if (i >= a->size - a->curr_size)
			printf("%d  ", a->tab[i]);
        else
			printf("0 ");
    }
    printf("\n");
}

void	do_move(t_stack *a, t_stack *b, char *move)
{
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	if (ft_strncmp(move, "sa", ft_strlen(move)) == 0)
		swap(a);
	else if (ft_strncmp(move, "sb", ft_strlen(move)) == 0)
		swap(b);
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
		ss(a, b);
	if (ft_strncmp(move, "pa", ft_strlen(move)) == 0)
		push(a, b);
	else if (ft_strncmp(move, "pb", ft_strlen(move)) == 0)
		push(b, a);
	else if (ft_strncmp(move, "ra", ft_strlen(move)) == 0)
		rotate(a);
	else if (ft_strncmp(move, "rb", ft_strlen(move)) == 0)
		rotate(b);
	else if (ft_strncmp(move, "rr", ft_strlen(move)) == 0)
		rr(a, b);
	else if (ft_strncmp(move, "rra", ft_strlen(move)) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(move, "rrb", ft_strlen(move)) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(move, "rrr", ft_strlen(move)) == 0)
		rrr(a, b);
	//print_s(a);
	//print_s(b);
}
