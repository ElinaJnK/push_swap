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
		return (ft_putstr_fd("KO\n", 1), exit(EXIT_FAILURE));
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
		return (ft_putstr_fd("KO\n", 1), exit(EXIT_FAILURE));
}

void	rotate(t_stack *s)
{
	int		i;
	int		prev;
	int		tmp;

	if (s->curr_size == 1)
		return ;
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
		return (ft_putstr_fd("KO\n", 1), exit(EXIT_FAILURE));
}

void	reverse_rotate(t_stack *s)
{
	int		i;
	int		prev;
	int		tmp;

	if (s->curr_size == 1)
		return ;
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
		return (ft_putstr_fd("KO\n", 1), exit(EXIT_FAILURE));
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
}
