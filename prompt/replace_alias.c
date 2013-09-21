/*
** replace_alias.c for replace_alias in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun May 13 18:56:29 2012 antoine knockaert
** Last update Thu May 17 18:00:19 2012 antoine knockaert
*/

#include	"../42sh.h"
#include	"../lib/my.h"
#include	"prompt.h"

void		replace_alias_cmd(t_glob *glob, char **cmd)
{
  t_alia	*tmp;

  tmp = glob->alias;
  if (cmd && cmd[0])
    {
      while (tmp)
	{
	  if (tmp->cmd && my_match(cmd[0], tmp->cmd))
	    {
	      xfree(cmd[0]);
	      cmd[0] = my_strdup(tmp->alias);
	    }
	  tmp = tmp->next;
	}
    }
}

char		*replace_alias(t_glob *glob, char *str)
{
  char		**tabl;
  char		*str_final;
  int		i;
  char		*tmp;
  char		*tmp2;

  str_final = NULL;
  tabl = my_str_to_wordtab(str, ' ');
  replace_alias_cmd(glob, tabl);
  i = 0;
  while (tabl[i])
    {
      tmp2 = concat(tabl[i], " ");
      tmp = str_final;
      str_final = concat(str_final, tmp2);
      xfree(tmp);
      xfree(tmp2);
      i++;
    }
  free_wtb(tabl);
  return (str_final);
}
