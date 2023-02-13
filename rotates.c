/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:44:47 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/13 13:25:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_stack *stks)
{
	int	i;
	int	tmp;

	if (stks->sz_a < 2)
		return ;
	tmp = stks->a[0];
	i = -1;
	while (++i < stks->sz_a - 1)
		stks->a[i] = stks->a[i + 1];
	stks->a[i] = tmp;
	ft_println("ra");
}

void	rot_b(t_stack *stks)
{
	int	i;
	int	tmp;

	if (stks->sz_b < 2)
		return ;
	tmp = stks->b[0];
	i = -1;
	while (++i < stks->sz_b - 1)
		stks->b[i] = stks->b[i + 1];
	stks->b[i] = tmp;
	ft_println("rb");
}

void	rot_ab(t_stack *stks)
{
	int	i;
	int	tmp;

	if (stks->sz_a < 2 || stks->sz_b < 2)
		return ;
	tmp = stks->a[0];
	i = -1;
	while (++i < stks->sz_a - 1)
		stks->a[i] = stks->a[i + 1];
	stks->a[i] = tmp;
	tmp = stks->b[0];
	i = -1;
	while (++i < stks->sz_b - 1)
		stks->b[i] = stks->b[i + 1];
	stks->b[i] = tmp;
	ft_println("rr");
}
