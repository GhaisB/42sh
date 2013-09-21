/*
** main.c for echo in /home/knocka_a/repositories/42sh/builtins/my_echo
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May  5 14:14:57 2012 antoine knockaert
** Last update Fri May 18 15:29:56 2012 florian dell'aiera
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"../../others/others.h"
#include	"../../42sh.h"
#include	"../../lib/my.h"

void		catch_av(int ac, char **av, int *opte, int *optn)
{
  int		i;
  int		j;

  i = 1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  j = 1;
	  while (av[i][j])
	    {
	      if (av[i][j] == 'n')
		*optn = 1;
	      if (av[i][j] == 'E')
		*opte = 1;
	      j++;
	    }
	}
      i++;
    }
}

void		option_e(char *str, int optn)
{
  int		i;
  int		j;
  char		*copy;

  i = 0;
  j = 0;
  copy = xmalloc(sizeof(char) * my_strlen(str));
  while (str[i])
    {
      if (str[i] && str[i] == '\\')
	{
	  copy[j++] = str[++i];
	  i++;
	}
      if (str[i])
	copy[j++] = str[i++];
    }
  copy[j] = '\0';
  my_putstr(copy);
  if (optn != 1)
    my_putchar('\n');
}

int		my_echo(int ac, char **av, t_glob *glob)
{
  int		opte;
  int		optn;
  int		i;

  i = 0;
  opte = 0;
  optn = 0;
  glob = glob;
  catch_av(ac, av, &opte, &optn);
  while (av[i])
    i++;
  i--;
  if (optn == 1 && opte == 0)
    my_putstr(av[i]);
  else if (opte == 1)
    option_e(av[i], optn);
  else
    {
      my_putstr(av[i]);
      my_putchar('\n');
    }
  return (1);
}
