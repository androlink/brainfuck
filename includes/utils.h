/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:29:32 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 08:50:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "arr.h"
#include "brainfuck.h"

int	load_file(char	*file, t_array	*arr);
int	parse(t_array *arr, t_program *program);
int	run(t_program *program);

#endif