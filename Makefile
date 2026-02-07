SRCS	=	main.c	parser/parser_redir3.c \
			parser/parser.c parser/input_split.c parser/input_split2.c	\
			parser/parser_delegator.c parser/parser_variable.c	\
			parser/parser_redir.c parser/parser2.c parser/parser_redir2.c	\
			parser/handle_basic.c parser/parser_error.c builtins/echo.c	\
			builtins/pwd.c builtins/cd_utils.c builtins/cd.c	\
			builtins/exec.c  builtins/exec_utils.c builtins/env.c	\
			builtins/export.c builtins/export_utils.c builtins/unset.c	\
			builtins/pipe.c builtins/signal.c builtins/exit.c get_next_line.c \
			get_next_line_utils.c parser/parser_redir4.c \
			parser/parser_error_redir.c parser/parser_error_redir2.c \
			parser/parser_error_redir3.c builtins/signal_utils.c\
			parser/handle_basic_utils.c parser/parser_delegator_utils.c \
			parser/parser_error2.c parser/parser_variable2.c builtins/exit_utils.c\

OBJS	= $(SRCS:.c=.o)
NAME	= minishell
LIBFT	= libft/libft.a

CC	= gcc
FLAGS	= -Wall -Wextra -Werror -g3
INCLUDE	= -L libft -lft
READLINE_FLAGS = -lreadline -I /usr/include/readline

all:
	@echo "\033[1;30mif compilation fails, make sure you have readline installed on your system.\033[0m" 
	@echo "\033[1;30mOn Debian/Ubuntu:\033[0m" 
	@echo "\033[1;30msudo apt-get install libreadline-dev\033[0m" 
	@echo "\033[1;30mOn macOS:\033[0m" 
	@echo "\033[1;30mbrew install readline\033[0m" 
	@echo "\n\033[1;34mCompilation is in progress...\033[0m\n"
	@make -s $(NAME)

%.o: %.c
	@printf "\033[KCompiling: $<\r"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C libft/
	@printf "\033[KCompiling: $$file\r"; \
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDE) $(READLINE_FLAGS)
	@echo "\033[1;32mMinishell: successful compilation\033[0m 🎇"

clean:
	@printf "\033[KRemoving $$file\r";
	@rm -f $(OBJS) $(B_OBJS)
	@make -s clean -C libft/
	@echo "\033[1;36m===>Minishell: .o correctly cleaned\033[0m"

fclean: clean
	@printf "\033[KRemoving $(NAME)\r"
	@rm -f $(NAME) $(BONUS)
	@rm -f ./libft/libft.a
	@echo "\033[1;36m===>Minishell: .a correctly cleaned\033[0m"
	
re: fclean all


.PHONY:	clean fclean re bonus
