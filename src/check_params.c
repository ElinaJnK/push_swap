#include "../include/push_swap.h"
#include "push_swap.h"

void	failure(void)
{
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

void	failure_free(t_stack *a, t_stack *b, const char *str)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	check_dup(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
			return (free(tab), failure());
		i++;
	}
}

void	check_digit(char *num, int *n, t_stack	*stack)
{
	size_t			i;
	long long int	temp;
	int				sign;

	i = 0;
	sign = 1;
	temp = 0;
	if (num[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (num[i] == '+')
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (free_stack(stack), failure());
		temp = temp * 10 + num[i++] - '0';
		if (temp > INT_MAX || (temp * sign) < INT_MIN)
			return (free_stack(stack), failure());
	}
	if (ft_strlen(num) == 1 && (num[0] == '+' || num[0] == '-'))
		return (free_stack(stack), failure());
	*n = temp * sign;
}

t_stack	*check_params(char **av, int ac)
{
	t_stack	*stack;
	int		i;
	int		n;

	i = 0;
	if (!ac)
		return (0);
	stack = init_stack(ac, ac);
	while (i < ac && av && av[i])
	{
		if (!av[i])
			return (NULL);
		check_digit(av[i], &n, stack);
		stack->tab[i++] = n;
	}
	return (stack);
}
