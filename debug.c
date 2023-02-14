/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:17:56 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/14 15:33:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stks)
{
	size_t	i;

	i = -1;
	ft_printf("===STACK A===\n[");
	while (++i <= stks->sz_a)
	{
		if (i == stks->sz_a)
			ft_printf("%d]\n", stks->a[i]);
		else
			ft_printf("%d, ", stks->a[i]);
	}
	i = -1;
	ft_printf("===STACK B===\n[");
	while (++i <= stks->sz_b)
	{
		if (i == stks->sz_b)
			ft_printf("%d]\n", stks->b[i]);
		else
			ft_printf("%d, ", stks->b[i]);
	}
}
