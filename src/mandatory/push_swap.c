/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:05 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 14:55:03 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort_argv(char *argv[])
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while(argv[j])
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_in_order(t_data *stack_a)
{
	while(stack_a->next)
	{
		if(stack_a->nb > stack_a->next->nb)
			return(0);
		stack_a = stack_a->next;
	}
	return(1);
}

void	set_index(char *argv[], t_data *stack_a)
{
	int	i;
	t_data *temp;

	i = 0;
	temp = stack_a;
	while(argv[i] && temp)
	{
		if(ft_atoi(argv[i]) == temp->nb)
		{
			temp->pos_lst = i;
			temp = temp->next;
			i = -1;
		}
		i++;
	}
}

void	sort_3(t_data **stack_a)
{
	t_data *max;

	max = get_max(*stack_a);
	if ((*stack_a)->nb == max->nb)
		choose_r(1, stack_a, NULL);
	else if ((*stack_a)->next->nb == max->nb)
		choose_rrr(1, stack_a, NULL);
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		sa(stack_a);
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
		return(free_list(stack_a));
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
