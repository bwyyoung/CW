/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 16:15:25 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		input_delete_redundancy(t_push_swap *ps)
{
	SAFE_DELETE(ps->op_list->bottom->op);
	if (!ps->op_list->next)
	{
		SAFE_DELETE(ps->op_list);
		return (false);
	}
	ps->op_list->bottom = ps->op_list->bottom->prev;
	SAFE_DELETE(ps->op_list->bottom->next);
	return (false);
}

t_bool	bottom_is_rotate(t_push_swap *ps)
{
	if (!ft_strcmp(ps->op_list->bottom->op, OP_RA) ||
		!ft_strcmp(ps->op_list->bottom->op, OP_RRA) ||
		!ft_strcmp(ps->op_list->bottom->op, OP_RRB) ||
		!ft_strcmp(ps->op_list->bottom->op, OP_RB))
		return (true);
	return (false);
}

int		input_rotate_recurring(t_push_swap *ps, char *op)
{
	if (!ps->op_list || ps->check_mode)
		return (1);
	if (ft_strcmp(ps->op_list->bottom->op, op))
	{
		if ((bottom_is_rotate(ps)) && ((ps->num_elements_a -
		ps->op_list->bottom->num) < ps->op_list->bottom->num))
		{
			ps->m = ps->num_elements_a;
			if (!ft_strcmp(ps->op_list->bottom->op, OP_RRA))
				while (ps->m-- > 0)
					input_op(ps, OP_RA);
			else if (!ft_strcmp(ps->op_list->bottom->op, OP_RA))
				while (ps->m-- > 0)
					input_op(ps, OP_RRA);
		}
		return (1);
	}
	if (bottom_is_rotate(ps))
		return (ps->op_list->bottom->num + 1);
	return (1);
}