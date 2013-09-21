/*
** basic_prompt.c for basic_prompt in /home/knocka_a/repositories/42sh/prompt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  2 16:57:51 2012 antoine knockaert
** Last update Thu May 17 11:16:35 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"../42sh.h"
#include	"prompt.h"
#include	"../lib/my.h"

void            gere_signal()
{
  kill(-10, SIGINT);
  my_putstr("\n");
}

char		*basic_prompt(t_glob *glob, t_prompt *prompt)
{
  char		*buffer;
  int		ret;

  buffer = xmalloc(1024 * sizeof(char));
  init_str(buffer, 1020);
  my_putstr(prompt->prompt);
  while (42)
    {
      put_signal(&(gere_signal));
      ret = read(0, buffer, 950);
      if (ret != -1 && buffer != NULL && my_strlen(buffer) > 1)
        {
          buffer[ret - 1] = 0;
          return (buffer);
        }
      else if (my_strlen(buffer) == 0 && ret != -1)
        {
	  glob->exit = 1;
	  return (NULL);
	}
      else
        my_putstr(prompt->prompt);
      init_str(buffer, 1020);
    }
}
