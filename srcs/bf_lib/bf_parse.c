/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:32:20 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 18:17:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck_int.h"

#include <stdlib.h>
#include <unistd.h>

static ssize_t	req_parse(t_brainfuck *this,
					const char *program, int loop_level);
static size_t	_parse_(t_brainfuck *this, const char *program);
static ssize_t	_parse_loop(t_brainfuck *this,
					const char *program, int loop_level);

int	bf_parse(t_brainfuck *this, const char *program)
{
	this->program = malloc(bf_strlen(program) * sizeof(*this->program));
	if (this->program == NULL)
		return (1);
	this->program_size = 0;
	if (req_parse(this, program, 0) == -1)
	{
		free(this->program);
		return (1);
	}
	return (0);
}

static ssize_t	req_parse(t_brainfuck *this,
	const char *program, int loop_level)
{
	ssize_t	ret;
	ssize_t	count;

	count = 0;
	while (program[count])
	{
		if (program[count] == TX_LOOP)
			ret = _parse_loop(this, program + count, loop_level);
		else if (program[count] == TX_END)
		{
			if (loop_level == 0)
				return (-1);
			return (count);
		}
		else
			ret = _parse_(this, program + count);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (loop_level > 0)
		return (-1);
	return (count);
}

static ssize_t	_parse_loop(t_brainfuck *this,
	const char *program, int loop_level)
{
	size_t	loop_save;
	ssize_t	count;

	loop_save = this->program_size;
	this->program_size++;
	this->program[loop_save].op = op_loop;
	count = req_parse(this, program + 1, loop_level + 1);
	if (count == -1)
		return (count);
	this->program[loop_save].value = this->program_size;
	this->program[this->program_size] = (t_operator){
		.op = op_end, .value = loop_save};
	this->program_size++;
	count += 2;
	return (count);
}

static size_t	_parse_(t_brainfuck *this, const char *program)
{
	t_op	op;

	op = op_none;
	if (*program == TX_LE)
		op = op_le;
	else if (*program == TX_RI)
		op = op_ri;
	else if (*program == TX_ADD)
		op = op_add;
	else if (*program == TX_SUB)
		op = op_sub;
	else if (*program == TX_RD)
		op = op_rd;
	else if (*program == TX_WR)
		op = op_wr;
	if (op == op_none)
		return (1);
	if (this->program_size != 0
		&& op == this->program[this->program_size - 1].op)
		this->program[this->program_size - 1].value++;
	else
		this->program[this->program_size++] = (t_operator){
			.op = op, .value = 1};
	return (1);
}
