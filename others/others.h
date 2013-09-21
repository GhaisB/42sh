/*
** others.h for 42sh in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr  8 19:34:22 2012 antoine knockaert
** Last update Fri May 18 16:25:53 2012 antoine knockaert
*/

#ifndef		__OTHERS_H__
#define		__OTHERS_H__

/*
** Includes
*/

#include	"../42sh.h"

/*
** Prototypes
*/

void		free_all(t_glob *glob);
void		free_alias(t_glob *glob);
void		free_var(t_glob *glob);
void		free_hist(t_glob *glob);
void		add_alias(t_glob *glob, char *str);
int		add_alias_list(t_glob *glob, char *cmd, char *alias);
int		add_env_end(t_glob *glob, char *name, char *value);
int		add_hist_end(t_glob *glob, char *str);
int		add_var_end(t_glob *glob, char *name, char *value);
void		add_var_list(t_glob *glob, char *str, int line);
int		init_builtins(t_glob *glob);
void		init_glob(t_glob *glob);
t_glob		*init(int ac, char **av, char **envp);
int		open_configfile(char *configname, int flags, int rights);
void		gere_config_line(t_glob *glob, char *str, int line);
void		init_config(t_glob *glob);
int		init_env(t_glob *glob, char **envp);
int		init_history(t_glob *glob);
int		main(int ac, char **av, char **envp);
void		shell(t_glob *glob);

#endif
