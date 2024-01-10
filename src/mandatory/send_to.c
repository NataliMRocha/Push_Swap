/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:16 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 15:18:38 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void send_to(t_data **src, t_data **dst)
{
    t_data *temp;

    temp = *src;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
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
