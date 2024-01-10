/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_allocate_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:04:10 by natali            #+#    #+#             */
/*   Updated: 2024/01/10 13:23:03 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(char *argv[], int argc)
{
	int	i;
	int	j;

	if (argc < 3)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[++i])
	{
		if (!isnum(argv[i]) || (ft_atoi(argv[i]) > INT_MAX
				|| ft_atoi(argv[i]) < INT_MIN))
			exit_failure(1);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				exit_failure(1);
			j++;
		}
	}
}

t_data *allocate_stack(t_data *stack_a, char *argv[])
{
	int		i;
	int		j;
	t_data	*new;

	i = 0;
	j = 0;
	while (argv[++j])
	{
		new = new_node(ft_atoi(argv[j]), i);
		add_node_back(&stack_a, new);
		i++;
	}
	return(stack_a);
}