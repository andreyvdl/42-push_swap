/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:20:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/31 10:58:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	void	*content;

	content = 0x0;
	if (!root || !data_ref || !cmpf)
		return (0x0);
	content = ft_btree_search_item(root->left, data_ref, cmpf);
	if (content)
		return (content);
	if (cmpf(root->content, data_ref) == 0)
		return (root->content);
	content = ft_btree_search_item(root->right, data_ref, cmpf);
	if (content)
		return (content);
	return (0x0);
}
