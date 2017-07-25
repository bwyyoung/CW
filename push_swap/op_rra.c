/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_rra(t_push_swap *ps)
{
	if (!ps->pile_a)
		return (false);
	if (ps->num_elements_a == 1)
		return (true);
	ps->tmp_num = ps->pile_a->bottom;
	ps->tmp_num->next = ps->pile_a;
	ps->tmp_num->bottom = ps->tmp_num->prev;
	ps->tmp_num->prev->next = NULL;
	ps->tmp_num->prev->bottom = ps->tmp_num->prev;
	ps->pile_a->bottom = ps->tmp_num->prev;
	ps->tmp_num->prev = NULL;
	ps->pile_a->prev = ps->tmp_num;
	ps->pile_a = ps->tmp_num;
	ps->pile_a->prev = NULL;
	return (true);
}

t_bool		op_rra_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_rra(ps))
			return (false);
		input_op(ps, OP_RRA);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}

t_bool		op_rra_n_custom_1(t_push_swap *ps, int *n, int *m)
{
	if (*n + *m != ps->num_elements_a)
		return (false);
	ps->i = 0;
	while ((ps->num_elements_a >= 2)
		&& (ps->pile_a->num > ps->pile_a->bottom->num))
	{
		op_rra_n(ps, 1);
		//*n = *n + 1;
		ps->i++;
		/*if (ps->i >= ps->num_elements_a)
		{
			op_ra_n(ps, ps->num_elements_a);
			break;
		}*/
	}
	return (true);
}

t_bool		op_rra_n_custom_2(t_push_swap *ps, int *n, int *m)
{
	if (*n + *m != ps->num_elements_a)
		return (false);
	ps->i = 0;
	while ((ps->num_elements_a >= 2) && (ps->num_elements_b >= 1)
		&& (ps->pile_a->num > ps->pile_a->bottom->num)
		&& (ps->pile_b->num < ps->pile_a->bottom->num))
	{
		op_rra_n(ps, 1);
		//*m = *m + 1;
		ps->i++;
		if (ps->i >= ps->num_elements_a)
		{
			op_ra_n(ps, ps->num_elements_a);
			break;
		}
	}
	return (true);
}
