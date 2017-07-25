/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_rrb(t_push_swap *ps)
{
	if (!ps->pile_b)
		return (false);
	if (ps->num_elements_b == 1)
		return (true);
	ps->tmp_num = ps->pile_b->bottom;
	ps->tmp_num->next = ps->pile_b;
	ps->tmp_num->bottom = ps->tmp_num->prev;
	ps->tmp_num->prev->next = NULL;
	ps->tmp_num->prev->bottom = ps->tmp_num->prev;
	ps->pile_b->bottom = ps->tmp_num->prev;
	ps->tmp_num->prev = NULL;
	ps->pile_b->prev = ps->tmp_num;
	ps->pile_b = ps->tmp_num;
	ps->pile_b->prev = NULL;
	return (true);
}

t_bool		op_rrb_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_rrb(ps))
			return (false);
		input_op(ps, OP_RRB);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}

t_bool		op_rrb_custom_b(t_push_swap *ps)
{
	if (!ps->pile_b || !ps->pile_a)
		return (false);
	if  (ps->pile_b->bottom->num < ps->pile_a->num)
		if (ps->pile_b->bottom->num > ps->pile_b->num)
		{
			op_rrb_n(ps, 1);
			op_pa_n(ps, 1);
		}
	return (true);
}


t_bool		op_rrb_custom_a(t_push_swap *ps)
{
	if (!ps->pile_b || !ps->pile_a)
		return (false);
	if (ps->pile_b->bottom->num < ps->pile_a->num)
		if (ps->pile_b->bottom->num > ps->pile_a->bottom->num)
		{
			op_rrb_n(ps, 1);
			op_pa_n(ps, 1);
		}
	return (true);
}