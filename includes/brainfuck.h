/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:33:20 by gcros             #+#    #+#             */
/*   Updated: 2025/07/28 21:06:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_H
#define BRAINFUCK_H

/*
	https://en.wikipedia.org/wiki/Brainfuck
*/

#include "operator.h"
#include <stddef.h>

typedef unsigned char t_byte;

typedef struct s_brainfuck
{
	t_byte *stack;
	size_t stack_size;
	size_t sp;
	t_operator *program;
	size_t program_size;
	size_t pc;
	int running;
} t_brainfuck;

int bf_init(t_brainfuck *this, size_t stack_size, const char *program);
t_brainfuck *bf_new(size_t stack_size, const char *program);
int bf_parse(t_brainfuck *this, const char *program);

void bf_dump_program(t_brainfuck *this);
void bf_print_instruction(t_operator *op);

void bf_destroy(t_brainfuck *this);
void bf_delete(t_brainfuck *this);

void bf_next(t_brainfuck *this);
void bf_next_n(t_brainfuck *this, size_t n);

#endif