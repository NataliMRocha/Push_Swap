/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:40:30 by namoreir          #+#    #+#             */
/*   Updated: 2024/01/12 15:32:26 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void send_to_a(t_data **stack_a, t_data **stack_b)
{
	t_data	*move;

	while(*stack_b)
	{
		find_target_pos_in_a(stack_a, stack_b, get_max(*stack_a), get_min(*stack_a));
		move = finding_min_cost(*stack_b);
		if(move->cost_a != move->cost_b)
		{
			if (move->cost_a < 0)
				choose_rrr(1, stack_a, NULL);
			if (move->cost_a > 0)
				choose_r(1, stack_a, NULL);
			if (move->cost_b < 0)
				choose_rrr(2, stack_b, NULL);
			if (move->cost_b > 0)
				choose_r(2, stack_a, NULL);
		}
		else
			choose_r(3, stack_a, stack_a);
		if ((*stack_b)->pos_lst == (*stack_a)->pos_lst && total_cost(*stack_b) == 0)
			pa(stack_a, stack_b);
		*stack_b = (*stack_b)->next;
	}
	find_pos_curr(*stack_a);
	printf_stack(*stack_a, 'a');
	printf_stack(*stack_b, 'b');
}

int	send_to_b(t_data **stack_a, t_data **stack_b, int len)
{
	int half_stack;

	half_stack = len / 2;
	while(len > 3 && len > half_stack + 1)
    {
        if ((*stack_a)->pos_lst <= half_stack)
        {
            pb(stack_a, stack_b);
            len--;
        }
        else
            choose_r(1, stack_a, NULL);
    }
	return(len);
}
