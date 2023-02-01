/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_pt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:12:15 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/31 11:30:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != 0x0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*next;
	void	*temp;

	if (!begin_list || !cmp)
		return ;
	current = *begin_list;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			if (cmp(current->content, next->content) > 0)
			{
				temp = current->content;
				current->content = next->content;
				next->content = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
}
