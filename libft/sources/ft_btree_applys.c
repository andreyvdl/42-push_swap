/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_applys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:04:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/01 12:39:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_structs.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	applyf(root->content);
	ft_btree_apply_prefix(root->left, applyf);
	ft_btree_apply_prefix(root->right, applyf);
}

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	ft_btree_apply_infix(root->left, applyf);
	applyf(root->content);
	ft_btree_apply_infix(root->right, applyf);
}

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	ft_btree_apply_suffix(root->left, applyf);
	ft_btree_apply_suffix(root->right, applyf);
	applyf(root->content);
}
