/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:04:05 by natali            #+#    #+#             */
/*   Updated: 2024/01/23 15:25:36 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_data **stack)
{
	t_data	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_data **stack_a, int flag)
{
	swap(stack_a);
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_data **stack_b, int flag)
{
	swap(stack_b);
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_data **stack_a, t_data **stack_b, int flag)
{
	swap(stack_b);
	swap(stack_a);
	if (flag == 0)
		write(1, "ss\n", 3);
}
