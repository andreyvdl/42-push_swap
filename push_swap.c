/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/03 17:44:07 by adantas-         ###   ########.fr       */
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
	simple_solve(&stks);
	else if (argc == 4)
		boog
	return (free_strct(&stks), exit(0));
}

int	simple_solve(t_stack *stks)
{
	if (stks->sz == 2 && stks->a[0] > stks->a[1])
		return (swap_a(stks), free_strct(stks), exit(0));
	else if (stks->sz == 2 && stks->a[0] < stks->a[1])
		return (free_strct(stks), exit(0));
	if (stks->sz == 3)
		return (stooge_sort(stks), free_strct(stks), exit(0));
	if (stks->sz == 4)
		return (merge_sort(stks), free_strct(stks), exit(0));
	return (0);
}

int	merge_sort(t_stack *stks)
{
	if (stks->a[0] > stks->a[1])
		swap_a(stks);
	if (stks->a[2] > stks->a[3])
	{
		rot_a(stks);
		rot_a(stks);
		swap_a(stks);
	}
}

int	stooge_sort(t_stack *stks)
{
	if (stks->a[0] > stks->a[1])
		swap_a(stks);
	if (stks->a[1] > stks->a[2])
		revrot_a(stks);
	if (stks->a[0] > stks->a[2])
		rot_a(stks);
	if (stks->a[0] > stks->a[1] || stks->a[1] > stks->a[2]
		|| stks->a[0] > stks->a[2])
		stooge_sort(stks);
	return (0);
}

t_stack	*validate(int size, char **args)
{
	int		i;
	int		j;
	int		comp;
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
		comp = ft_atoi(args[i]);
		stks.a[i - 1] = (int)comp;
		i++;
	}
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