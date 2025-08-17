/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:38 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 17:43:07 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_INT_H
# define BRAINFUCK_INT_H

/*
	https://en.wikipedia.org/wiki/Brainfuck
*/

# include <stddef.h>

typedef enum e_op
{
	op_add,
	op_sub,
	op_ri,
	op_le,
	op_loop,
	op_end,
	op_rd,
	op_wr,
	op_none
}	t_op;

# define TX_ADD	'+'
# define TX_SUB	'-'
# define TX_RI	'>'
# define TX_LE	'<'
# define TX_LOOP	'['
# define TX_END	']'
# define TX_RD	','
# define TX_WR	'.'

typedef struct s_if
{
	size_t	endif;
}	t_if;

typedef struct s_fi
{
	size_t	startif;
}	t_fi;

typedef struct s_operator
{
	size_t	value;
	t_op	op;
}	t_operator;

typedef unsigned char	t_byte;

typedef struct s_brainfuck
{
	t_byte		*stack;
	size_t		stack_size;
	size_t		sp;
	t_operator	*program;
	size_t		program_size;
	size_t		pc;
	int			running;
}	t_brainfuck;

int			bf_init(t_brainfuck *self, size_t stack_size, const char *program);
t_brainfuck	*bf_new(size_t stack_size, const char *program);
int			bf_parse(t_brainfuck *self, const char *program);

void		bf_dump_program(t_brainfuck *self);
void		bf_print_instruction(t_operator *op);

void		bf_destroy(t_brainfuck *self);
void		bf_delete(t_brainfuck *self);

void		bf_next(t_brainfuck *self);
void		bf_next_n(t_brainfuck *self, size_t n);

size_t		bf_strlen(const char *str);
void		bf_bzero(void *s, size_t n);

#endif