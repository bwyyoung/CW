/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 16:15:25 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	input_op_check(t_push_swap *ps, char *op)
{
	if (!ft_strcmp(ps->op_list->bottom->op, OP_PA) && !ft_strcmp(op, OP_PB))
		return (false);
	if (!ft_strcmp(ps->op_list->bottom->op, OP_PB) && !ft_strcmp(op, OP_PA))
		return (false);
	if (!ft_strcmp(ps->op_list->bottom->op, OP_RA) && !ft_strcmp(op, OP_RRA))
		return (false);
	if (!ft_strcmp(ps->op_list->bottom->op, OP_RRA) && !ft_strcmp(op, OP_RA))
		return (false);
	if (!ft_strcmp(ps->op_list->bottom->op, OP_RRB) && !ft_strcmp(op, OP_RB))
		return (false);
	return (true);
}

t_bool	input_op(t_push_swap *ps, char *op)
{
	((ps->verbose) ? ft_printf("%s\n", op) : 0);
	if (ps->check_mode)
		return (false);
	if (!ps->op_list)
	{
		ps->op_list = init_num(1, 0);
		ps->op_list->bottom = ps->op_list;
		ps->op_list->op = ft_strdup(op);
		return (true);
	}
	if (!input_op_check(ps, op))
		return (input_delete_redundancy(ps));
	ps->op_list->bottom->next = init_num(input_rotate_recurring(ps, op), 0);
	ps->op_list->bottom->next->op = ft_strdup(op);
	ps->op_list->bottom->next->prev = ps->op_list->bottom;
	ps->op_list->bottom = ps->op_list->bottom->next;
	return (true);
}

t_bool	verify_input(t_push_swap *ps, char **argv)
{
	if ((ps->num_elements == 1) && (ft_strstr(argv[1], " ") != NULL))
	{
		if (!parse_single_param_string(ps, argv))
			return (false);
		argv = ps->tmp_argv;
	}
	while (++ps->i < (ps->num_elements + 1))
		if (!ft_isint(argv[ps->i]))
			return (false);
	ps->arr_elements = malloc(sizeof(int) * ps->num_elements);
	if (!ps->arr_elements)
		return (false);
	parse_input(ps, argv);
	while (++ps->i < ps->num_elements)
		while(++ps->j < ps->num_elements)
			if ((ps->i != ps->j) &&
			(ps->arr_elements[ps->i] == ps->arr_elements[ps->j]))
				return (false);
	return (true);
}

t_bool	parse_single_param_string(t_push_swap *ps, char **argv)
{
	ps->buffer = ft_strjoin("0 ", argv[1]);
	if (!ps->buffer)
		return (false);
	ps->tmp_argv = ft_strsplit(ps->buffer, ' ');
	SAFE_DELETE(ps->buffer);
	if (!ps->tmp_argv)
		return (false);
	ps->num_elements = 0;
	ps->i = 0;
	while (ps->tmp_argv[++ps->i] != NULL)
		ps->num_elements++;
	ps->num_elements_a = ps->num_elements;
	ps->i = 0;
	return (true);
}

void	parse_input(t_push_swap *ps, char **argv)
{
	ps->i = ps->num_elements + 1;
	while (--ps->i > 0)
	{
		if (!ps->pile_a)
		{
			ps->pile_a = init_num(ft_atoi(argv[ps->i]), ps->i - 1);
			ps->tmp_num = ps->pile_a;
			ps->arr_elements[ps->i - 1] = ps->tmp_num->num;
			ps->pile_a->bottom = ps->pile_a;
			continue;
		}
		ps->tmp_num->prev = init_num(ft_atoi(argv[ps->i]), ps->i - 1);
		ps->tmp_num->prev->next = ps->tmp_num;
		ps->tmp_num = ps->tmp_num->prev;
		ps->tmp_num->bottom = ps->tmp_num->next->bottom;
		ps->pile_a = ps->tmp_num;
		ps->arr_elements[ps->i - 1] = ps->tmp_num->num;
	}
	ps->i = -1;
	ps->j = -1;
}
