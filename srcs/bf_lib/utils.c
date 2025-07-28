/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:33:14 by gcros             #+#    #+#             */
/*   Updated: 2025/07/28 21:00:22 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t bf_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count])
		count++;
	return count;
}

void bf_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n) {
		((char *)s)[i] = '\0';
		i++;
	}
	return;
}