/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:51:46 by tattali           #+#    #+#             */
/*   Updated: 2017/05/17 09:51:46 by tattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <float.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "libft/get_next_line.h"
# define OP_PA "pa"
# define OP_PB "pb"
# define OP_RA "ra"
# define OP_RB "rb"
# define OP_RR "rr"
# define OP_RRA "rra"
# define OP_RRB "rrb"
# define OP_RRR "rrr"
# define OP_SA "sa"
# define OP_SB "sb"
# define OP_SS "ss"
# define DEBUG_PS 1

typedef enum
{
	A,
	B
}	t_pile;

typedef struct		s_num
{
	int				num;
	int				i;
	int				i_fin;
	char			*op;
	t_pile			p;
	struct s_num	*prev;
	struct s_num	*next;
	struct s_num	*bottom;
}					t_num;

typedef struct		s_push_swap
{
	char			*buffer;
	char			**tmp_argv;
	t_num			*pile_a;
	t_num			*pile_b;
	t_num			*tmp_num;
	t_num			*op_list;
	int				num_elements;
	int				num_elements_a;
	int				num_elements_b;
	int				*arr_elements;
	t_bool			check_mode;
	t_bool			echo;
	t_bool			verbose;
	int				i;
	int				j;
	int				m;
	int				k;
}					t_push_swap;

t_push_swap			*init_push_swap();
int					delete_push_swap(t_push_swap *ps, t_bool err);
t_num				*init_num(int n, int index);
int					print_push_swap(t_push_swap *ps);
t_bool				checker_input(t_push_swap *ps);
t_bool				verify_input(t_push_swap *ps, char **argv);
t_bool				input_op(t_push_swap *ps, char *op);
t_bool				input_delete_redundancy(t_push_swap *ps);
int					input_rotate_recurring(t_push_swap *ps, char *op);
void				parse_input(t_push_swap *ps, char **argv);
t_bool				parse_single_param_string(t_push_swap *ps, char **argv);
t_bool				op_pa(t_push_swap *ps);
t_bool				op_pa_n(t_push_swap *ps, int n);
t_bool				op_pa_n_custom_1(t_push_swap *ps, int n, int m);
t_bool				op_pb(t_push_swap *ps);
t_bool				op_pb_n(t_push_swap *ps, int n);
t_bool				op_pb_n_custom_1(t_push_swap *ps, int *n, int *m);
t_bool				op_pb_n_custom_2(t_push_swap *ps, int n);
t_bool				op_ra(t_push_swap *ps);
t_bool				op_ra_n(t_push_swap *ps, int n);
t_bool				op_rb(t_push_swap *ps);
t_bool				op_rb_n(t_push_swap *ps, int n);
t_bool				op_rr(t_push_swap *ps);
t_bool				op_rra(t_push_swap *ps);
t_bool				op_rra_n(t_push_swap *ps, int n);
t_bool				op_rra_n_custom_1(t_push_swap *ps);
t_bool				op_rra_n_custom_2(t_push_swap *ps);
t_bool				op_rrb(t_push_swap *ps);
t_bool				op_rrb_n(t_push_swap *ps, int n);
t_bool				op_rrb_custom_b(t_push_swap *ps);
t_bool				op_rrb_custom_a(t_push_swap *ps);
t_bool				op_rrr(t_push_swap *ps);
t_bool				op_sa(t_push_swap *ps);
t_bool				op_sa_n(t_push_swap *ps, int n);
t_bool				op_sb(t_push_swap *ps);
t_bool				op_sb_n(t_push_swap *ps, int n);
t_bool				op_ss(t_push_swap *ps);
void				sort_merge(t_push_swap *ps, int n);
t_bool				merge_already_sorted(t_push_swap *ps, int n);

void				ps_verbose(t_push_swap *ps, char *string, ...);
t_bool				ps_flag_mode(t_push_swap *ps, char *string);
#endif
