/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		merge_shortcut(t_push_swap *ps, int len_h1, int len_h2)
{
	if (ps->pile_a && ps->pile_b && ps->pile_a->num >= ps->pile_b->num)
		return (op_pa_n(ps, len_h1));
	if (len_h2 < ps->num_elements_a)
	{
		//while (ps->pile_a && ps->pile_a->next &&
			//	(ps->pile_a->num < ps->pile_a->next->num))
	//	if (len_h2 < ps->num_elements_a / 2)
			op_ra_n(ps, len_h2);
	//	else
	//		op_rra_n(ps, ps->num_elements_a - len_h2);
		input_rotate_recurring(ps, "OFFSET");
	}
	return (false);
}

t_bool		merge_shortcut_small(t_push_swap *ps, int n)
{
	while (ps->pile_a && (ps->pile_a->num > ps->pile_a->bottom->num))
		op_rra_n(ps, 1);
	input_rotate_recurring(ps, "OFFSET");
	if (ps->pile_a && ps->pile_a->next)
		if ((n == 3 || n == 2) && (ps->pile_a->num > ps->pile_a->next->num))
			op_sa_n(ps, 1);
	if (n == 3 && !merge_already_sorted(ps, n))
	{
		op_ra_n(ps, 1);
		op_sa_n(ps, 1);
		op_rra_n(ps ,1);
		if ((ps->pile_a && ps->pile_a->next)
			&& ps->pile_a->num > ps->pile_a->next->num)
			op_sa_n(ps, 1);
	}
	if (merge_already_sorted(ps, n))
		return (true);
	return (false);
}

void		merge(t_push_swap *ps, int len_h1, int len_h2)
{
	while (ps->i < len_h1 && ps->j < len_h2)
	{
		if (ps->pile_a && ps->pile_b &&
				ps->pile_a->bottom->num < ps->pile_b->num)
		{
			op_pa_n(ps, 1);
			ps->i++;
			continue ;
		}
		op_rra_n(ps, 1);
		ps->j++;
	}
	ps->i--;
	ps->j--;
	while (++ps->j < len_h2)
		op_rra_n(ps, 1);
	input_rotate_recurring(ps, "OFFSET");
	while (++ps->i < len_h1)
		op_pa_n(ps, 1);
}

t_bool		calc_merge_half(t_push_swap *ps, int *n, int *len_h1, int *len_h2)
{
	int		m;

	if (*n <= 1)
		return (false);
	*len_h1 = 0;
	*len_h2 = 0;
	m = (*n / 2);
	*len_h1 = *n - m;
	*len_h2 = m;
	if ((*len_h2 >= *len_h1) && (*n < ps->num_elements_a))
		return (true);
	*len_h1 = m;
	*len_h2 = *n - m;
	return (true);
}

void		sort_merge(t_push_swap *ps, int n)
{
	int		len_h1;
	int		len_h2;

	if (merge_already_sorted(ps, n))
		return ;
	if (!calc_merge_half(ps, &n, &len_h1, &len_h2))
		return ;
	if (merge_shortcut_small(ps, n))
		return ;

	sort_merge(ps, len_h1);
	if (merge_already_sorted(ps, n))
		return ;
	if (n < ps->num_elements / 2)
	while (ps->pile_a && (ps->pile_a->num > ps->pile_a->bottom->num))
	{
		op_rra_n(ps, 1);
		len_h1++;
	}
	input_rotate_recurring(ps, "OFFSET");
	ps->k = ps->num_elements_b;
	op_pb_n_custom_1(ps, &len_h1, &len_h2);

/*	if (n < ps->num_elements / 2)
		while (ps->pile_b && (ps->pile_b->num < ps->pile_b->bottom->num))
		{
			op_rrb_n(ps, 1);
			len_h1++;
		}
*/
	sort_merge(ps, len_h2);
	if (n < ps->num_elements / 2)
	while (ps->pile_a && (ps->pile_a->num > ps->pile_a->bottom->num))
	{
		op_rra_n(ps, 1);
		len_h2++;
	}
	input_rotate_recurring(ps, "OFFSET");
	print_push_swap(ps);
	ps->i = 0;
	ps->j = 0;
	if (merge_shortcut(ps, len_h1, len_h2))
		return ;
	merge(ps, len_h1, len_h2);
	if (n < ps->num_elements / 2)
	while (ps->pile_a && (ps->pile_a->num > ps->pile_a->bottom->num))
	{
		op_rra_n(ps, 1);
	}
	input_rotate_recurring(ps, "OFFSET");
}
