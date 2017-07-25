/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap			*init_push_swap(void)
{
	t_push_swap		*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (ps == NULL)
		ft_error("Error Malloc init_num\n");
	ps->pile_a = NULL;
	ps->pile_b = NULL;
	ps->i = 0;
	ps->j = 0;
	ps->buffer = NULL;
	ps->op_list = NULL;
	ps->tmp_argv = NULL;
	ps->m = 0;
	ps->num_elements_a = 0;
	ps->num_elements_b = 0;
	ps->num_elements = 0;
	ps->arr_elements = NULL;
	ps->check_mode = false;
	ps->echo = true;
	ps->verbose = false;
	return (ps);
}

t_num				*init_num(int n, int index)
{
	t_num		*num;

	num = (t_num *)malloc(sizeof(t_num));
	if (num == NULL)
		ft_error("Error Malloc init_num\n");
	num->next = NULL;
	num->num = n;
	num->i = index;
	num->i_fin = 0;
	num->p = A;
	num->op = NULL;
	num->prev = NULL;
	num->next = NULL;
	num->bottom = NULL;
	return (num);
}

int					print_push_swap(t_push_swap *ps)
{
	if (!DEBUG_PS && !ps->verbose)
		return (0);
	ps->tmp_num = ps->pile_a;
	ft_putstr("--------------\nA: ");
	while (ps->tmp_num)
	{
		ft_printf("(%i)<- %i (%i)| ", (ps->tmp_num->prev ?
		ps->tmp_num->prev->num : -999), ps->tmp_num->num,
		ps->tmp_num->bottom->num);
		ps->tmp_num = ps->tmp_num->next;
	}
	ft_putstr("\nB: ");
	ps->tmp_num = ps->pile_b;
	while (ps->tmp_num)
	{
		ft_printf("(%i)<- %i (%i)| ", (ps->tmp_num->prev ?
		ps->tmp_num->prev->num : -999), ps->tmp_num->num,
		ps->tmp_num->bottom->num);
		ps->tmp_num = ps->tmp_num->next;
	}
	ft_putstr("\n--------------\n");
	return (0);
}

int					delete_push_swap(t_push_swap *ps, t_bool err)
{
	if (err)
		ft_printf("Error\n");
	if (!ps)
		return (0);
	while (ps->op_list)
	{
		ps->tmp_num = ps->op_list;
		ps->op_list = ps->op_list->next;
		(err ? 0 : ft_printf("%s\n", ps->tmp_num->op));
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
	SAFE_DELETE(ps->arr_elements);
	while ((ps->tmp_argv != NULL) && (--ps->num_elements + 1 >= 0))
	{
		SAFE_DELETE(ps->tmp_argv[ps->num_elements + 1]);
	}
	SAFE_DELETE(ps->tmp_argv);
	SAFE_DELETE(ps->buffer);
	SAFE_DELETE(ps);
	return (0);
}

t_bool				merge_already_sorted(t_push_swap *ps, int n)
{
	if (ps->pile_b || !ps->pile_a)
		return (false);
	ps->tmp_num = ps->pile_a;
	ps->i = ps->tmp_num->num;
	while (ps->tmp_num && n > 0)
	{
		n--;
		if (ps->i > ps->tmp_num->num)
			return (false);
		ps->i = ps->tmp_num->num;
		ps->tmp_num = ps->tmp_num->next;
	}
	return (true);
}
