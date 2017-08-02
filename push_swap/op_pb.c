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

t_bool		op_pb_n_custom_1(t_push_swap *ps, int *len_h1, int *len_h2, int *n)
{
	ps->l = num_already_sorted(ps, *n);
	if ((ps->l  > *len_h1) && (ps->l < ps->num_elements_a))
	{
		*len_h1 = ps->l ;
		*len_h2 = *n - *len_h1;
	}
	ps->k = ps->num_elements_b;
	ps->i = *len_h1;
	ps->j = *len_h2;
	while (ps->i-- > 0 && *len_h2 >= 0)
	{
		while (ps->pile_a && ps->pile_b && (ps->num_elements_a >= 2) &&
			(ps->pile_a->num > ps->pile_a->bottom->num) &&
				(ps->pile_b->num < ps->pile_a->bottom->num) && (*len_h2 > 1))
		{
			op_rra_n(ps, 1);
			*len_h1 = *len_h1 + 1;
			*len_h2 = *len_h2 - 1;
			ps->i++;
		}
		input_rotate_recurring(ps, "OFFSET");
		op_pb_n(ps, 1);
	}
	return (true);
}
