/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:23:00 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 08:54:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "get_next_line.h"
#include <fcntl.h>

int	read_file(int fd, t_array *arr);

int	load_file(char	*file, t_array	*arr)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	read_file(fd, arr);
	close(fd);
	return (0);
}

int	read_file(int fd, t_array *arr)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		ft_arr_append(arr, str);
		str = get_next_line(fd);
	}
	return (0);
}
