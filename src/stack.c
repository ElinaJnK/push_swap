#include "../include/push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->tab = (int *)malloc(sizeof(int) * size);
	if (!stack->tab)
		return (NULL);
	stack->size = size;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->tab);
	free(stack);
}