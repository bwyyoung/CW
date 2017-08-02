/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		op_pa(t_push_swap *ps)
{
	if (!ps->pile_b || !ps->num_elements_b)
		return (false);
	ps->tmp_num = ps->pile_b;
	ps->tmp_num->p = A;
	ps->pile_b = ps->pile_b->next;
	if (ps->pile_b)
	{
		ps->pile_b->bottom = ps->tmp_num->bottom;
		ps->pile_b->prev = NULL;
	}
	ps->tmp_num->next = ps->pile_a;
	ps->tmp_num->bottom = ps->tmp_num;
	ps->tmp_num->prev = NULL;
	if (ps->pile_a)
	{
		ps->tmp_num->bottom = ps->pile_a->bottom;
		ps->pile_a->prev = ps->tmp_num;
	}
	ps->pile_a = ps->tmp_num;
	ps->num_elements_a++;
	ps->num_elements_b--;
	return (true);
}

t_bool		op_pa_n(t_push_swap *ps, int n)
{
	while (n-- > 0)
	{
		if (!op_pa(ps))
			return (false);
		input_op(ps, OP_PA);
	}
	((ps->verbose) ? print_push_swap(ps) : 0);
	return (true);
}

t_bool		op_pa_n_custom_1(t_push_swap *ps, int n, int m)
{
	//ps->k = ps->num_elements_a;
	while (++n < m)
	{
		while (ps->pile_b && ps->pile_a &&
		(ps->pile_a->num > ps->pile_a->bottom->num) &&
		(ps->pile_b->num < ps->pile_a->bottom->num))
		{
			ft_printf("op_pa_n_custom_1 rra \n");
			op_rra_n(ps, 1);
			//n--;
		}
		//input_rotate_recurring(ps, "OFFSET");
		op_pa_n(ps, 1);
	}
	return (true);
}
