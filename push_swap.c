/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/09 17:59:54 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stks;

	if (argc == 1)
		exit(0);
	stks = validate(argc, argv);
	if (argc == 2 || is_sorted(&stks))
		return (free_strct(&stks), exit(0));
	simple_solve(&stks);
	return (free_strct(&stks), exit(0));
}

t_stack	*validate(int size, char **args)
{
	int		i;
	int		j;
	t_stack	stks;

	stks.a = (int *)ft_calloc(size - 1, sizeof(int));
	stks.b = (int *)ft_calloc(size - 1, sizeof(int));
	if (!stks.a || !stks.b)
		return (free_strct(&stks), msg(12));
	i = 1;
	while (i < size)
	{
		arg_is_invalid(args[i], &stks);
		arg_is_over(args[i], &stks);
		stks.a[i - 1] = (int)ft_atoi(args[i]);
		i++;
	}
	stks.sz_a = size - 1;
	stks.sz_b = 0;
	return (&stks);
}

int	simple_solve(t_stack *stks)
{
	if (stks->sz == 2 && !is_sorted(stks))
		return (swap_a(stks), free_strct(stks), exit(0));
	else if (stks->sz == 2 && is_sorted(stks))
		return (free_strct(stks), exit(0));
	else if (stks->sz == 3 && !is_sorted(stks))
		return (stooge_sort(stks), free_strct(stks), exit(0));
	else if (stks->sz == 4 && !is_sorted(stks))
		return (merge_sort(stks), free_strct(stks), exit(0));
	else if (stks->sz >= 5 && !is_sorted(stks))
		return (sort(stks), free_strct(stks), exit(0));
	return (0);
}

int	merge_sort(t_stack *stks)
{
	push_b(stks);
	push_b(stks);
	if (stks->a[0] > stks->a[1] && stks->b[0] < stks->b[1])
		swap_ss(stks);
	else if (stks->a[0] > stks->a[1])
		swap_a(stks);
	else if (stks->b[0] < stks->b[1])
		swap_b(stks);
	push_a(stks);
	if (stks->a[0] > stks->a[1] && stks->a[0] < stks->a[2])
		swap_a(stks);
	else if (stks->a[0] > stks->a[1] && stks->a[0] > stks->a[2])
		rot_a(stks);
	else if (stks->a[0] < stks->a[1] && stks->a[0] > stks->a[2])
		revrot_a(stks);
	push_a(stks);
	if (stks->a[0] > stks->a[1] && stks->a[0] < stks->a[3])
		swap_a(stks);
	else if (stks->a[0] > stks->a[1] && stks->a[0] > stks->a[3])
		rot_a(stks);
	else if (stks->a[0] < stks->a[1] && stks->a[0] > stks->a[3])
		revrot_a(stks);
}

int	radix_sort(t_stack *stks)
{
	int	bit;

	bit = 1;
	while (stks->sz_a != 0)
	{
		if (stks->a[0] & bit == 0)
		{
			push_b(stks);
			continue ;
		}
		
	}
}
