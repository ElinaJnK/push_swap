CC			= cc

NAME		= push_swap
NAME_BONUS 	= checker

SOURCES		= 	main.c			\
				check_params.c	\
				quicksort.c		\
				presort.c 		\
				stack.c			\
				double_moves.c	\
				moves.c			\
				costs.c			\
				cost_utils.c 	\
				do_while_costs.c\

SOURCES_BONUS = checker.c		\
				check_params.c	\
				quicksort.c		\
				presort.c 		\
				stack.c			\
				double_moves.c	\
				moves.c			\

LIBFT		= libft

CFLAGS		= -Wall -Wextra -Werror -g3

INCLUDE		= include

SRC_DIR		= src

OBJ_DIR		= obj
OBJ_DIR_BONUS = obj_bonus

RM			= rm -f

SRC	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJS =	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

SRC_BONUS = $(addprefix $(SRC_DIR)/,$(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(SOURCES_BONUS:.c=.o))

all: lib obj $(NAME)

bonus: lib obj_bonus $(NAME_BONUS)

lib:
	@make -C $(LIBFT)

obj:
	mkdir -p $(OBJ_DIR)

obj_bonus:
	mkdir -p $(OBJ_DIR_BONUS)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) -L $(LIBFT) -lft -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C libft
	$(CC) $(OBJS_BONUS) -L $(LIBFT) -lft -o $(NAME_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)/push_swap.h Makefile
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c $(INCLUDE)/push_swap.h Makefile
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re