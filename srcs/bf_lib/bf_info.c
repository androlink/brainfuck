/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:53:02 by gcros             #+#    #+#             */
/*   Updated: 2025/07/28 23:22:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include <stdio.h>

void bf_dump_program(t_brainfuck *this)
{
	char *status[] = {"stoped", "running"};
	size_t count;

	count = 0;
	printf("status: %s\n", status[this->running != 0]);
	printf("pc: %zu\n", this->pc);
	printf("sp: %zu\n", this->sp);
	while (count < this->program_size) {
		bf_print_instruction(&this->program[count]);
		count++;
	}
}

void bf_print_instruction(t_operator *op)
{
	static char *op_str[] = {
		[op_add] = "add", [op_sub] = "sub",	 [op_rd] = "read",	 [op_wr] = "write",
		[op_le] = "left", [op_ri] = "right", [op_loop] = "loop", [op_end] = "end"};

	printf("%s: %zu\n", op_str[op->op], op->value);
}
