/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:33:20 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 18:01:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_H
# define BRAINFUCK_H

/*
	https://en.wikipedia.org/wiki/Brainfuck
*/

# include <stddef.h>

typedef void	t_brainfuck;

int			bf_init(t_brainfuck *this, size_t stack_size, const char *program);
t_brainfuck	*bf_new(size_t stack_size, const char *program);

void		bf_destroy(t_brainfuck *this);
void		bf_delete(t_brainfuck *this);

void		bf_next(t_brainfuck *this);
void		bf_next_n(t_brainfuck *this, size_t n);

#endif