#include "../include/push_swap.h"

int	check_order(int *t1, int *t2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (t1[i] != t2[i])
			return (ft_putstr_fd("KO\n", 1), EXIT_FAILURE);
		i++;
	}
	return (ft_putstr_fd("OK\n", 1), EXIT_SUCCESS);
}

int	find_move(t_stack *a, t_stack *b, char *move, int i)
{
	if (ft_strncmp(move, "sa\n", ft_strlen(move)) == 0)
		i = swap(a);
	else if (ft_strncmp(move, "sb\n", ft_strlen(move)) == 0)
		i = swap(b);
	else if (ft_strncmp(move, "ss\n", ft_strlen(move)) == 0)
		i = ss(a, b);
	else if (ft_strncmp(move, "pa\n", ft_strlen(move)) == 0)
		i = push(a, b);
	else if (ft_strncmp(move, "pb\n", ft_strlen(move)) == 0)
		i = push(b, a);
	else if (ft_strncmp(move, "ra\n", ft_strlen(move)) == 0)
		i = rotate(a);
	else if (ft_strncmp(move, "rb\n", ft_strlen(move)) == 0)
		i = rotate(b);
	else if (ft_strncmp(move, "rr\n", ft_strlen(move)) == 0)
		i = rr(a, b);
	else if (ft_strncmp(move, "rra\n", ft_strlen(move)) == 0)
		i = reverse_rotate(a);
	else if (ft_strncmp(move, "rrb\n", ft_strlen(move)) == 0)
		i = reverse_rotate(b);
	else if (ft_strncmp(move, "rrr\n", ft_strlen(move)) == 0)
		i = rrr(a, b);
	else
		failure_free(a, b, "Error\n");
	return (i);
}

void	get_move(t_stack *a, t_stack *b)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	while (line)
	{
		i = EXIT_FAILURE;
		i = find_move(a, b, line, i);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (i == EXIT_FAILURE)
		failure_free(a, b, "KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_tab;

	if (ac < 2)
		return (EXIT_SUCCESS);
	a = check_params(av + 1, ac - 1);
	sorted_tab = copy_tab(a);
	if (!sorted_tab)
		return (free_stack(a), EXIT_FAILURE);
	quicksort(sorted_tab, 0, a->size - 1);
	check_dup(sorted_tab, a->size);
	b = init_stack(a->size, 0);
	get_move(a, b);
	check_order(a->tab, sorted_tab, a->size);
	free(sorted_tab);
	free_stack(a);
	free_stack(b);
	return (0);
}
