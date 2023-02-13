/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/13 15:28:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stks;

	if (argc == 1)
		exit(0);
	validate(argc, argv, &stks);
	if (is_sorted(&stks))
	{
		free_strct(&stks);
		exit(0);
	}
	simple_solve(&stks);
	return (free_strct(&stks), exit(0));
}

t_stack	*validate(int size, char **args, t_stack *stks)
{
	int		i;
	int		j;

	stks->a = (int *)ft_calloc(size - 1, sizeof(int));
	stks->b = (int *)ft_calloc(size - 1, sizeof(int));
	if (!stks->a || !stks->b)
		return (free_strct(&stks), msg(12));
	i = 1;
	while (i < size)
	{
		arg_is_invalid(args[i], &stks);
		arg_is_over(args[i], &stks);
		stks->a[i - 1] = (int)ft_atoi(args[i]);
		i++;
	}
	stks->sz_a = size - 1;
	stks->sz_b = 0;
	return (&stks);
}

int	simple_solve(t_stack *stks)
{
	if (stks->sz == 2)
	{
		swap_a(stks);
		free_strct(stks);
		exit(0);
	}
	else if (stks->sz == 3)
	{
		stooge_sort(stks);
		free_strct(stks);
		exit(0);
	}
	else if (stks->sz == 4 && !is_sorted(stks))
		return (merge_sort(stks), free_strct(stks), exit(0));
	else if (stks->sz >= 5 && !is_sorted(stks))
		return (sort(stks), free_strct(stks), exit(0));
	return (0);
}
