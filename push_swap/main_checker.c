/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	input_loop_2(t_push_swap *ps)
{
	if (!ft_strcmp(ps->buffer, OP_RRA))
		op_rra_n(ps, 1);
	else if (!ft_strcmp(ps->buffer, OP_RRB))
		op_rrb_n(ps, 1);
	else if (!ft_strcmp(ps->buffer, OP_RRR))
		op_rrr(ps);
	else if (!ft_strcmp(ps->buffer, OP_SA))
		op_sa_n(ps, 1);
	else if (!ft_strcmp(ps->buffer, OP_SB))
		op_sb_n(ps, 1);
	else if (!ft_strcmp(ps->buffer, OP_SS))
		op_ss(ps);
	else
	{
		ft_printf("%s\n", ps->buffer);
		return (true); //TODO: TEMP
	}
	return (true);
}

t_bool	input_loop(t_push_swap *ps)
{
	int i = 1;
	while (get_next_line(0, &ps->buffer) > 0)
	{
		if (!ft_strcmp(ps->buffer, OP_PA))
			op_pa_n(ps, 1);
		else if (!ft_strcmp(ps->buffer, OP_PB))
			op_pb_n(ps, 1);
		else if (!ft_strcmp(ps->buffer, OP_RA))
			op_ra_n(ps, 1);
		else if (!ft_strcmp(ps->buffer, OP_RB))
			op_rb_n(ps, 1);
		else if (!ft_strcmp(ps->buffer, OP_RR))
			op_rr(ps);
		else if (!input_loop_2(ps))
			return (false);
		SAFE_DELETE(ps->buffer);
		ft_printf("input_loop %i\n", i++);
	}
	return (true);
}

void	check_solved(t_push_swap *ps)
{
	if (!ps->num_elements || merge_already_sorted(ps, ps->num_elements))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		main(int argc, char **argv)
{
	t_push_swap		*data;

	ft_printf("checker 1 %i | %s\n", argc - 1, argv[1]);
	if (argc == 1)
		return (0);
	data = init_push_swap();
	ft_printf("checker 2\n");
	if (!data)
		return (delete_push_swap(data, true));
	ft_printf("checker 3\n");
	data->echo = false;
	data->num_elements = argc - 1;
	data->num_elements_a = argc - 1;
	data->check_mode = true;
	ft_printf("checker 4\n");
	if (!verify_input(data, argv))
		return (delete_push_swap(data, true));
	ft_printf("checker 5\n");
	data->verbose = true;
	ft_printf("checker 6\n");
	if (!input_loop(data))
		return (delete_push_swap(data, true));
	ft_printf("checker 7\n");
	check_solved(data);
	ft_printf("checker 8 %i | %s\n", argc - 1, argv[1]);
	delete_push_swap(data, false);
	return (0);
}
