/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/22 11:35:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stooge_sort(t_stack *stks)
{
	while (!is_sorted(stks, 1))
	{
		if (stks->a[0] < stks->a[1] && stks->a[0] < stks->a[2])
		{
			revrot_a(stks);
			swap_a(stks);
		}
		else if (stks->a[0] > stks->a[1] && stks->a[0] < stks->a[2])
			swap_a(stks);
		else if (stks->a[0] < stks->a[1] && stks->a[0] > stks->a[2])
			revrot_a(stks);
		else if (stks->a[0] > stks->a[1] && stks->a[1] < stks->a[2])
			rot_a(stks);
		else if (stks->a[0] > stks->a[1] && stks->a[1] > stks->a[2])
		{
			rot_a(stks);
			swap_a(stks);
		}
	}
}
