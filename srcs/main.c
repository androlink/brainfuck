/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:28:33 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 09:48:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include "put.h"
#include "arr.h"
#include "utils.h"
#include "ft_printf.h"

int	bf_exit(int	err);
int	init_program(t_program *program, char *file);

int	main(int ac, char **av)
{
	t_program	program;

	if (ac != 2)
		return (bf_exit(1));
	if (init_program(&program, av[1]))
		return (bf_exit(2));
	run(&program);
	//ft_printf("%x\n", *(unsigned int *)program.stack);
	return (bf_exit(0));
}

int	init_program(t_program *program, char *file)
{
	t_array	*arr;

	ft_bzero(program, sizeof(t_program));
	arr = ft_arr_new(50);
	if (arr == NULL)
		return (1);
	if (load_file(file, arr) == 1)
		return (ft_arr_free(&arr, free), 1);
	if (parse(arr, program) == 1)
		return (ft_arr_free(&arr, free), 1);
	ft_arr_free(&arr, free);
	return (0);
}

int	bf_exit(int	err)
{
	if (err == 0)
		ft_putendl_fd("okay", 2);
	if (err == 1)
		ft_putendl_fd("no input file", 2);
	if (err == 2)
		ft_putendl_fd("idk", 2);
	return (err);
}