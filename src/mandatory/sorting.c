/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:13:25 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 13:27:19 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting(t_data **stack_a, t_data **stack_b)
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
            printf_stack(*stack_a, 'a');
	        printf_stack(*stack_b, 'b');
        }
        else
        {   choose_r(1, stack_a, NULL);
            printf_stack(*stack_a, 'a');
	        printf_stack(*stack_b, 'b');
        }
    }
    
}

void pb(t_data **stack_a, t_data **stack_b)
{
    send_to(stack_a, stack_b);
    write(1, "pb\n", 3);    
}

void pa(t_data **stack_a, t_data **stack_b)
{
    send_to(stack_b, stack_a);
    write(1, "pa\n", 3);    
}

void send_to(t_data **src, t_data **dst)
{
    t_data *temp;

    temp = *src;
    temp->next = NULL;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
}