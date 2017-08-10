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

t_bool	input_delete_redundancy(t_push_swap *ps)
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
	if (ps->check_mode || !ps->op_list)
		return (1);
	if (ft_strcmp(ps->op_list->bottom->op, op) && ((ps->num_elements_a > 1)
		&& (bottom_is_rotate(ps)) && ((ps->num_elements_a
		- ps->op_list->bottom->num) < ps->op_list->bottom->num)))
	{
		ps->m = ps->op_list->bottom->num;
		ps->k = ps->num_elements_a - ps->op_list->bottom->num;
		if (!ft_strcmp(ps->op_list->bottom->op, OP_RRA))
		{
			while (ps->op_list && !ft_strcmp(ps->op_list->bottom->op, OP_RRA))
				input_delete_redundancy(ps);
			while (ps->k-- > 0)
				input_op(ps, OP_RA);
		}
		else if (!ft_strcmp(ps->op_list->bottom->op, OP_RA))
		{
			while (ps->op_list && !ft_strcmp(ps->op_list->bottom->op, OP_RA))
				input_delete_redundancy(ps);
			while (ps->k-- > 0)
				input_op(ps, OP_RRA);
		}
	}
	return (1);
}

int		num_already_sorted(t_push_swap *ps, int n)
{
	int		i;

	i = 0;
	ps->tmp_num = ps->pile_a;
	ps->i = ps->tmp_num->num;
	while (ps->tmp_num && n > 0)
	{
		n--;
		if (ps->i > ps->tmp_num->num)
			return (i);
		ps->i = ps->tmp_num->num;
		ps->tmp_num = ps->tmp_num->next;
		i++;
	}
	return (i);
}

t_bool	ps_flag_mode(t_push_swap *ps, char *string)
{
	if (!ft_strcmp(string, "-v"))
	{
		ps->verbose = true;
		return (true);
	}
	return (false);
}
