/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_sa(t_push_swap *ps)
{
	if (!ps->pile_a)
		return (false);
	if (ps->num_elements_a == 1)
		return (false);
	ps->tmp_num = ps->pile_a;
	ps->pile_a = ps->pile_a->next;
	ps->tmp_num->next = ps->pile_a->next;
	ps->tmp_num->prev = ps->pile_a;
	if (ps->num_elements_a == 2)
	{
		ps->pile_a->bottom = ps->tmp_num;
		ps->tmp_num->bottom = ps->tmp_num;
	}
	else
		ps->pile_a->bottom = ps->tmp_num->bottom;
	ps->pile_a->next = ps->tmp_num;
	ps->pile_a->prev = NULL;
	if (ps->tmp_num->next)
		ps->tmp_num->next->prev = ps->tmp_num;
	return (true);
}

t_bool		op_sa_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_sa(ps))
			return (false);
		input_op(ps, OP_SA);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}
