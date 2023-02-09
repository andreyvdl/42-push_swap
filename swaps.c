/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:54:43 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/09 12:48:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stks)
{
	int	tmp;

	if (stks->sz_a < 2)
		return ;
	tmp = stks->a[0];
	stks->a[0] = stks->a[1];
	stks->a[1] = tmp;
	ft_println("sa");
}

void	swap_b(t_stack *stks)
{
	int	tmp;

	if (stks->sz_b < 2)
		return ;
	tmp = stks->b[0];
	stks->b[0] = stks->b[1];
	stks->b[1] = tmp;
	ft_println("sb");
}

void	swap_ss(t_stack *staks)
{
	int	tmp;

	if (staks->sz_a < 2 || staks->sz_b < 2)
		return ;
	tmp = staks->a[0];
	staks->a[0] = staks->a[1];
	staks->a[1] = tmp;
	tmp = staks->b[0];
	staks->b[0] = staks->b[1];
	staks->b[1] = tmp;
	ft_println("ss");
}
