/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:13:25 by natali            #+#    #+#             */
/*   Updated: 2024/01/23 15:21:32 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_pos_curr(t_data **stack)
{
	t_data	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos_curr = i;
		temp = temp->next;
		i++;
	}
}

void	find_target_pos_in_a(t_data **stack_a, t_data **stack_b, t_data *max_nb,
		t_data *min_nb)
{
	t_data	*temp_a;
	t_data	*temp_b;
	int		i;

	temp_b = *stack_b;
	find_pos_curr(stack_a);
	while (temp_b)
	{
		temp_a = *stack_a;
		i = stack_len(*stack_a) + stack_len(*stack_b);
		while (temp_a)
		{
			if (temp_b->pos_lst < temp_a->pos_lst && temp_a->pos_lst <= i)
			{
				temp_b->target_pos_a = temp_a->pos_curr;
				i = temp_a->pos_lst;
			}
			if (temp_b->pos_lst > max_nb->pos_lst)
				temp_b->target_pos_a = min_nb->pos_curr;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
	find_cost(*stack_a, *stack_b);
}

void	find_cost(t_data *stack_a, t_data *stack_b)
{
	int		len_a;
	int		len_b;
	t_data	*temp;

	find_pos_curr(&stack_b);
	find_pos_curr(&stack_a);
	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		calculate_cost(&stack_b, len_b, 'b', stack_b->pos_curr);
		temp = stack_a;
		while (temp)
		{
			if (stack_b->target_pos_a == temp->pos_curr)
				calculate_cost(&stack_b, len_a, 'a', temp->pos_curr);
			temp = temp->next;
		}
		stack_b = stack_b->next;
	}
}

void	calculate_cost(t_data **stack, int len, char c, int pos_curr)
{
	if (*stack == NULL)
		return ;
	if (pos_curr <= (len / 2))
	{
		if (c == 'a')
			(*stack)->cost_a = pos_curr;
		else
			(*stack)->cost_b = pos_curr;
	}
	else
	{
		if (c == 'a')
			(*stack)->cost_a = pos_curr - len;
		else
			(*stack)->cost_b = pos_curr - len;
	}
}

t_data	*finding_min_cost(t_data *stack_b)
{
	int		min_cost;
	t_data	*temp;

	min_cost = INT_MAX;
	temp = stack_b;
	while (temp)
	{
		if (min_cost > total_cost(temp))
			min_cost = total_cost(temp);
		temp = temp->next;
	}
	while (stack_b)
	{
		if (total_cost(stack_b) == min_cost)
			return (stack_b);
		stack_b = stack_b->next;
	}
	return (NULL);
}
