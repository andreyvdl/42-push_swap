/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:07:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/27 12:45:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648

int	arg_is_over(char *arg, t_stack *stks)
{
	ssize_t	comp;

	if (arg[0] != '-' && ft_strlen(arg) > 10)
		return (free_strct(stks), msg(22));
	else if (arg[0] == '-' && ft_strlen(arg) > 11)
		return (free_strct(stks), msg(22));
	else if (!arg || !arg[0] || ((arg[0] == '-' || arg[0] == '+') && !arg[1]))
		return (free_strct(stks), msg(22));
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
	if (!arg[i])
		return (free_strct(stks), msg(22));
	while (arg[i] == 32)
		i++;
	if (!arg[i])
		return (free_strct(stks), msg(22));
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i] || !ft_isdigit(arg[i]))
		return (free_strct(stks), msg(22));
	while (arg[i] && arg[i] != 32)
	{
		if (!ft_isdigit(arg[i]))
			return (free_strct(stks), msg(22));
		i++;
	}
	while (arg[i] == 32)
		i++;
	if (arg[i])
		return (free_strct(stks), msg(22));
	return (0);
}

int	repeat_nums(t_stack *stks)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < stks->sz_a)
	{
		j = i;
		while (++j < stks->sz_a)
			if (stks->a[i] == stks->a[j])
				return (free_strct(stks), msg(22));
	}
	return (0);
}

int	msg(int code)
{
	if (code == 12)
	{
		ft_println("Error: ENOMEM: Cannot allocate memory.");
		exit(code);
	}
	else if (code == 22)
	{
		ft_println("Error");
		exit(code);
	}
	return (0);
}

int	free_strct(t_stack *stks)
{
	ft_free(stks->a);
	ft_free(stks->b);
	ft_free(stks->f);
	return (0);
}
