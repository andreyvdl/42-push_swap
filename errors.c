/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:07:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/08 15:08:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648

t_stack	*validate(int size, char **args)
{
	int		i;
	int		j;
	t_stack	stks;

	stks.a = (int *)ft_calloc(size - 1, sizeof(int));
	stks.b = (int *)ft_calloc(size - 1, sizeof(int));
	stks.f = (int *)ft_calloc(size - 1, sizeof(int));
	if (!stks.a || !stks.b || !stks.f)
		return (free_strct(&stks), msg(12));
	stks.sz = size - 1;
	i = 1;
	while (i < size)
	{
		arg_is_invalid(args[i], &stks);
		arg_is_over(args[i], &stks);
		stks.a[i - 1] = (int)ft_atoi(args[i]);
		i++;
	}
	sort_it(&stks);
	stks.sz_a = stks.sz;
	stks.sz_b = 0;
	return (&stks);
}

int	arg_is_over(char *arg, t_stack *stks)
{
	ssize_t	comp;

	comp = ft_atoi(arg);
	if (comp > MAX_INT)
		return (free_strct(stks), msg(22));
	else if (comp < MIN_INT)
		return (free_strct(stks), msg(22));
	return (0);
}

int	arg_is_invalid(char *arg, t_stack *stks)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (free_strct(stks), msg(22));
		i++;
	}
	return (0);
}