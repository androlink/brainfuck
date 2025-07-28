/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain_fuck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:42:47 by gcros             #+#    #+#             */
/*   Updated: 2025/07/28 23:20:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

#include "utils.h"
#include <stdlib.h>

int bf_init(t_brainfuck *this, size_t stack_size, const char *program)
{
	this->stack = malloc(stack_size * sizeof(*this->stack));
	if (this->stack == NULL)
		return 1;
	bf_bzero(this->stack, stack_size * sizeof(*this->stack));
	if (bf_parse(this, program)) {
		free(this->stack);
		return 1;
	}
	this->stack_size = stack_size;
	this->running = 1;
	return 0;
}

t_brainfuck *bf_new(size_t stack_size, const char *program)
{
	t_brainfuck *bf;

	bf = malloc(sizeof(*bf));
	if (bf != NULL && bf_init(bf, stack_size, program)) {
		free(bf);
		bf = NULL;
	}
	return bf;
}

void bf_destroy(t_brainfuck *this)
{
	free(this->stack);
	free(this->program);
}

void bf_delete(t_brainfuck *this)
{
	bf_destroy(this);
	free(this);
}
