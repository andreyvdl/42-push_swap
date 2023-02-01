/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:45:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/31 11:28:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !data_ref || !cmp)
		return (0x0);
	while (begin_list != 0x0)
	{
		if (cmp(begin_list->content, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0x0);
}

t_list	*ft_lstat(t_list *begin_list, size_t nbr)
{
	size_t	i;

	if (!begin_list)
		return (0x0);
	i = -1;
	while (++i < nbr)
	{
		if (begin_list->next == 0x0)
			return (0x0);
		begin_list = begin_list->next;
	}
	return (begin_list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0x0)
		return (lst);
	while (lst->next != 0x0)
		lst = lst->next;
	return (lst);
}
