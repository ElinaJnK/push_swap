#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_elem
{
	int	pos;
	int	val;
}	t_elem;

typedef struct s_stack
{
	t_elem	*tab;
	int		curr_size;
	int		size;
}	t_stack;

t_stack	*init_stack(int size, int curr_size);
void	free_stack(t_stack *stack);
void	quicksort(int *tab, int min, int max);
t_stack	*check_params(char **av, int ac);
void	failure();


void	swap(t_stack *s);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	do_move(t_stack *a, t_stack *b, char *move);
#endif