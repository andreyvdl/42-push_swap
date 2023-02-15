/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:17:56 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stks)
{
	size_t	i;

	i = -1;
	ft_printf("===STACK A===\n[");
	while (++i < stks->sz_a)
	{
		if (i == stks->sz_a - 1)
			ft_println("%d]", stks->a[i]);
		else
			ft_printf("%d, ", stks->a[i]);
	}
	ft_println(" ");
	i = -1;
	ft_printf("===STACK B===\n[");
	while (++i < stks->sz_b)
	{
		if (i == stks->sz_b - 1)
			ft_println("%d]", stks->b[i]);
		else
			ft_printf("%d, ", stks->b[i]);
	}
	ft_println(" ");
	i = -1;
	ft_printf("===STACK RIGHT===\n[");
	while (++i < stks->sz)
	{
		if (i == stks->sz - 1)
			ft_println("%d]", stks->f[i]);
		else
			ft_printf("%d, ", stks->f[i]);
	}
	ft_println(" ");
}
