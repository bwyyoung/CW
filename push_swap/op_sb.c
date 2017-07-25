/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_sb(t_push_swap *ps)
{
	if (!ps->pile_b)
		return (false);
	if (ps->num_elements_b == 1)
		return (false);
	ps->tmp_num = ps->pile_b;
	ps->pile_b = ps->pile_b->next;
	ps->tmp_num->next = ps->pile_b->next;
	ps->tmp_num->prev = ps->pile_b;
	if (ps->num_elements_b == 2)
	{
		ps->pile_b->bottom = ps->tmp_num;
		ps->tmp_num->bottom = ps->tmp_num;
	}
	else
		ps->pile_b->bottom = ps->tmp_num->bottom;
	ps->pile_b->next = ps->tmp_num;
	ps->pile_b->prev = NULL;
	if (ps->tmp_num->next)
		ps->tmp_num->next->prev = ps->tmp_num;
	return (true);
}

t_bool		op_sb_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_sb(ps))
			return (false);
		input_op(ps, OP_SB);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}
