/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		*f;
	size_t	sz_a;
	size_t	sz_b;
	size_t	sz;
}	t_stack;

// moves functions (swaps.c, rotates.c, rev_rotates.c, pushes.c)
void	rot_a(t_stack *stks);
void	rot_b(t_stack *stks);
void	push_a(t_stack *stks);
void	push_b(t_stack *stks);
void	rot_ab(t_stack *stks);
void	swap_a(t_stack *stks);
void	swap_b(t_stack *stks);
void	swap_ab(t_stack *stks);
void	revrot_a(t_stack *stks);
void	revrot_b(t_stack *stks);
void	revrot_ab(t_stack *stks);

// errors.c functions
int		msg(int code);
int		free_strct(t_stack *stks);
int		repeat_nums(t_stack *stks);
int		arg_is_over(char *arg, t_stack *stks);
int		arg_is_invalid(char *arg, t_stack *stks);

// push_swap.c functions
int		validate(int size, char **args, t_stack *stks);
void	solve_all(t_stack *stks);
void	simple_solve(t_stack *stks);

// sorts.c functions
int		is_sorted(t_stack *stks);
void	stooge_sort(t_stack *stks);
void	insertion_sort(t_stack *stks);
void	selection_sort(t_stack *stks, size_t dist, size_t ref);

// debug.c
void	print_stacks(t_stack *stks);

#endif