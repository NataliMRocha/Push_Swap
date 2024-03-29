/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:08:47 by natali            #+#    #+#             */
/*   Updated: 2024/01/23 15:21:28 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exit_failure(int i)
{
	ft_printf("Error\n");
	exit(i);
}

int	free_list(t_data *stack)
{
	t_data	*temp;

	temp = NULL;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	free(stack);
	return (EXIT_SUCCESS);
}
