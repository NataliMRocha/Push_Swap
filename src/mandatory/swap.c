/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:04:05 by natali            #+#    #+#             */
/*   Updated: 2024/01/12 15:37:04 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data **stack)
{
	t_data	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_data **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_data **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}
