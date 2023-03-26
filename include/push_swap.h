#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*tab;
	int	size;
}	t_stack;

t_stack	*init_stack(int size);
void	free_stack(t_stack *stack);
void	quicksort(int *tab, int min, int max);
t_stack	*check_params(char **av, int ac);
void	failure();
#endif