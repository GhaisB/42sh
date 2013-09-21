/*
** execution.h for 42sh in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr  8 19:32:51 2012 antoine knockaert
** Last update Thu May 17 17:37:45 2012 florian dell'aiera
*/

#ifndef			__EXECUTION_H__
#define			__EXECUTION_H__

/*
** Includes
*/
#include		<stdio.h>
#include		"../parser/parser.h"
#include		"../42sh.h"
/*
** Defines
*/

/*
** Structures
*/
typedef	struct	s_way
{
  char *way_to_exec;
  char	**c_env;
  int	built;
  int	i;
  int	c_i;
  int	c_j;
  char	*c_type;
  char	*c_file;
}		t_way;
/*
** Prototypes
*/
int		check_path(char **bin, char *str, t_way *pt);
void		delete_egal(char **tabl);
void		end_of_way(t_way *pt, char *str);
int		error(int i);
int		execute_member(t_pars *pars, char *token, t_glob *glob, int side);
int		search(char **tabl, t_glob *glob, char *type, char *filename);
void		type_of_redir(char **tabl, t_way *pt, t_glob *glob);
int		exec_gnral(char **tabl, t_glob *glob, char *type, char *filename);
int		check_builtins(t_glob *glob, char **tabl, t_way *pt);
int		check_dup(int fd);
int		check_dup2(int oldfd, int fd);
int		check_access(char *pathname);
int		check_error(int error);
int		check_pipe(int *pipefd);
int		redir_right(t_way *pt);
int		redir_left(t_way *pt);
int		d_redir_right(t_way *pt);
int		d_redir_left(t_way *pt);
int		open_file(char *str, int flags);
int		d_redir_right(t_way *pt);
char		**copy_env(t_glob *glob, char **c_env, t_way *pt);
int		execution_bin(char **tabl, t_way *pt);
int		func_to_fork(char **tabl, t_way *pt, t_glob *glob);
int		check_bin(char **tabl, t_way *pt, t_glob *glob, int *status);
void		gere_status(int status);
void		copy_value(t_way *pt, char *type, char *filename);
int		search_pipe(char **tabl, t_glob *glob, t_pars *pars);
void		do_fork_pipe(t_pars *pars, t_glob *glob);
int		pipe_only(t_pars *pars, t_glob *glob);

#endif
