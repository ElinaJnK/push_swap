#include "../include/push_swap.h"


void	swap(t_stack *s)
{
	t_elem	temp;

	if (s->curr_size > 1)
	{
		temp = s->tab[s->size - s->curr_size];
		s->tab[s->size - s->curr_size] = s->tab[s->size - s->curr_size + 1];
		s->tab[s->size - s->curr_size + 1] = temp;
	}
	else
		printf("pb swap\n");
}

void	 push(t_stack *a, t_stack *b)
{
	if (b->curr_size > 0)
	{
		a->tab[a->size - a->curr_size - 1] = b->tab[b->size - b->curr_size];
		b->tab[b->size - b->curr_size].val = 0;
		b->tab[b->size - b->curr_size].pos = 0;
		b->curr_size -= 1;
		a->curr_size += 1;
	}
	else
		printf("pb push\n");
}

void	rotate(t_stack *s)
{
	int		i;
	t_elem	prev;
	t_elem	tmp;

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
		printf("pb rot\n");
}

void reverse_rotate(t_stack *s)
{
	int		i;
	t_elem	prev;
	t_elem	tmp;

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
		printf("pb revrot\n");
}

void	do_move(t_stack *a, t_stack *b, char *move)
{
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
}