#include "../include/push_swap.h"

int	swap(t_stack *s)
{
	int	temp;

	if (s->curr_size > 1)
	{
		temp = s->tab[s->size - s->curr_size];
		s->tab[s->size - s->curr_size] = s->tab[s->size - s->curr_size + 1];
		s->tab[s->size - s->curr_size + 1] = temp;
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	push(t_stack *a, t_stack *b)
{
	if (b->curr_size > 0)
	{
		a->tab[a->size - a->curr_size - 1] = b->tab[b->size - b->curr_size];
		b->tab[b->size - b->curr_size] = 0;
		b->curr_size -= 1;
		a->curr_size += 1;
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	rotate(t_stack *s)
{
	int		i;
	int		prev;
	int		tmp;

	if (s->curr_size == 1)
		return (EXIT_SUCCESS);
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
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	reverse_rotate(t_stack *s)
{
	int		i;
	int		prev;
	int		tmp;

	if (s->curr_size == 1)
		return (EXIT_SUCCESS);
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
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

void	do_move(t_stack *a, t_stack *b, char *move)
{
	int	i;

	i = EXIT_SUCCESS;
	i = do_first_half(a, b, move);
	if (ft_strncmp(move, "rb", ft_strlen(move)) == 0)
		i = rotate(b);
	else if (ft_strncmp(move, "rr", ft_strlen(move)) == 0)
		i = rr(a, b);
	else if (ft_strncmp(move, "rra", ft_strlen(move)) == 0)
		i = reverse_rotate(a);
	else if (ft_strncmp(move, "rrb", ft_strlen(move)) == 0)
		i = reverse_rotate(b);
	else if (ft_strncmp(move, "rrr", ft_strlen(move)) == 0)
		i = rrr(a, b);
	some_func(a, b, move, i);
}
