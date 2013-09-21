/*
** autocomplete.c for 42 in /home/dell-a_f/42sh
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun May 20 15:46:57 2012 florian dell'aiera
** Last update Sun May 20 15:49:24 2012 antoine knockaert
*/

#include        <sys/types.h>
#include        <signal.h>
#include	<glob.h>
#include        "../lib/my.h"
#include        "../42sh.h"
#include        "prompt.h"

void		autocomplete(t_prompt *prompt)
{
  glob_t	globp;
  size_t	i;
  int		ret;
  char		*str;
  int		opt;

  if (prompt->line[my_strlen(prompt->line) - 1] == '/')
    str = concat(prompt->line, "*");
  printf("\nPrompt line : %s\n\n", str);
  globp.gl_offs = 0;
  ret =  glob(str, GLOB_TILDE | GLOB_BRACE | GLOB_MARK | GLOB_APPEND , NULL, &globp);
  globp.gl_offs = 0;
  opt = GLOB_TILDE | GLOB_BRACE | GLOB_MARK | GLOB_APPEND;
  ret =  glob(str, opt, NULL, &globp);
  if (ret != 0)
    {
      return ;
    }
  i = 0;
  while (i < globp.gl_pathc)
    {
      i++;
    }
}
