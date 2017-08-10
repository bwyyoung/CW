/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				delete_struct_arrays(t_push_swap *ps)
{
	while (ps->op_list)
	{
		ps->tmp_num = ps->op_list;
		ps->op_list = ps->op_list->next;
		SAFE_DELETE(ps->tmp_num->op);
		SAFE_DELETE(ps->tmp_num);
	}
	while (ps->pile_a)
	{
		ps->tmp_num = ps->pile_a;
		ps->pile_a = ps->pile_a->next;
		SAFE_DELETE(ps->tmp_num);
	}
	while (ps->pile_b)
	{
		ps->tmp_num = ps->pile_b;
		ps->pile_b = ps->pile_b->next;
		SAFE_DELETE(ps->tmp_num);
	}
	ps->i = -1;
	while ((ps->tmp_argv != NULL) && (ps->tmp_argv[++ps->i] != NULL))
	{
		SAFE_DELETE(ps->tmp_argv[ps->i]);
	}
}

int					delete_push_swap(t_push_swap *ps, t_bool err)
{
	if (err)
		ft_printf("Error\n");
	if (!ps)
		return (0);
	delete_struct_arrays(ps);
	SAFE_DELETE(ps->arr_elements);
	SAFE_DELETE(ps->tmp_argv);
	SAFE_DELETE(ps->buffer);
	SAFE_DELETE(ps);
	return (0);
}
