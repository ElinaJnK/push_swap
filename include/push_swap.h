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

int		ft_abs(int val);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

int		*copy_tab(t_stack *stack);

void	do_while_both(t_stack *a, t_stack *b, int *ca, int *cb);
void	do_while_a(t_stack *a, t_stack *b, int *ca);
void	do_while_b(t_stack *a, t_stack *b, int *cb);

t_stack	*presort(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	sort_3(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

t_stack	*init_stack(int size, int curr_size);
void	free_stack(t_stack *stack);
void	update_stack(int *sorted_tab, t_stack *stack);
void	quicksort(int *tab, int min, int max);
t_stack	*check_params(char **av, int ac);
void	failure(void);
void	check_dup(int *tab, int size);
int		get_papa_a(t_stack *a, int elem);
int		best_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b);

void	swap(t_stack *s);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	do_move(t_stack *a, t_stack *b, char *move);
#endif