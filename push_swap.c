/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/22 17:05:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stks;

	if (argc == 1)
		exit(0);
	validate(argc, argv, &stks);
	if (is_sorted(&stks, 1))
	{
		free_strct(&stks);
		exit(0);
	}
	sort_reference(&stks);
	if (stks.sz != 100 && stks.sz != 500)
		simple_solve(&stks);
	else
		advanced_solve(&stks);
	//print_stacks(&stks);
	free_strct(&stks);
	exit(0);
}

int	validate(int size, char **args, t_stack *stks)
{
	int	i;

	stks->a = (int *)ft_calloc(size - 1, sizeof(int));
	stks->b = (int *)ft_calloc(size - 1, sizeof(int));
	stks->f = (int *)ft_calloc(size - 1, sizeof(int));
	if (!stks->a || !stks->b)
		return (free_strct(stks), msg(12));
	i = 0;
	while (++i < size)
	{
		arg_is_invalid(args[i], stks);
		arg_is_over(args[i], stks);
		stks->a[i - 1] = (int)ft_atoi(args[i]);
	}
	stks->sz_a = size - 1;
	stks->sz_b = 0;
	stks->sz = stks->sz_a;
	repeat_nums(stks);
	return (0);
}

void	simple_solve(t_stack *stks)
{
	if (stks->sz == 2)
		swap_a(stks);
	else if (stks->sz == 3)
		stooge_sort(stks);
	else
		selection_sort(stks);
}

void	advanced_solve(t_stack *stks)
{
	size_t	i;
	int		bucket[500];

	i = -1;
	ft_bzero(bucket, 500);
	while (++i < stks->sz)
		bucket[i] = stks->f[i];
	if (stks->sz == 100)
	{
		bucket_sort(stks, bucket, 20, 100);
		push_b(stks);
		push_order(stks);
	}
	else
	{
		bucket_sort(stks, bucket, 50, 500);
		push_b(stks);
		push_order(stks);
	}
}
