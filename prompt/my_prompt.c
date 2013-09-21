/*
** my_prompt.c for my_prompt in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 13 15:38:47 2012 antoine knockaert
** Last update Fri May 18 16:13:17 2012 antoine knockaert
*/

#include	"../42sh.h"
#include	"../lib/my.h"
#include	"prompt.h"

void		free_prompt(t_prompt *prompt)
{
  xfree(prompt->prompt);
  xfree(prompt);
}

char		*my_prompt(t_glob *glob)
{
  t_prompt	*prompt;
  char		*str;

  str = NULL;
  prompt = init_prompt(glob);
  if (prompt)
    str = prompt_dispatcher(glob, prompt);
  if (str && my_strlen(str) > 0)
    add_hist_beg(glob, str);
  else
    {
      xfree(str);
      return (NULL);
    }
  free_prompt(prompt);
  return (str);
}
