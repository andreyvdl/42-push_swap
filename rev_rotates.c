/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:49:56 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/13 13:25:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot_a(t_stack *stks)
{
	int	i;
	int	tmp;

	if (stks->sz_a < 2)
		return ;
	tmp = stks->a[stks->sz_a - 1];
	i = stks->sz_a;
	while (--i > 0)
		stks->a[i] = stks->a[i - 1];
	stks->a[i] = tmp;
	ft_println("rra");
}

void	revrot_b(t_stack *stks)
{
	int	i;
	int	tmp;

	if (stks->sz_b < 2)
		return ;
	tmp = stks->b[stks->sz_b - 1];
	i = stks->sz_b;
	while (--i > 0)
		stks->b[i] = stks->b[i - 1];
	stks->b[i] = tmp;
	ft_println("rrb");
}

void	revrot_ab(t_stack *stks)
{
	int	i;
	int	tmp;

	if (stks->sz_a < 2 || stks->sz_b < 2)
		return ;
	tmp = stks->a[stks->sz_a - 1];
	i = stks->sz_a;
	while (--i > 0)
		stks->a[i] = stks->a[i - 1];
	stks->a[i] = tmp;
	tmp = stks->b[stks->sz_b - 1];
	i = stks->sz_b;
	while (--i > 0)
		stks->b[i] = stks->b[i - 1];
	stks->b[i] = tmp;
	ft_println("rrr");
}
