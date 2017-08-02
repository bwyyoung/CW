# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	=	push_swap
CHECKER		=	checker
CC			=	gcc -g -Wall -Werror -Wdeprecated-declarations -Wextra
CCO			=	gcc -o
LIB			=	-L libft/ -lft -L ft_printf/ -lftprintf
FLAGS		=	-Wall -Werror -Wextra

INC		=	-I libft/ -I ft_printf

SRC_CHECKER		=	main_checker.c					\
					$(SRC_COMMON)


SRC_PUSH_SWAP	=	main_push_swap.c				\
					sort_counting.c					\
					sort_merge.c					\
					$(SRC_COMMON)
					
SRC_COMMON		=	op_pa.c			\
					op_pb.c			\
					op_ra.c			\
					op_rb.c			\
					op_rr.c			\
					op_rra.c		\
					op_rrb.c		\
					op_rrr.c		\
					op_sa.c			\
					op_sb.c			\
					op_ss.c			\
					input.c			\
					input_verify.c	\
					push_swap.c		\
					delete.c


OBJ_CHECKER		=	$(SRC_CHECKER:.c=.o) #interesting compilation method
OBJ_PUSH_SWAP	=	$(SRC_PUSH_SWAP:.c=.o) #interesting compilation method


all				: MAKE_LIBS $(PUSH_SWAP) $(CHECKER)

MAKE_LIBS		:
	@make -C libft/
	@make -C ft_printf/

$(PUSH_SWAP)	: $(OBJ_PUSH_SWAP)
	@$(CC) $(FLAGS) $(INC) $(OBJ_PUSH_SWAP) -o $(PUSH_SWAP) $(LIB)

$(CHECKER)		: $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(INC) $(OBJ_CHECKER) -o $(CHECKER) $(LIB)

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

clean	:
	@make -C libft/ clean
	@make -C ft_printf/ clean
	@$(RM) $(OBJ_CHECKER)
	@$(RM) $(OBJ_PUSH_SWAP)

fclean	: clean
	@make -C libft/ fclean
	@make -C ft_printf/ fclean
	@$(RM) $(PUSH_SWAP)
	@$(RM) $(CHECKER)

re		: fclean all

.PHONY : re fclean clean all