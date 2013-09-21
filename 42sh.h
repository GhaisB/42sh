/*
** 42sh.h for 42sh in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr  8 19:30:16 2012 antoine knockaert
** Last update Sun May 20 16:13:24 2012 antoine knockaert
*/

#ifndef		__42SH_H__
#define		__42SH_H__

/*
** Includes
*/

#include	<sys/types.h>
#include	"parser/parser.h"

/*
** Defines
*/

#define		HISTORY_NAME	".42history"
#define		CONFIG_NAME	".42shrc"
#define		COMMENT_CHAR	'#'
typedef void	(*sighandler_t)(int);

/*
** Structures
*/

typedef struct	s_hist
{
  char		*cmd;
  struct s_hist	*next;
  struct s_hist	*prev;
} t_hist;

typedef struct	s_env
{
  char		*name;
  char		*data;
  struct s_env	*next;
  struct s_env	*prev;
} t_env;

typedef struct	s_var
{
  char		*name;
  char		*data;
  struct s_var	*next;
} t_var;

typedef struct	s_alia
{
  char		*cmd;
  char		*alias;
  struct s_alia	*next;
} t_alia;


typedef struct	s_glob
{
  t_env		*env;
  t_hist	*hist;
  t_var		*var;
  t_alia	*alias;
  int		exit;
  int		exit_code;
  char		*builtin[10];
  int		(*builtin_fc[10])(int ac, char **av, struct s_glob *glob);
} t_glob;

/*
** Prototypes
*/

void		unsetenv_all(t_glob *glob);
void		gere_signal_void();
t_glob		*init(int ac, char **av, char **envp);
char		*my_prompt(t_glob *glob);
void		execution(t_pars *pars, t_glob *glob);

/*
** Builtins fc
*/
int		kill(pid_t pid, int sig);
void		reset_term();
int		my_setenv(int ac, char **av, t_glob *glob);
int		my_unsetenv(int ac, char **av, t_glob *glob);
int		my_echo(int ac, char **av, t_glob *glob);
int		my_exit(int ac, char **av, t_glob *glob);
int		my_cd(int ac, char **av, t_glob *glob);
t_pars 		*make_tree(char *str, t_glob *glob);
void		gere_alias_pars(t_pars **pars, t_glob *list);

#endif
