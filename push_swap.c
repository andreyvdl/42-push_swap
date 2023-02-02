/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/02 17:20:46 by adantas-         ###   ########.fr       */
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
	if (argc == 2)
		return (free_strct(&stks), exit(0));
	else if (argc == 3)
		bi_sort(&stks);
	else if (argc == 4)
		boog
	return (free_strct(&stks), exit(0));
}

t_stack	*validate(int size, char **args)
{
	int		i;
	int		j;
	int		comp;
	t_stack	stks;

	stks.a = (int *)ft_calloc(argc, sizeof(int));
	stks.b = (int *)ft_calloc(argc, sizeof(int));
	stks.f = (int *)ft_calloc(argc, sizeof(int));
	if (!stks.a || !stks.b || !stks.f)
		return (free_strct(&stks), msg(12));
	i = 1;
	while (i < size - 1)
	{
		arg_is_invalid(args[i], &stks);
		arg_is_over(args[i], &stks);
		comp = ft_atoi(args[i]);
		stks.a[i - 1] = (int)comp;
		i++;
	}
	return (&stks);
}

int	arg_is_over(char *arg, t_stack *stks)
{
	int	i;
	int	comp;

	i = 0;
	comp = 1;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			comp = 0;
		i++;
	}
	if (comp)
		arg_is_big(arg, stks, i);
	else
		arg_is_small(arg, stks, i);
	return (0);
}

int	arg_is_big(char *arg, t_stack *stks, int i)
{
	int	j;

	j = 0;
	while (arg[i])
	{
		if (arg[i] > MAX_INT[j])
			return (free_strct(stks), msg(22));
		i++;
		j++;
	}
	return (0);
}

int	arg_is_small(char *arg, t_stack *stks, int i)
{
	int	j;

	j = 1;
	while (arg[i])
	{
		if (arg[i] > MIN_INT[j])
			return (free_strct(stks), msg(22));
		i++;
		j++;
	}
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
	ft_free(stks->f);
}