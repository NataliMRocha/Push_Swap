/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:19:31 by natali            #+#    #+#             */
/*   Updated: 2023/11/29 14:47:26 by natali           ###   ########.fr       */
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

void	allocate_stack(char *argv[]);
int		exit_failure(int i, const char *str);
t_data	*get_last_node(t_data *lst);
void	add_node_back(t_data **lst, t_data *new);
t_data	*new_node(int nb, int pos);
int		isnum(char *argv);
void	check_args(char *argv[], int argc);

#endif
