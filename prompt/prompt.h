/*
** prompt.h for 42sh in /home/knocka_a/repositories/42sh/prompt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr  8 19:34:50 2012 antoine knockaert
** Last update Thu May 17 17:50:30 2012 antoine knockaert
*/

#ifndef		__PROMPT_H__
#define		__PROMPT_H__

#include	<stdio.h>
#include	<termios.h>
#include	<term.h>
#include	<curses.h>

typedef struct	s_prompt
{
  char		*buffer;
  char		*line;
  char		*prompt;
  int		cursor;
  int		enter;
  t_hist	*current;
  t_glob	*glob;
} t_prompt;

int		add_hist_beg(t_glob *glob, char *cmd);
void		autocomplete(t_prompt *prompt);
void		gere_signal();
char		*basic_prompt(t_glob *glob, t_prompt *prompt);
void		hist_up(t_prompt *prompt);
void		hist_down(t_prompt *prompt);
t_prompt	*init_prompt(t_glob *glob);
void		move_right(t_prompt *prompt);
void		move_left(t_prompt *prompt);
void		delete_char(t_prompt *prompt, int offset);
char		*add_char_into(t_prompt *prompt, char *buffer, char *tmp);
void		add_char(t_prompt *prompt, char *buffer);
void		free_prompt(t_prompt *prompt);
char		*my_prompt(t_glob *glob);
int		init_termcaps(t_glob *glob);
char		*prompt_dispatcher(t_glob *glob, t_prompt *prompt);
sighandler_t	put_signal(sighandler_t handler);
void		replace_alias_cmd(t_glob *glob, char **cmd);
char		*replace_alias(t_glob *glob, char *str);
void		reset_term();
void		gere_signal_termcap();
void		gere_key(t_prompt *prompt, char *buffer);
void		aff_prompt_cursor(t_prompt *prompt);
void		aff_prompt(t_prompt *prompt);
char		*termcap_prompt(t_glob *glob, t_prompt *prompt);

#endif
