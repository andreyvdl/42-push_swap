/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:58:16 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/17 17:59:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_sort(t_stack *stks, int bucket[], int buck_sz)
{
	size_t h_first;
	size_t h_last;

	while (stks->sz_a != 3)
	{
		h_first = 0;
		while (!part_bucket(stks, bucket, buck_sz, h_first))
		h_last = stks->sz_a;
	}
	bucket_sort(stks,)
}