# ======= VARIABLES =======
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
# ======= FILES =======
LIB_SRCS = $(addprefix sources/,ft_absolute.c \
	ft_btree_applys.c ft_btree_insert_data.c ft_btree_new.c ft_btree_search_item.c \
	ft_convert_pt1.c ft_convert_pt2.c ft_frees.c ft_gnl_utils.c ft_gnl.c ft_is_pt1.c ft_is_pt2.c \
	ft_lstadd.c ft_lstdelete.c ft_lstfind.c ft_lstiter_pt1.c ft_lstiter_pt2.c ft_lstnew.c \
	ft_math_pt1.c ft_math_pt2.c ft_memcmp.c ft_memset.c ft_print_hex.c ft_print_nbr.c ft_printf.c \
	ft_println.c ft_put_fd.c ft_put.c ft_split.c ft_strcapitalize.c ft_strcat.c ft_strcmp_pt1.c \
	ft_strcmp_pt2.c ft_strdup_pt1.c ft_strdup_pt2.c ft_striteri.c ft_swap.c ft_to.c)
LIB_OBJS = $(LIB_SRCS:%.c=%.o)
# ======= COLORS ========
BLACK =		\033[1;30m
RED =		\033[1;31m
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
BLUE =		\033[1;34m
PURPLE =	\033[1;35m
CYAN =		\033[1;36m
WHITE =		\033[1;37m
RESET =		\033[0m
# ======= RULES =======

all: $(NAME)

$(NAME): $(LIB_OBJS)
	@echo "$(GREEN)Creating $(NAME)...$(RESET)"
	@mv *.o sources/
	@ar rcs $(NAME) $(LIB_OBJS)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(LIB_OBJS):
	@cc $(CFLAGS) -I includes/. -c $(@:%.o=%.c)

clean:
	@rm -rf $(LIB_OBJS)
	@echo "$(WHITE)Objects deleted.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(PURPLE)$(NAME) removed.$(RESET)"

re: fclean all
	@echo "$(RED)Recompilation completed.$(RESET)"

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@norminette
	@echo "$(YELLOW)All OK.$(RESET)"

.PHONY: all clean fclean re norm