/*
** parser.h for 42sh in /home/dell-a_f/42sh
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri May 18 11:44:10 2012 antoine maitre
** Last update Sun May 20 15:50:22 2012 antoine maitre
*/

#ifndef		__PARSER_H__
#define		__PARSER_H__

/*
** Includes
*/

#include		<stdlib.h>
#include		<unistd.h>

/*
** Defines
*/

#define LABEL_OPERAND	"|&;"
#define	OR		"||"
#define PIPE		"|"
#define AND		"&&"
#define AND_BIN		"&"
#define SEMICOLON	";"
#define LEFT_RED	"<"
#define D_LEFT_RED	"<<"
#define RIGHT_RED	">"
#define D_RIGHT_RED	">>"

/*
** Structures
*/

typedef struct	s_pars
{
  char			*command;
  char			*redir;
  char			*redir_fich;
  int			status;
  char			**arg;
  char			*token;
  char			success;
  struct s_pars		*left;
  struct s_pars		*right;
  struct s_pars		*next;
  struct s_pars		*prev;
}			t_pars;

/*
** Prototypes
*/

int		handle_last(t_pars **pars);
int		is_alpha_numeric(char c);
int		is_an_op(char c);
int		parser(char *str, int a, t_pars **pars);
int		init_parser(char *str, t_pars **pars);
int		handle_op(char *str, int i, int *a, t_pars **pars);
int		handle_parent(char *str, int i, int *a, t_pars **pars);
int		handle_quote(char *str, int i, int *a, t_pars **pars);
int		handle_command(char *str, int i, int *a, t_pars **pars);
int		is_an_op(char c);
void		*xmalloc(int size);
int		my_strlen(char *str);
void		init_str(char *str, int size);
int		my_perror(char *msg, int type, int aexit, int prefix);
char		*epur_p(char *str);
int		find_parenth(char *s);
t_pars		*add_to_end(char *com, char *token, t_pars *pars, t_pars *new);
char		*my_strdup(char *str);
t_pars		*make_link(char ***tab, t_pars *pars);
char		*fonction(char *str, char *s);
int		find_dif(char *s1, char *s2);
t_pars		*find_link(char **tab, t_pars *pars);
char		***make_operand_tab(void);
void		make_link_bis(t_pars **pars, t_pars **tmp, char ***tab);
void		affich_tree(t_pars *pars, int tree);
char		*check_semicolon(char *str);
void		declaration(int *close_parent, int *open_parent, int *b, int a);
void		count_open(int *open_parent, char *str, int *b);
void		check_the_tree(t_pars *pars, t_pars **tmp);
int		error_tok(char *str, char ***tab);
void		error_tok_end(t_pars **tmp, t_pars *pars);
void		error_pars(t_pars **pars, char ***tab);
char		**my_str_to_wordtab(char *str, char c);
int		find_r(char *str);
int		check_semi_colon(char *str);
char		**fill_d_tab(char *str);
char		*init_and_malloc(int len);
int		is_dir(char c);
char		*epur_redir_fich(char *src);
int		find_nb_par(char *str);
void		error_redir(t_pars **pars);
void		redir(t_pars **pars);
void		error_null(t_pars **pars);
void		xfree(void *tmp);
void		epur_pars(t_pars **pars);
void		free_wtb(char **str);
void		free_the_tree(t_pars **pars);
void		complet_redir(t_pars **pars, char **tab);

#endif
