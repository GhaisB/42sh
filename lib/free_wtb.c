/*
** free_wtb.c for free in /home/knocka_a/lem-in/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed Mar 28 14:32:50 2012 antoine knockaert
** Last update Wed Mar 28 14:34:09 2012 antoine knockaert
*/

#include	"my.h"

void		free_wtb(char **str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      xfree(str[i]);
      i++;
    }
  xfree(str);
}
