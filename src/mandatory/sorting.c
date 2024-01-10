/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:13:25 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 16:16:34 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_data **stack_a, t_data **stack_b)
{
    int len;
    int half_stack;

    len = stack_len(*stack_a);
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
    while (len-- > 3)
        pb(stack_a, stack_b);
    sort_3(stack_a);
    finding_pos_curr(stack_a);
    finding_pos_curr(stack_b);
    finding_target_pos_in_a(stack_a, stack_b, stack_len(*stack_b));
    printf_stack(*stack_a, 'a');
	printf_stack(*stack_b, 'b');
}

void finding_pos_curr(t_data **stack)
{
    t_data *temp;
    int i;

    temp = *stack;
    i = 0;
    while(temp)
    {
        temp->pos_curr = i;
        temp = temp->next;
        i++;
    }
}

void finding_target_pos_in_a(t_data **stack_a, t_data **stack_b, int len)
{
    t_data  *temp_a;
    t_data  *temp_b;

    temp_b = *stack_b;
    while(temp_b)
    {
        temp_a = *stack_a;
        temp_b->target_pos_a = len;
        while(temp_a)
        {
            if (temp_b->pos_lst < temp_a->pos_lst && temp_b->target_pos_a >= temp_a->pos_lst)
                temp_b->target_pos_a = temp_a->pos_curr;
            temp_a = temp_a->next;
        }
        temp_b = temp_b->next;
    }
    
}