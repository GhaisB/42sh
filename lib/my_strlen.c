/*
** my_strlen.c for strlen in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 14:30:49 2012 antoine knockaert
** Last update Tue May 15 17:11:34 2012 antoine knockaert
*/

#include	"my.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
