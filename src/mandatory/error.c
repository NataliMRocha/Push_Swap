/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:08:47 by natali            #+#    #+#             */
/*   Updated: 2024/01/07 13:49:03 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_failure(int i)
{
	ft_printf("Error\n");
	exit(i);
}

void free_list(t_data *stack)
{
	t_data *temp;
	
	temp = NULL;
	while(stack->next)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	free(stack);
	return(EXIT_SUCCESS);
}
