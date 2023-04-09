#include "../include/push_swap.h"

int	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) == EXIT_FAILURE || rotate(b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	rrr(t_stack *a, t_stack *b)
{
	if (reverse_rotate(a) == EXIT_FAILURE || reverse_rotate(b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ss(t_stack *a, t_stack *b)
{
	if (swap(a) == EXIT_FAILURE || swap(b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	some_func(t_stack *a, t_stack *b, char *move, int i)
{
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	if (i == EXIT_FAILURE)
		failure_free(a, b, "Error\n");
}

int	do_first_half(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "sa", ft_strlen(move)) == 0)
		return (swap(a));
	else if (ft_strncmp(move, "sb", ft_strlen(move)) == 0)
		return (swap(b));
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
		return (ss(a, b));
	else if (ft_strncmp(move, "pa", ft_strlen(move)) == 0)
		return (push(a, b));
	else if (ft_strncmp(move, "pb", ft_strlen(move)) == 0)
		return (push(b, a));
	else if (ft_strncmp(move, "ra", ft_strlen(move)) == 0)
		return (rotate(a));
	return (EXIT_SUCCESS);
}
