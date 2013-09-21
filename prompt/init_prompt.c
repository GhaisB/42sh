/*
** init_prompt.c for init_prompt in /home/knocka_a/repositories/42sh/prompt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr 22 15:10:17 2012 antoine knockaert
** Last update Sun May 20 15:17:25 2012 florian dell'aiera
*/

#include	<stdlib.h>
#include	<pwd.h>
#include	<fcntl.h>
#include	"../42sh.h"
#include	"prompt.h"

t_prompt	*init_prompt(t_glob *glob)
{
  t_prompt	*prompt;
  uid_t		uid;
  int		size;
  struct passwd	*passwd;

  prompt = xmalloc(sizeof(t_prompt));
  if (prompt)
    {
      prompt->buffer = NULL;
      prompt->line = NULL;
      prompt->enter = 1;
      prompt->glob = glob;
      uid = getuid();
      if ((passwd = getpwuid(uid)) != NULL)
	{
	  size = my_strlen(passwd->pw_name) + 10;
	  prompt->prompt = xmalloc(size * sizeof(char));
	  sprintf(prompt->prompt, "<%s>$> ", passwd->pw_name);
	}
      prompt->current = glob->hist;
      prompt->cursor = 0;
    }
  return (prompt);
}
