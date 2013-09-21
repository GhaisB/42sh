/*
** main.c for others in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr  8 19:28:57 2012 antoine knockaert
** Last update Thu May  3 23:43:53 2012 antoine knockaert
*/

#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"
#include	"../parser/parser.h"

int		main(int ac, char **av, char **envp)
{
  t_glob	*glob;

  glob = init(ac, av, envp);
  if (glob)
    shell(glob);
  if (glob)
    return (glob->exit_code);
  else
    return (EXIT_FAILURE);
}
