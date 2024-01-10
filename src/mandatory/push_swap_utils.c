/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:02:57 by natali            #+#    #+#             */
/*   Updated: 2024/01/08 18:52:34 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *get_max(t_data *stack)
{
    int max;
    t_data *temp;

    max = INT_MIN;
    temp = stack;
    while(stack)
    {
        if(max < stack->nb)
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