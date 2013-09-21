/*
** my_perror.c for 42sh in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 14:04:09 2012 antoine knockaert
** Last update Wed May  2 16:24:49 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"my.h"

int		my_perror(char *msg, int type, int aexit, int prefix)
{
  if (prefix)
    xwrite(2, "42sh:", 6);
  if (type == 1)
    xwrite(2, " Warning: ", 11);
  else if (type == 2)
    xwrite(2, " Error: ", 9);
  else if (type == 3)
    xwrite(2, " Fatal-Error: ", 15);
  if (msg)
    xwrite(2, msg, my_strlen(msg));
  return (aexit);
}
