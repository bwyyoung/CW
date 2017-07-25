/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_pb(t_push_swap *ps)
{
	if (!ps->pile_a || !ps->num_elements_a)
		return (false);
	ps->tmp_num = ps->pile_a;
	ps->tmp_num->p = B;
	ps->pile_a = ps->pile_a->next;
	if (ps->pile_a)
	{
		ps->pile_a->bottom = ps->tmp_num->bottom;
		ps->pile_a->prev = NULL;
	}
	ps->tmp_num->next = ps->pile_b;
	ps->tmp_num->bottom = ps->tmp_num;
	ps->tmp_num->prev = NULL;
	if (ps->pile_b)
	{
		ps->tmp_num->bottom = ps->pile_b->bottom;
		ps->pile_b->prev = ps->tmp_num;
	}
	ps->pile_b = ps->tmp_num;
	ps->num_elements_b++;
	ps->num_elements_a--;
	return (true);
}

t_bool		op_pb_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_pb(ps))
			return (false);
		input_op(ps, OP_PB);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}

t_bool		op_pb_n_custom_1(t_push_swap *ps, int *n, int *m)
{
	ps->i = *n - 1;
	while (ps->i-- > 0 && *m >= 0)
	{
		if (ps->pile_b && ps->num_elements_a >= 2 &&
			(ps->pile_a->num > ps->pile_a->bottom->num) &&
				(ps->pile_b->num < ps->pile_a->bottom->num))
		{
			op_rra_n(ps, 1);
			op_pb_n(ps, 2);
			*n = *n + 1;
			*m = *m - 1;
			continue ;
		}
		op_pb_n(ps, 1);
	}
	if (ps->num_elements_a >= 2 && (ps->pile_a->num > ps->pile_a->next->num)
		&& ps->pile_b && (ps->pile_b->num < ps->pile_a->next->num))
		op_sa_n(ps, 1);
	op_pb_n(ps, 1);
	return (true);
}
