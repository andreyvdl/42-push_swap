/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/01 12:42:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

void	ft_btree_insert_data(t_btree **root, void *item,
int (*cmpf)(void *, void*))
{
	t_btree	*current;

	if (!item || !cmpf)
		return ;
	if (!root)
	{
		*root = ft_btree_new(item);
		return ;
	}
	current = *root;
	if (cmpf(item, current->content) >= 0)
		ft_btree_insert_data(&current->right, item, cmpf);
	else
		ft_btree_insert_data(&current->left, item, cmpf);
}
