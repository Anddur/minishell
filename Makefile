SRCS	=	minishell.c \
			exec/exec_assign.c \
			exec/exec_bin.c \
			exec/exec_cd.c \
			exec/exec_cmd.c \
			exec/exec_echo.c \
			exec/exec_env.c \
			exec/exec_pwd.c \
			exec/exec.c \
			exec/exec_exit.c \
			exec/exec_export.c \
			exec/exec_unset.c \
			exec/expand_var.c \
			exec/ft_find_env.c \
			exec/manage_fds.c \
			exec/parse_cmd.c \
			exec/parse_syntax.c \
			exec/set_fds.c \
			free/exit.c \
			free/free_cmds_lst.c \
			history/compute_alt_upndown.c \
			history/compute_arrow.c \
			history/compute_crud.c \
			history/compute_cut.c \
			history/compute_homenend.c \
			history/compute_input.c \
			history/compute_left_arrow.c \
			history/compute_right_arrow.c \
			history/compute_upndown_arrow.c \
			history/init_term.c \
			history/manipulate_input.c \
			history/manipulate_utils.c \
			history/parse_input.c \
			history/save_history.c \
			signal/signal.c \
			utils/create_cmd.c \
			utils/errors.c \
			utils/fork_error.c \
			utils/ft_cmp_env.c \
			utils/ft_man_env.c \
			utils/ft_redirnpipe.c \
			utils/ft_split_lst.c \
			utils/ft_split_mod.c \
			utils/ft_trimquote.c \
			utils/print_error.c \
			utils/print_logo.c \
			utils/print_prompt.c \
			utils/read_input.c \
			utils/set_flag.c \
			utils/set_user.c \
			utils/syntax_error.c

OBJS	= ${SRCS:.c=.o}

INCS	= ./includes

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a

NAME	= minishell

$(VERBOSE).SILENT:

RED		= \033[0;31m
NC		= \033[0m
GREEN	= \033[0;32m
BLUE	= \033[0;34m

%.o		: %.c
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o} -I $(INCS)

all		: $(NAME)

$(NAME)	: $(OBJS)
		make -C ./libft
		$(CC) -lcurses -ltermcap $(OBJS) $(LIBFT) -I $(INCS) -o $(NAME)
		@echo  "$(GREEN)Minishell is ready$(NC)"

bonus	: re

test	: re
		@echo  "$(GREEN)Exec Minishell$(NC)"
		./minishell

clean	:
		make clean -C ./libft
		rm -rf $(OBJS)

fclean	: clean
		make fclean -C ./libft
		rm -rf $(NAME)

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(INCS)/*.h

re		: fclean all

.PHONY	: all bonus clean fclean re
