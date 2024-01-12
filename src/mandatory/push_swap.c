/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:05 by natali            #+#    #+#             */
/*   Updated: 2024/01/12 17:26:23 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_data **stack_a)
{
	t_data	*max;

	max = get_max(*stack_a);
	if ((*stack_a)->nb == max->nb)
		choose_r(1, stack_a, NULL);
	else if ((*stack_a)->next->nb == max->nb)
		choose_rrr(1, stack_a, NULL);
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		sa(stack_a);
}

void	push_swap(t_data **stack_a, t_data **stack_b)
{
	int		len;
	int		top_of_list;
	t_data	*temp;

	len = send_to_b(stack_a, stack_b, stack_len(*stack_a));
	while (len-- > 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	send_to_a(stack_a, stack_b);
	len = stack_len(*stack_a) / 2;
	temp = *stack_a;
	while (temp)
	{
		if (temp->pos_lst == 1)
			top_of_list = temp->pos_curr;
		temp = temp->next;
	}
	while ((*stack_a)->pos_lst != 1)
	{
		if (top_of_list <= len)
			choose_r(1, stack_a, NULL);
		else
			choose_rrr(1, stack_a, NULL);
	}
}

int	main(int argc, char *argv[])
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argv, argc);
	stack_a = allocate_stack(stack_a, argv);
	if (is_in_order(stack_a))
		return (free_list(stack_a));
	bubble_sort_argv(argv);
	set_index(argv, stack_a);
	if (argc == 3)
		sa(&stack_a);
	else if (argc == 4)
		sort_3(&stack_a);
	else
		push_swap(&stack_a, &stack_b);
	return (free_list(stack_a));
}
