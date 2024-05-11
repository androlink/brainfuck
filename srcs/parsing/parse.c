/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:30:33 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 08:25:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include "utils.h"

int	parse_line(char	*line, t_program *program, size_t *j);
int	get_program(t_array *arr, t_program *program);

int	parse(t_array *arr, t_program *program)
{
	if (get_program(arr, program) == 1)
		return (1);
	return (0);
}

int	get_program(t_array *arr, t_program *program)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < arr->size)
	{
		if (parse_line(arr->data[i], program, &j) == 1)
			return (1);
		i++;
	}
	program->program_len = j;
	return (0);
}

int	parse_line(char	*line, t_program *program, size_t *j)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == TX_ADD)
			program->program[*j] = (t_operator){.op = op_add};
		else if (line[i] == TX_SUB)
			program->program[*j] = (t_operator){.op = op_sub};
		else if (line[i] == TX_RI)
			program->program[*j] = (t_operator){.op = op_ri};
		else if (line[i] == TX_LE)
			program->program[*j] = (t_operator){.op = op_le};
		else if (line[i] == TX_IF)
			program->program[*j] = (t_operator){.op = op_if};
		else if (line[i] == TX_FI)
			program->program[*j] = (t_operator){.op = op_fi};
		else if (line[i] == TX_RD)
			program->program[*j] = (t_operator){.op = op_rd};
		else if (line[i] == TX_WR)
			program->program[*j] = (t_operator){.op = op_wr};
		if (++*j == PROGRAM_SIZE)
			return (1);
		i++;
	}
	return (0);
}
