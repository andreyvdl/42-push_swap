# VAR ====================================

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -O3
LIBPATH = libft/
# FILES ==================================

SRCS = bucket_sort.c errors.c push_swap.c pushes.c rev_rotates.c \
	rotates.c selection_sort.c stooge_sort.c swaps.c utils.c
OBJS = $(SRCS:%.c=%.o)
# COLORS =================================

BLACK =		\033[1;30m
RED =		\033[1;31m
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
BLUE =		\033[1;34m
PURPLE =	\033[1;35m
CYAN =		\033[1;36m
WHITE =		\033[1;37m
RESET =		\033[0m
# RULES ==================================

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Creating $(NAME)...$(RESET)"
	@make -C $(LIBPATH)
	@cc $(CFLAGS) -I . $(OBJS) $(LIBPATH)libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS):
	@cc $(CFLAGS) -I . -c $(@:%.o=%.c)

clean:
	@rm -rf $(OBJS)
	@make $@ -C $(LIBPATH)
	@echo "$(WHITE)Objects deleted.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make $@ -C $(LIBPATH)
	@echo "$(PURPLE)$(NAME) removed.$(RESET)"

re: fclean all
	@echo "$(RED)Recompilation completed.$(RESET)"

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@norminette
	@echo "$(YELLOW)All OK.$(RESET)"

tests:
	./push_swap
	./push_swap 1
	./push_swap -1
	./push_swap -1a
	./push_swap ""
	./push_swap "-"
	./push_swap 1 -1 1
	./push_swap 1 2 3 4 5 6 7 8 9 10
	./push_swap "1 2 3 4 5 10 9 8 7 6"

test2:
	./push_swap 1 2
	./push_swap 2 1

test3:
	./push_swap 1 2 3
	./push_swap 3 2 1
	ARG=$$(seq 1 3 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 3 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 3 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 3 | shuf); ./push_swap $$ARG | wc -l

test4:
	./push_swap 1 2 3 4
	./push_swap 4 3 2 1
	ARG=$$(seq 1 4 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 4 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 4 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 4 | shuf); ./push_swap $$ARG | wc -l

test5:
	./push_swap 1 2 3 4 5
	./push_swap 5 4 3 2 1
	ARG=$$(seq 1 5 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 5 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 5 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 5 | shuf); ./push_swap $$ARG | wc -l

test100:
	ARG=$$(seq 1 100 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 100 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 100 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 100 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 100 | shuf); ./push_swap $$ARG | wc -l

test500:
	ARG=$$(seq 1 500 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 500 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 500 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 500 | shuf); ./push_swap $$ARG | wc -l
	ARG=$$(seq 1 500 | shuf); ./push_swap $$ARG | wc -l

.PHONY: all clean fclean re norm