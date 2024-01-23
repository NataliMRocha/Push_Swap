/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:19:31 by natali            #+#    #+#             */
/*   Updated: 2024/01/19 22:14:32 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data	t_data;
struct					s_data
{
	int					nb;
	int					pos_curr;
	int					pos_lst;
	int					target_pos_a;
	int					cost_a;
	int					cost_b;
	t_data				*next;
};

void					set_index(char *argv[], t_data *stack_a);
t_data					*allocate_stack(t_data *stack_a, char *argv[]);
int						exit_failure(int i);
t_data					*get_last_node(t_data *lst);
void					add_node_back(t_data **lst, t_data *new);
t_data					*new_node(int nb, int pos);
int						isnum(char *argv);
void					check_args(char *argv[], int argc);
void					bubble_sort_argv(char *argv[]);
int						free_list(t_data *stack);
void					rotate(t_data **stack);
void					reverse_rotate(t_data **stack);
void					choose_r(int flag, t_data **stack_a, t_data **stack_b,
							int check);
void					choose_rr(int flag, t_data **stack_a, t_data **stack_b,
							int check);
void					swap(t_data **stack);
void					sa(t_data **stack_a, int flag);
void					sb(t_data **stack_b, int flag);
void					ss(t_data **stack_a, t_data **stack_b, int flag);
t_data					*get_max(t_data *stack);
t_data					*get_min(t_data *stack);
void					sort_3(t_data **stack_a);
int						stack_len(t_data *stack);
void					push_swap(t_data **stack_a, t_data **stack_b);
void					pb(t_data **stack_a, t_data **stack_b, int flag);
void					pa(t_data **stack_a, t_data **stack_b, int flag);
void					push_to(t_data **src, t_data **dst);
void					find_pos_curr(t_data **stack);
void					find_target_pos_in_a(t_data **stack_a, t_data **stack_b,
							t_data *max_nb, t_data *min_nb);
void					find_cost(t_data *stack_a, t_data *stack_b);
void					send_to_a(t_data **stack_a, t_data **stack_b);
void					calculate_cost(t_data **stack, int len, char c,
							int pos_curr);
int						is_in_order(t_data *stack_a);
int						total_cost(t_data *stack_b);
int						send_to_b(t_data **stack_a, t_data **stack_b, int len);
t_data					*finding_min_cost(t_data *stack_b);

#endif
