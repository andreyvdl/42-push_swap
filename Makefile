# VAR ====================================

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3
LIBPATH = libft/
# FILES ==================================

SRCS = errors.c push_swap.c pushes.c rev_rotates.c \
	rotates.c sorts.c swaps.c utils.c debug.c
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

.PHONY: all clean fclean re norm