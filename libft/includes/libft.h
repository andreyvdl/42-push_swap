/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/14 15:32:00 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft_defines.h"
# include "libft_structs.h"

// converters
size_t	ft_btoi(char *bin);
size_t	ft_htoi(char *hex);
size_t	ft_otoi(char *octal);
ssize_t	ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_itoh(size_t n);
char	*ft_itoo(size_t n);
char	*ft_itob(size_t nbr);

// is*
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
int		ft_isprime(size_t nb);

// math
double	ft_sum(size_t n, ...);
double	ft_power(double n, ssize_t exp);
size_t	ft_termial(size_t n);
ssize_t	ft_absolute(ssize_t n);
size_t	ft_factorial(size_t n);
double	ft_neg_power(double n, ssize_t exp);
ssize_t	ft_next_prime(ssize_t nb);

// prints
void	ft_putnbr(int n);
int		print_chr(int c);
int		print_int(int nbr);
void	ft_putstr(char *str);
int		print_str(char *str);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		print_uint(unsigned int nbr);
int		ft_println(const char *str, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		print_hex_cap(size_t hex);
int		print_ptr_hex(size_t ptr);
int		print_hex_low(size_t hex);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

// mem*
void	ft_free(void *ptr);
void	ft_swap(void **a, void **b);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	ft_free_matrix(void **matrix);

// str*
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrev(char *str);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, char *src);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(const char *str, const char *to_find);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strupcase(char *str);
char	*get_next_line(int fd);
char	*ft_strlowcase(char *str);
char	**ft_matrixdup(char **matrix);
char	*ft_strcapitalize(char *str);

// linked list
t_list	*ft_lstat(t_list *begin_list, size_t nbr);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstsort(t_list **begin_list, int (*cmp)());
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstreverse(t_list **begin_list);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *));
t_list	*ft_lstpush_strs(size_t size, char **strs);
void	ft_lst_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref,
			int (*cmp)());

// binary tree
t_btree	*ft_btree_new(void *item);
void	ft_btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void*));
void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	*ft_btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *));
void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));

// DO NOT USE -function specific- DO NOT USE
int		this_flag(unsigned char c, va_list al);
void	*ft_realloc_mod(char **ptr);
char	*ft_strjoin_mod(char *s1, char *s2);

// rest of the original libft
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif