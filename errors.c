/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:07:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/09 14:08:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648

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
}
