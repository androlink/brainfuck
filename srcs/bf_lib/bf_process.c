/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:46:08 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 17:58:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	_process_(t_brainfuck *this, const t_operator *nc);
static void	_process_oper(t_brainfuck *this, const t_operator *nc);
t_byte		_bf_read_(void);

void	bf_next(t_brainfuck *this)
{
	if (!this->running || this->pc >= this->program_size)
	{
		this->running = 0;
		return ;
	}
	_process_(this, &this->program[this->pc]);
}

void	bf_next_n(t_brainfuck *this, size_t n)
{
	size_t	loop_count;

	loop_count = 0;
	while (this->running && loop_count++ < n)
		bf_next(this);
}

static void	_process_(t_brainfuck *this, const t_operator *nc)
{
	if (nc->op == op_loop)
	{
		if (this->stack[this->sp])
			this->pc++;
		else
			this->pc = nc->value + 1;
	}
	else if (nc->op == op_end)
	{
		this->pc = nc->value;
	}
	else
	{
		_process_oper(this, nc);
		this->pc++;
	}
}

static void	_process_oper(t_brainfuck *this, const t_operator *nc)
{
	size_t	loop_count;

	loop_count = 0;
	if (nc->op == op_add)
		this->stack[this->sp] += nc->value;
	else if (nc->op == op_sub)
		this->stack[this->sp] -= nc->value;
	else if (nc->op == op_le)
	{
		if (this->sp < nc->value)
			this->sp += this->stack_size;
		this->sp -= nc->value;
	}
	else if (nc->op == op_ri)
	{
		this->sp += nc->value;
		if (this->sp >= this->stack_size)
			this->sp -= this->stack_size;
	}
	else if (nc->op == op_rd)
		while (loop_count++ < nc->value)
			this->stack[this->sp] = _bf_read_();
	else if (nc->op == op_wr)
		while (loop_count++ < nc->value)
			write(1, &this->stack[this->sp], 1);
}

t_byte	_bf_read_(void)
{
	t_byte	rv;

	if (read(0, &rv, 1) <= 0)
	{
		rv = 0;
	}
	return (rv);
}
