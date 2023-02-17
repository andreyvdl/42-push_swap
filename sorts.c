/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/17 17:58:34 by adantas-         ###   ########.fr       */
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

void	selection_sort(t_stack *stks)
{
	size_t	i;
	size_t	j;
	size_t	ref;

	ref = 0;
	while (stks->sz_a != 3 && !is_sorted(stks, 1))
	{
		i = -1;
		j = 0;
		while (stks->a[++i] != stks->f[ref] && i < stks->sz_a)
			j++;
		select_send_next(stks, j, ref);
		ref++;
	}
	if (stks->sz_a == 3)
		stooge_sort(stks);
	while (stks->sz_b)
		push_a(stks);
}

// void	mia_cambalhotas(t_stack *stks)
// {
// }

// void	quick_sort(t_stack *stks)
// {
// 	int	tmp;

// 	while (stks->sz_a)
// 	{
// 		tmp = stks->a[stks->sz_a - 1];
// 		while (stks->a[0] != tmp)
// 		{
// 			if (stks->a[0] > tmp)
// 				rot_a(stks);
// 			else
// 				push_b(stks);
// 		}
// 	}
// }

// void	radix_sort(t_stack *stks)
// {
// 	int	div;
// 	int	bool;
// 	int	max;
// 	int	i;

// 	div = 1;
// 	bool = 1;
// 	max = stks->f[stks->sz - 1];
// 	while (max / div > 0 && (!is_sorted(stks, 1) || is_revsorted(stks, 0)))
// 	{
// 		i = -1;
// 		while (++i < 10)
// 		{
// 		}
// 	}
// 	while (stks->sz_b > 0)
// 		push_a(stks);
// }
