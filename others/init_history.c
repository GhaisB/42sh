/*
** init_history.c for init_history in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 19:08:08 2012 antoine knockaert
** Last update Thu May 17 17:39:20 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

int		init_history(t_glob *glob)
{
  int		fd;
  char		**tabl;
  int		i;

  i = 0;
  glob->hist = NULL;
  fd = open_configfile(HISTORY_NAME, O_RDONLY, 0);
  if (fd != -1)
    {
      tabl = read_all(fd);
      while (tabl && tabl[i])
	{
	  if (add_hist_end(glob, tabl[i++]))
	    return (0);
	}
      free_wtb(tabl);
    }
  xclose(fd);
  return (1);
}
