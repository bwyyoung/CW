/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_rb(t_push_swap *ps)
{
	if (!ps->pile_b)
		return (false);
	if (ps->num_elements_b == 1)
		return (true);
	ps->tmp_num = ps->pile_b;
	ps->pile_b = ps->pile_b->next;
	if (ps->pile_b)
		ps->pile_b->bottom = ps->tmp_num;
	ps->pile_b->prev = NULL;
	ps->tmp_num->bottom->next = ps->tmp_num;
	ps->tmp_num->prev = ps->tmp_num->bottom;
	ps->tmp_num->bottom->bottom = ps->tmp_num;
	ps->tmp_num->bottom = ps->tmp_num;
	ps->tmp_num->next = NULL;
	return (true);
}

t_bool		op_rb_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_rb(ps))
			return (false);
		input_op(ps, OP_RB);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}
