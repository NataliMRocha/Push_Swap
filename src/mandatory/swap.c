/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:04:05 by natali            #+#    #+#             */
/*   Updated: 2024/01/07 13:17:54 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_data *stack_a)
{
    t_data *temp;

    temp = stack_a->nb;
    stack_a->nb = stack_a->next->nb;
    stack_a->next->nb = temp;
    write(1, "sa\n", 3);
}

void swap_b(t_data *stack_b)
{
    t_data *temp;

    temp = stack_b->nb;
    stack_b->nb = stack_b->next->nb;
    stack_b->next->nb = temp;
    write(1, "sb\n", 3);
}