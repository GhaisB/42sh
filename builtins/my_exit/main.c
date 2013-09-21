/*
** main.c for exit in /home/knocka_a/repositories/42sh/builtins/my_exit
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May  5 13:57:46 2012 antoine knockaert
** Last update Fri May 18 16:02:36 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../../others/others.h"
#include	"../../42sh.h"
#include	"../../lib/my.h"

void		end_history(char *configname, t_hist *hist)
{
  int		fd;
  int		flags;
  t_hist	*tmp;
  char		c;

  flags = O_RDWR | O_CREAT | O_APPEND | O_TRUNC;
  c = '\n';
  tmp = hist;
  fd = open_configfile(configname, flags, 0644);
  while (tmp)
    {
      write(fd, tmp->cmd, my_strlen(tmp->cmd));
      write(fd, &c, 1);
      tmp = tmp->next;
    }
  close(fd);
}

int		my_exit(int ac, char **av, t_glob *glob)
{
  reset_term();
  glob->exit = 1;
  end_history(HISTORY_NAME, glob->hist);
  if (ac == 1)
    {
      glob->exit_code = EXIT_SUCCESS;
      return (1);
    }
  else if (ac == 2)
    {
      if (av && av[1])
	glob->exit_code = my_getnbr(av[1]);
      else
	glob->exit_code = EXIT_SUCCESS;
      return (1);
    }
  return (1);
}
