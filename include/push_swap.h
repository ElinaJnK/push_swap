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
	int		*tab;
	int		curr_size;
	int		size;
}	t_stack;

void print_array(int *arr, int size);
void print_array_double(double *arr, int size);

t_stack	*presort(t_stack *stack);
void	sort(t_stack *a, t_stack *b);

t_stack	*init_stack(int size, int curr_size);
void	free_stack(t_stack *stack);
void	update_stack(int *sorted_tab, t_stack *stack);
void	quicksort(int *tab, int min, int max);
t_stack	*check_params(char **av, int ac);
void	failure();
void	check_dup(int *tab, int size);

void	swap(t_stack *s);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	do_move(t_stack *a, t_stack *b, char *move);
#endif