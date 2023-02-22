# VAR ====================================

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3
LIBPATH = libft/
# FILES ==================================

SRCS = bucket_sort.c errors.c push_swap.c pushes.c rev_rotates.c \
	rotates.c selection_sort.c stooge_sort.c swaps.c utils.c debug.c
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

test100:
	./push_swap 99 89 79 69 59 49 39 29 19 09 98 88 78 68 58 48 38 28 18 08 97 87 77 67 57 47 37 27 17 07 96 86 76 66 56 46 36 26 16 06 95 85 75 65 55 45 35 25 15 05 94 84 74 64 54 44 34 24 14 04 93 83 73 63 53 43 33 23 13 03 92 82 72 62 52 42 32 22 12 02 91 81 71 61 51 41 31 21 11 01 90 80 70 60 50 40 30 20 10 0

.PHONY: all clean fclean re norm