/*
** shell.c for 42 in /home/dell-a_f/42sh/others
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun May 20 15:06:30 2012 florian dell'aiera
** Last update Sun May 20 15:06:31 2012 florian dell'aiera
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"others.h"

void		shell(t_glob *glob)
{
  char		*str;
  t_pars	*pars;

  while (glob->exit == 0)
    {
      str = NULL;
      str = my_prompt(glob);
      pars = NULL;
      if (str && my_strlen(str) > 0)
	{
	  pars = make_tree(str, glob);
	  if (pars)
	    {
	      execution(pars, glob);
	      free_the_tree(&pars);
	    }
	  else
	    printf("42sh: Invalid command.\n");
	}
    }
  free_all(glob);
}
