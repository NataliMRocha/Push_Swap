/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:05 by natali            #+#    #+#             */
/*   Updated: 2023/11/29 14:51:17 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char *argv)
{
	int	i;

	i = 0;
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

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[++i])
	{
		if (!isnum(argv[i]) || (ft_atoi(argv[i]) > INT_MAX
				|| ft_atoi(argv[i]) < INT_MIN))
			exit_failure(i, "Só pode número e do tamanho de um int");
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				exit_failure(i, "Não pode repetir os números ok");
			j++;
		}
	}
}

void	allocate_stack(char *argv[])
{
	int		i;
	int		j;
	t_data	*data;
	t_data	*new;

	data = malloc(sizeof(t_data));
	i = 0;
	j = 0;
	while (argv[++j])
	{
		new = new_node(ft_atoi(argv[j]), i);
		printf("Número: %d Posição: %d\n", new->nb, new->pos_curr);
		add_node_back(&data, new);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	check_args(argv, argc);
	allocate_stack(argv);
}
