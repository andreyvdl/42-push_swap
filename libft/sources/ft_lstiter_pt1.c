/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:58:25 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/31 11:29:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0x0)
		return ;
	while (lst != 0x0)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = 0x0;
	while (lst != 0x0)
	{
		ft_lstadd_back(&new_lst, ft_lstnew(f(lst->content)));
		if (new_lst == 0x0)
		{
			ft_lstclear(&new_lst, del);
			return (0x0);
		}
		lst = lst->next;
	}
	return (new_lst);
}

void	ft_lst_foreach_if(t_list *begin_list, void (*f)(void *),
void *data_ref, int (*cmp)())
{
	if (!f || !data_ref || !cmp)
		return ;
	while (begin_list != 0x0)
	{
		if (cmp(begin_list->content, data_ref) == 0)
			f(begin_list->content);
		begin_list = begin_list->next;
	}
}

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!begin_list || !data_ref || !cmp || !free_fct)
		return ;
	current = *begin_list;
	prev = 0x0;
	while (current)
	{
		next = current->next;
		if (cmp(current->content, data_ref) == 0)
		{
			if (!prev)
				*begin_list = next;
			else
				prev->next = next;
			free_fct(current->content);
			free(current);
		}
		else
			prev = current;
		current = next;
	}
}

void	ft_lstreverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = 0x0;
	current = *begin_list;
	while (current != 0x0)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}
