/*
** check_path.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:49:54 2012 florian dell'aiera
** Last update Thu May 17 17:37:13 2012 florian dell'aiera
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		check_path(char **bin, char *str, t_way *pt)
{
  DIR		*dirp;
  struct dirent	*entry;
  int		i;

  i = 0;
  while (bin[i])
    {
      dirp = opendir(bin[i]);
      if (dirp == NULL)
	return (0);
      while ((entry = readdir(dirp)) != NULL)
	{
	  if (my_match(entry->d_name, str) == 1)
	    {
	      pt->way_to_exec = bin[i];
	      return (1);
	    }
	}
      i++;
    }
  return (0);
}
