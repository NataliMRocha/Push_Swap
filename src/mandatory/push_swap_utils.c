/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:02:57 by natali            #+#    #+#             */
/*   Updated: 2024/01/23 15:21:38 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_data	*get_max(t_data *stack)
{
	int		max;
	t_data	*temp;

	max = stack->nb;
	temp = stack;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->nb == max)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_data	*get_min(t_data *stack)
{
	int		min;
	t_data	*temp;

	min = stack->nb;
	temp = stack;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->nb == min)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	stack_len(t_data *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_in_order(t_data *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
