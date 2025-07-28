/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:28:33 by gcros             #+#    #+#             */
/*   Updated: 2025/07/28 23:23:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include <unistd.h>

int main(int ac, char **av)
{
	t_brainfuck bf;

	if (ac != 2) {
		write(2, "missing args\n", 14);
		return 1;
	}
	if (bf_init(&bf, 30000, av[1]) == 1)
		return (1);
	bf_dump_program(&bf);
	bf_next_n(&bf, -1);
	bf_destroy(&bf);
	return (0);
}
