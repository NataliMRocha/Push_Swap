/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:24:29 by namoreir          #+#    #+#             */
/*   Updated: 2024/01/23 15:21:57 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	validate_instructions(char *move)
{
	char	*instructions;

	instructions = "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n";
	if (!move)
		return ;
	if (!ft_strnstr(instructions, move, ft_strlen(instructions)))
		exit_failure(1);
}

void	choose_move(char *move, t_data **stack_a, t_data **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(stack_a, 1);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(stack_b, 1);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(stack_b, stack_a, 1);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		choose_r(1, stack_a, NULL, 1);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		choose_r(2, NULL, stack_b, 1);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		choose_r(3, stack_a, stack_b, 1);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		choose_rr(1, stack_a, NULL, 1);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		choose_rr(2, NULL, stack_b, 1);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		choose_rr(3, stack_a, stack_b, 1);
}

int	check_stack(t_data **stack_a, t_data **stack_b)
{
	if (!is_in_order(*stack_a))
	{
		write(1, "KO", 2);
		return (free_list(*stack_a));
	}
	else
		write(1, "OK", 2);
	if (stack_b)
		free_list(*stack_b);
	free_list(*stack_a);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data	*stack_a;
	t_data	*stack_b;
	char	*move;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argv, argc);
	stack_a = allocate_stack(stack_a, argv);
	move = "";
	while (move)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		validate_instructions(move);
		choose_move(move, &stack_a, &stack_b);
		free(move);
	}
	return (check_stack(&stack_a, &stack_b));
}
