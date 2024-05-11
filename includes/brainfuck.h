/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:33:20 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 10:45:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_H
# define BRAINFUCK_H

/*
	https://en.wikipedia.org/wiki/Brainfuck

	https://en.wikipedia.org/wiki/Code_segment
	https://en.wikipedia.org/wiki/Data_segment
	https://en.wikipedia.org/wiki/Process_control_block
	https://en.wikipedia.org/wiki/Thread_control_block
*/

# include <stddef.h>
# include "operator.h"

# ifndef STACK_SIZE
#  define STACK_SIZE 100000
# endif

# ifndef PROGRAM_SIZE
#  define PROGRAM_SIZE 150000
# endif

# ifndef MAX_THREAD
#  define MAX_THREAD 256
# endif

typedef unsigned char	t_byte;

typedef struct s_tcb
{
	size_t	sp;
	size_t	pc;
}	t_tcb;

typedef struct s_pcb
{
	t_tcb	thread[MAX_THREAD];
	size_t	thread_len;
}	t_pcb;

typedef struct s_program
{
	t_byte		stack[STACK_SIZE];
	t_pcb		pcb;
	t_operator	program[PROGRAM_SIZE];
	size_t		program_len;
}	t_program;



#endif