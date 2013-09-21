##
## Makefile for  in /home/knocka_a/repositories/42sh-2016-knocka_a
##
## Made by antoine knockaert
## Login   <knocka_a@epitech.net>
##
## Started on  Sun May 20 22:22:59 2012 antoine knockaert
## Last update Sat Sep 21 17:36:46 2013 antoine knockaert
##

NAME=			42sh
RM=			rm -f
CC=			cc
CFLAGS=			-g -W -Wall -ansi -pedantic -lcurses

LDFLAGS=		-lcurses

## Prompt SRC

PROMPT_SRC=		prompt/my_prompt.c \
			prompt/init_prompt.c \
			prompt/prompt_dispatcher.c \
			prompt/reset_term.c \
			prompt/basic_prompt.c \
			prompt/termcap_prompt.c \
			prompt/add_to_hist.c \
			prompt/put_signal.c \
			prompt/history.c \
			prompt/replace_alias.c \
			prompt/autocomplete.c \
			prompt/key_funcs.c \

PROMPT_OBJ=		$(PROMPT_SRC:.c=.o)

## Builtins SRC

BUILTINS_SRC=		builtins/my_cd/main.c \
			builtins/my_setenv/main.c \
			builtins/my_unsetenv/main.c \
			builtins/my_exit/main.c \
			builtins/my_echo/main.c \

BUILTINS_OBJ=		$(BUILTINS_SRC:.c=.o)

## Parser

PARSER_SRC=		parser/tree.c \
			parser/init_parser.c \
			parser/add_to_end.c \
			parser/parser.c \
			parser/init.c \
			parser/handle.c \
			parser/error_pars.c \
			parser/find_pars.c \
			parser/link.c \
			parser/redir.c \
			parser/redir_2.c \
			parser/handle_2.c \
			parser/epur_pars.c \
			parser/gere_alias_pars.c \
			parser/free_tree.c

PARSER_OBJ=		$(PARSER_SRC:.c=.o)

## Execution SRC

EXEC_SRC=		execution/execution.c \
			execution/search.c \
			execution/search_pipe.c \
			execution/gere_status.c \
			execution/func_to_fork.c \
			execution/execution_bin.c \
			execution/redir_right.c \
			execution/redir_left.c \
			execution/pipe.c \
			execution/check_dup.c \
			execution/check_dup2.c \
			execution/check_builtins.c \
			execution/check_access.c \
			execution/check_error.c \
			execution/check_pipe.c \
			execution/copy_env.c \
			execution/copy_value.c \
			execution/execution_general.c \
			execution/do_fork_pipe.c \
			execution/check_path.c \
			execution/error.c \
			execution/check_bin.c \
			execution/d_redir_right.c \
			execution/d_redir_left.c \
			execution/end_of_way.c \
			execution/type_of_redir.c

EXEC_OBJ=		$(EXEC_SRC:.c=.o)

## Other SRC

OTHER_SRC=		others/main.c \
			others/add_alias.c \
			others/add_var_list.c \
			others/free.c \
			others/init_builtins.c \
			others/add_alias_list.c \
			others/init_env.c \
			others/init_history.c \
			others/add_hist_end.c \
			others/add_env_end.c \
			others/shell.c \
			others/init.c \
			others/init_config.c

OTHER_OBJ=		$(OTHER_SRC:.c=.o)

## Lib SRC

LIB_SRC=		lib/xmalloc.c \
			lib/my_getenv.c \
			lib/my_getenv_ptr.c \
			lib/create_path.c \
			lib/xclose.c \
			lib/read_all.c \
			lib/my_getnbr.c \
			lib/concat.c \
			lib/my_putstr.c \
			lib/my_str_to_wordtab.c \
			lib/xread.c \
			lib/my_putint.c \
			lib/enable_tc.c \
			lib/xwrite.c \
			lib/my_perror.c \
			lib/my_strlen.c \
			lib/xfree.c \
			lib/copy_wordtab.c \
			lib/epur_str.c \
			lib/free_wtb.c \
			lib/my_match.c \
			lib/my_lenenv.c \
			lib/my_strdup.c \
			lib/my_tablen.c \
			lib/init_str.c

LIB_OBJ=		$(LIB_SRC:.c=.o)

## Rules

all:		$(NAME)

$(NAME):	$(PROMPT_OBJ) $(BUILTINS_OBJ) $(PARSER_OBJ) $(EXEC_OBJ) $(OTHER_OBJ) $(LIB_OBJ)
		$(CC) -o $(NAME) $(PROMPT_OBJ) $(BUILTINS_OBJ) $(PARSER_OBJ) $(EXEC_OBJ) $(OTHER_OBJ) $(LIB_OBJ) -lcurses

clean:
		$(RM) $(PROMPT_OBJ) $(BUILTINS_OBJ) $(PARSER_OBJ) $(EXEC_OBJ) $(OTHER_OBJ) $(LIB_OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all
