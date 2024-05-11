/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 08:31:23 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 10:30:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include <unistd.h>
#include "put.h"

int	run_fi(t_program *program);
int	run_op(t_program *program);
int	run_if(t_program *program);

int	run(t_program *program)
{
	while (program->pcb.thread[0].pc < program->program_len)
	{
		run_op(program);
	}
	return (0);
}

int	run_op(t_program *program)
{
	if (program->program[program->pcb.thread[0].pc].op == op_add)
		program->stack[program->pcb.thread[0].sp]++;
	else if (program->program[program->pcb.thread[0].pc].op == op_sub)
		program->stack[program->pcb.thread[0].sp]--;
	else if (program->program[program->pcb.thread[0].pc].op == op_le)
		program->pcb.thread[0].sp--;
	else if (program->program[program->pcb.thread[0].pc].op == op_ri)
		program->pcb.thread[0].sp++;
	else if (program->program[program->pcb.thread[0].pc].op == op_rd)
		read(0, &program->stack[program->pcb.thread[0].sp], 1);
	else if (program->program[program->pcb.thread[0].pc].op == op_wr)
		write(1, &program->stack[program->pcb.thread[0].sp], 1);
	else if (program->program[program->pcb.thread[0].pc].op == op_if)
		run_if(program);
	else if (program->program[program->pcb.thread[0].pc].op == op_fi)
		run_fi(program);
	program->pcb.thread[0].pc++;
	return (0);
}

int	run_if(t_program *program)
{
	size_t	depth;
	//ft_putendl_fd("==if==", 2);
	if (program->stack[program->pcb.thread[0].sp] != 0)
		return (0);
	depth = 1;
	while (depth)
	{
		program->pcb.thread[0].pc++;
		if (program->program[program->pcb.thread[0].pc].op == op_if)
			depth++;
		else if (program->program[program->pcb.thread[0].pc].op == op_fi)
			depth--;
		if (program->pcb.thread[0].pc >= PROGRAM_SIZE)
			return (1);
	}
	return (0);
}

int	run_fi(t_program *program)
{
	size_t	depth;

	depth = 1;
	program->pcb.thread[0].pc--;
	while (depth)
	{
		if (program->program[program->pcb.thread[0].pc].op == op_if)
			depth--;
		else if (program->program[program->pcb.thread[0].pc].op == op_fi)
			depth++;
		program->pcb.thread[0].pc--;
		if (program->pcb.thread[0].pc >= PROGRAM_SIZE)
			return (1);
	}
	return (0);
}
