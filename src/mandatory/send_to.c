/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:40:30 by namoreir          #+#    #+#             */
/*   Updated: 2024/01/23 15:21:48 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	send_to_a(t_data **stack_a, t_data **stack_b)
{
	t_data	*move;

	while (*stack_b)
	{
		find_target_pos_in_a(stack_a, stack_b, get_max(*stack_a),
			get_min(*stack_a));
		move = finding_min_cost(*stack_b);
		if (move->cost_a != move->cost_b)
		{
			if (move->cost_a < 0)
				choose_rr(1, stack_a, NULL, 0);
			if (move->cost_a > 0)
				choose_r(1, stack_a, NULL, 0);
			if (move->cost_b < 0)
				choose_rr(2, NULL, stack_b, 0);
			if (move->cost_b > 0)
				choose_r(2, NULL, stack_b, 0);
		}
		else if (move->cost_b != 0)
			choose_r(3, stack_a, stack_b, 0);
		if ((*stack_b)->pos_lst == move->pos_lst && total_cost(*stack_b) == 0)
			pa(stack_a, stack_b, 0);
	}
	find_pos_curr(stack_a);
}

int	send_to_b(t_data **stack_a, t_data **stack_b, int len)
{
	int	half_stack;

	half_stack = len / 2;
	while (len > 3 && len > half_stack + 1)
	{
		if ((*stack_a)->pos_lst <= half_stack)
		{
			pb(stack_a, stack_b, 0);
			len--;
		}
		else
			choose_r(1, stack_a, NULL, 0);
	}
	return (len);
}

int	total_cost(t_data *stack_b)
{
	int	total_cost;

	total_cost = (abs(stack_b->cost_a)) + (abs(stack_b->cost_b));
	return (total_cost);
}
