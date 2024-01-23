/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:16 by natali            #+#    #+#             */
/*   Updated: 2024/01/23 15:23:41 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_to(t_data **src, t_data **dst)
{
	t_data	*temp;

	if (*src == NULL || *dst == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pb(t_data **stack_a, t_data **stack_b, int flag)
{
	push_to(stack_a, stack_b);
	if (flag == 0)
		write(1, "pb\n", 3);
}

void	pa(t_data **stack_a, t_data **stack_b, int flag)
{
	push_to(stack_b, stack_a);
	if (flag == 0)
		write(1, "pa\n", 3);
}
