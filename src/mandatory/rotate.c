/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:49:33 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 15:10:18 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_data **stack)
{
    t_data *temp;
    t_data *head;

    head = (*stack)->next;
    temp = *stack;
    while((*stack)->next)
        *stack = (*stack)->next;
    temp->next = NULL;
    (*stack)->next = temp;
    *stack = head;
}

void reverse_rotate(t_data **stack)
{
    t_data  *last_node;
    t_data  *temp;

    temp = *stack;
    last_node = NULL;
    while(temp->next)
    {
        last_node = temp;
        temp = temp->next;
        if(temp == NULL)
            break ;
    }
    temp->next = *stack;
    last_node->next = NULL;
    *stack = temp;
}

void choose_r(int flag, t_data **stack_a, t_data **stack_b)
{
    if (flag == 1)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    if (flag == 2)
    {
        rotate(stack_b);
        write(1, "rb\n", 3);
    }
    if (flag == 3)
    {
        rotate(stack_a);
        rotate(stack_b);
        write(1, "rr\n", 3);
    }
}

void choose_rrr(int flag, t_data **stack_a, t_data **stack_b)
{
    if (flag == 1)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 3);
    }
    if (flag == 2)
    {
        reverse_rotate(stack_b);
        write(1, "rrb\n", 3);
    }
    if (flag == 3)
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        write(1, "rrr\n", 3);
    }
}