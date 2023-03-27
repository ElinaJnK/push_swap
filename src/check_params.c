#include "../include/push_swap.h"

void	failure()
{
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

long long int	ft_atoi_maison(const char *str)
{
	int				sign;
	int				i;
	unsigned int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';

	return ((long long int)sign * nb);
}

// suppose the stack is sorted
void	check_dup(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->tab[i] == stack->tab[i + 1])
			return (free_stack(stack), failure());
	}
}

void	check_digit(char *num, int *n, t_stack	*stack)
{
	size_t i;
	long long int temp;

	i = 0;
	if (num[i] == '-')
		i++;
	while (i < ft_strlen(num))
	{
		if (num[i] < '0' || num[i] > '9')
			failure();
		++i;
	}
	temp = ft_atoi_maison(num);
	if (temp > INT_MAX || temp < INT_MIN)
		return (free_stack(stack), failure());
	*n = temp;
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
	while(i < ac && av && av[i])
	{
		if (!av[i])
			return (NULL);
		check_digit(av[i], &n, stack);
		stack->tab[i++] = n;
	}
	return (stack);
}