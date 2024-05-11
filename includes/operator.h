/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:39:44 by gcros             #+#    #+#             */
/*   Updated: 2024/05/11 07:54:12 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include <stddef.h>

typedef enum e_op
{
	op_add,
	op_sub,
	op_ri,
	op_le,
	op_if,
	op_fi,
	op_rd,
	op_wr,
}	t_op;

# define TX_ADD '+'
# define TX_SUB '-'
# define TX_RI '>'
# define TX_LE '<'
# define TX_IF '['
# define TX_FI ']'
# define TX_RD ','
# define TX_WR '.'


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
	t_op	op;
	union
	{
		t_if	_if;
		t_fi	_fi;
	};
}	t_operator;

#endif