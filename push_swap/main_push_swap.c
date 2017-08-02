/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_push_swap		*data;

	if (argc == 1)
		return (0);
	data = init_push_swap();
	if (!data)
		return (delete_push_swap(data, true));
	data->num_elements = argc - 1;
	data->num_elements_a = argc - 1;
	data->check_mode = false;
	if (!verify_input(data, argv))
		return (delete_push_swap(data, true));
	sort_merge(data, data->num_elements);
	data->tmp_num = data->op_list;
	while (data->tmp_num)
	{
		ft_printf("%s\n", data->tmp_num->op);
		data->tmp_num = data->tmp_num->next;
	}
	data->verbose = true;
	ft_printf("./push_swap arg |%s|\n", argv[1]);
	print_push_swap(data);
	delete_push_swap(data, false);

	return (0);
}
