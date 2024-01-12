/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:07:49 by natali            #+#    #+#             */
/*   Updated: 2024/01/12 16:40:46 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*new_node(int nb, int pos)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->pos_curr = pos;
	new->pos_lst = 0;
	new->target_pos_a = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_node_back(t_data **lst, t_data *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		get_last_node(*lst)->next = new;
}

t_data	*get_last_node(t_data *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
