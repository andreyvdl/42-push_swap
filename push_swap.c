/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/08 15:08:14 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648

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

int	is_sorted(t_stack *stks)
{
	int	i;

	i = -1;
	while (++i < stks->sz)
	{
		if (stks->a[i] != stks->f[i])
			return (0);
	}
	return (1);
}

int	simple_solve(t_stack *stks)
{
	if (stks->sz == 2 && !is_sorted(stks))
		return (swap_a(stks), free_strct(stks), exit(0));
	else if (stks->sz == 2 && is_sorted(stks))
		return (free_strct(stks), exit(0));
	if (stks->sz == 3 && !is_sorted(stks))
		return (stooge_sort(stks), free_strct(stks), exit(0));
	if (stks->sz == 4)
		return (insert_sort(stks), free_strct(stks), exit(0));
	return (0);
}

int	booble_sort(t_stack *stks)
{
	while (!is_sorted(stks))
	{
		if (stks->a[0] > stks->a[1])
			swap_a(stks);
		rot_a(stks);
	}
}

int	stooge_sort(t_stack *stks)
{
	if (stks->[0] < stks->a[1] && stks->a[0] < stks->a[2])
	{
		revrot_a(stks);
		swap_a(stks);
	}
	else if (stks->a[0] > stks->a[1] && stks->a[0] < stks->a[2])
		swap_a(stks);
	else if (stks->a[0] < stks->a[1] && stks->a[0] > stks->a[2])
		revrot_a(stks);
	else if (stks->a[0] > stks->a[1] && stks->a[0] > stks->a[2])
		rot_a(stks);
	else if (stks->a[0] > stks->a[1] && stks->[1] > stks->a[2])
	{
		swap_a(stks);
		rot_a(stks);
	}
	if (!is_sorted(stks))
		return (stooge_sort(stks));
	return (0);
}

void	sort_it(t_stack *stks)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < stks->sz)
		stks->f[i] = stks->a[i];
	i = -1;
	while (++i < stks->sz)
	{
		j = i;
		while (++j < stks->sz)
		{
			if (stks->f[i] > stks->f[j])
			{
				tmp = stks->f[i];
				stks->f[i] = stks->f[j];
				stks->f[j] = tmp;
			}
		}
	}
}

int	msg(int code)
{
	if (code == 12)
		return (ft_println("Error: ENOMEM: Cannot allocate memory."),
			exit(code));
	else if (code == 22)
		return (ft_println("Error"), exit(code));
	return (0);
}

void	free_strct(t_stack *stks)
{
	ft_free(stks->a);
	ft_free(stks->b);
	ft_free(stks->f);
}