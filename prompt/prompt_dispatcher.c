/*
** prompt_dispatcher.c for promot in /home/knocka_a/repositories/42sh/prompt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  2 16:50:22 2012 antoine knockaert
** Last update Fri May 18 16:43:14 2012 antoine knockaert
*/

#include		<stdio.h>
#include		"../lib/my.h"
#include		"../42sh.h"
#include		"prompt.h"

int			init_termcaps(t_glob *glob)
{
  struct termios	t;
  char			*term;
  int			ret;

  if (tcgetattr(0, &t) == -1)
    return (my_perror("Error on tcgetattr.\n", 2, 0, 1));
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &t) == -1)
    return (my_perror("Error on tcsetattr.\n", 2, 0, 1));
  if ((term =  my_getenv("TERM", glob->env)) == NULL)
    return (my_perror("$TERM not available.\n", 2, 0, 1));
  if ((ret = tgetent(NULL, term)) && ret != -1 )
    return (1);
  return (0);
}

char			*prompt_dispatcher(t_glob *glob, t_prompt *prompt)
{
  char			*str;

  if (isatty(0) && init_termcaps(glob))
    {
      str = termcap_prompt(glob, prompt);
      str = epur_str(str, 1, 0);
      reset_term();
      return (str);
    }
  else
    {
      reset_term();
      str = basic_prompt(glob, prompt);
      str = epur_str(str, 1, 0);
      return (str);
    }
}
