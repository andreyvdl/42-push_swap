/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:20:05 by adantas-          #+#    #+#             */
/*   Updated: 2022/09/17 18:20:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw_item;

	nw_item = (t_list *)malloc(sizeof(t_list));
	if (nw_item == 0x0)
		return (0x0);
	nw_item->content = content;
	nw_item->next = 0x0;
	return (nw_item);
}

t_list	*ft_lstpush_strs(size_t size, char **strs)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	i;

	if (!strs || !*strs)
		return (0x0);
	lst = ft_lstnew(strs[0]);
	i = 1;
	while (size-- > 0)
	{
		tmp = ft_lstnew(strs[i++]);
		ft_lstadd_back(&lst, tmp);
	}
	return (lst);
}
