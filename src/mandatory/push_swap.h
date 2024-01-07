/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:19:31 by natali            #+#    #+#             */
/*   Updated: 2024/01/07 16:26:19 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../libft/libft.h"

typedef struct s_data	t_data;
struct s_data{
	int		nb;
	int		pos_curr;
	int		pos_lst;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	t_data	*next;
};

t_data	*allocate_stack(t_data *stack_a, char *argv[]);
int		exit_failure(int i);
t_data	*get_last_node(t_data *lst);
void	add_node_back(t_data **lst, t_data *new);
t_data	*new_node(int nb, int pos);
int		isnum(char *argv);
void	check_args(char *argv[], int argc);
void	bubble_sort_argv(char *argv[]);

#endif
