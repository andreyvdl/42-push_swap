/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:48:51 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/15 17:08:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stks)
{
	int	i;

	if (!stks->sz_b)
		return ;
	i = (int)stks->sz_a;
	while (--i >= 0)
		stks->a[i + 1] = stks->a[i];
	stks->a[0] = stks->b[0];
	i = -1;
	while (++i < (int)stks->sz_b - 1)
		stks->b[i] = stks->b[i + 1];
	stks->sz_a++;
	stks->sz_b--;
	ft_println("pa");
}

void	push_b(t_stack *stks)
{
	int	i;

	if (!stks->sz_a)
		return ;
	i = (int)stks->sz_b;
	while (--i >= 0)
		stks->b[i + 1] = stks->b[i];
	stks->b[0] = stks->a[0];
	i = -1;
	while (++i < (int)stks->sz_a - 1)
		stks->a[i] = stks->a[i + 1];
	stks->sz_a--;
	stks->sz_b++;
	ft_println("pb");
}
