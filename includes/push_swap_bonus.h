/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:44:28 by namoreir          #+#    #+#             */
/*   Updated: 2024/01/19 22:13:56 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

void	validate_instructions(char *move);
void	choose_move(char *move, t_data **stack_a, t_data **stack_b);
int		check_stack(t_data **stack_a, t_data **stack_b);

#endif