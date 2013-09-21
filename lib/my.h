/*
** my.h for lib in /home/knocka_a/repositories/42sh-2016-knocka_a/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun May 20 19:30:45 2012 antoine knockaert
** Last update Sun May 20 22:21:59 2012 antoine knockaert
*/

#ifndef		__MY_H__
#define		__MY_H__

#include	"../42sh.h"
#include	<stdio.h>
#include	<termios.h>
#include	<term.h>
#include	<curses.h>

/*
** Prototypes
*/

char		*create_path(char *path, char *filename);
char		*concat(char *str1, char *str2);
char		**copy_wordtab(char **str);
void		enable_tc(char *cap);
char		*epur_str(char *str, int mfree, char c);
void		free_wtb(char **str);
void		init_str(char *str, int size);
char		*my_getenv(char *name, t_env *envp);
t_env		*my_getenv_ptr(char *name, t_env *envp);
int		my_getnbr(char *str);
int		my_lenenv(t_glob *glob);
int		my_match(char *str1, char *str2);
int		my_perror(char *msg, int type, int aexit, int prefix);
int		my_putint(int i);
void		my_putchar(char c);
void		my_putstr(char *str);
char		*my_strdup(char *str);
int		my_strlen(char *str);
char		**my_str_to_wordtab(char *str, char c);
int		my_tablen(char **tabl);
char		**read_all(int fd);
void		xclose(int fd);
void		xfree(void *tmp);
void		*xmalloc(int size);
int		xread(int fd, char *buffer, int size);
int		xwrite(int fd, char *buffer, int size);

#endif
