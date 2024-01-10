/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:02:57 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 15:15:07 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *get_max(t_data *stack)
{
    int max;
    t_data *temp;

    max = stack->nb;
    temp = stack;
    while(stack)
    {
        if(stack->nb > max)
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

int stack_len(t_data *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        stack = stack->next;
        i++;
    }
    return(i);
}

void printf_stack(t_data *stack, char c)
{
	printf("stack %c\n", c);
	while(stack)
	{
		printf("nb: %d | ", stack->nb);
        printf("pos_curr: %d | ", stack->pos_curr);
		printf("pos_lst: %d | ", stack->pos_lst);
        printf("target_pos_a: %d | ", stack->target_pos_a);
        printf("cost_a: %d | ", stack->cost_a);
        printf("cost_b: %d\n", stack->cost_b);
		stack = stack->next;
	}
}